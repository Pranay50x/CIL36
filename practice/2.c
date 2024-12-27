/*
 * =====================================================================================
 *
 *       Filename:  2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26/12/2024 16:03:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct employee{
    char name[20];
    int id; 
    float salary;
    char dept[50];

}; 

void readEmployees(struct employee *emp, int n){
    
    for(int i =0;i<n;i++){
        printf("Enter details for employees %d\n", i+1);
        printf("Enter name of employee: ");
        scanf(" %[^\n]", emp[i].name);
        
        printf("Enter id of the employee: "); 
        scanf("%d",&emp[i].id); 

        printf("Enter the salary: "); 
        scanf("%f", &emp[i].salary);

        printf("Enter the department: "); 
        scanf(" %[^\n]", emp[i].dept); 
    }
}


void display(struct employee *emp, int n) {

    printf("\nDetails for Employees: "); 

    for(int i =0;i<n;i++){
        printf("\nEmployee: %d",i+1);
        printf("\nName: %s", emp[i].name);
        printf("\nId: %d",emp[i].id); 
        printf("\nDepartment: %s", emp[i].dept); 
        printf("\nSalary: %.2f",emp[i].salary); 
    }
}

void totalSalary(struct employee *emp, int n, const char* dept){
    float total = 0;

    for(int i =0;i<n;i++){
        if(strcmp(emp[i].dept,dept)==0)
                total += emp[i].salary; 
    }

    printf("\nTotal Salary of %s is: %.2f\n",dept,total); 
}

int main(){
    
    
    char dept[40];
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n); 

    struct employee *emp = (struct employee*)malloc(n*sizeof(struct employee));
    readEmployees(emp,n);

    display(emp,n); 

    printf("\nEnter the department: ");  
    scanf(" %[^\n]",dept);

    totalSalary(emp,n,dept); 

    return 0;    
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct EMPLOYEE{
	char name[50];
	int id; 
	char dept_name[30]; 
	float salary; 
};

void readEmployees(struct EMPLOYEE *emp, int n){
	for(int i =0;i<n;i++){
		printf("Enter details for employee: \n");
		printf("Enter employee name: "); 
		scanf(" %[^\n]", emp[i].name); 
		printf("Employee ID: "); 
		scanf("%d",&emp[i].id); 
		printf("Department Name: "); 
		scanf(" %[^\n]", emp[i].dept_name); 
		printf("Salary: "); 
		scanf("%f", &emp[i].salary); 
	}
}


void displayEmployee(struct EMPLOYEE *emp, int n){
	printf("\nEmployee Details: \n");
	for(int i =0; i<n;i++){
		printf("\nEmployee %d\n",i+1); 
		printf("Name: %s\n", emp[i].name);
		printf("ID: %d\n", emp[i].id); 
		printf("Department %s\n", emp[i].dept_name); 
		printf("Salary: %.2f\n", emp[i].salary); 
	}
}


float totalSalaryByDept(struct EMPLOYEE *emp, int n,const  char* dept){
       float total_salary = 0;
       for(int i=0;i<n;i++){
	      if(strcmp(emp[i].dept_name, dept) == 0){
		     total_salary += emp[i].salary; 
	      }
       }

      return total_salary; 
} 
       

int main(){
	int n; 
	char dept[30]; 
	printf("Enter no. of employees: ");
	scanf("%d", &n); 

	struct EMPLOYEE *employees = (struct EMPLOYEE*) malloc (n*sizeof(struct EMPLOYEE)); 

	readEmployees(employees,n); 
	displayEmployee(employees,n); 

	printf("\nEnter the department to calculate total salary: ");
       	scanf(" %[^\n]", dept); 
	float totalSalary = totalSalaryByDept(employees, n, dept);
	printf("Total Salary for department %s: %.2f\n", dept, totalSalary); 
	free(employees);
	return 0; 
}	

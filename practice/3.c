/*
 * =====================================================================================
 *
 *       Filename:  3.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26/12/2024 18:27:31
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
#define MAX 5
int stack[MAX]; 
int top = -1;

void push(int x){

    if(top==MAX){
        printf("Stack Overflow\n"); 
        exit(0); 
    }

    stack[++top] = x; 
}

int pop(){
    if(top==-1){
        printf("Stack Underlfow\n");
        return 1; 
    }
    return stack[top--]; 
}


void display(){
    if(top==-1){
        printf("\nStack Underflow"); 
        exit(0);
    }
    
    printf("\nElements of stack are: \n"); 
    for(int i = top; i!=-1;i--){
        printf("%d ", stack[i]); 
    }
}

void check_p(){
    char str[20]; 

    printf("Enter a string: "); 
    scanf("%s",str); 

    int flag=0; 
    
    int len = strlen(str); 
    for(int i =0;i<len;i++)
        push(str[i]);

    for(int j = 0; j<len;j++){
            
        if(str[j]!=pop()){
            flag = 1;
            break;
        }
    }

    if(flag==1){
        printf("%s is not a palindrome!",str);
    }
    else {
        printf("%s is a palindrome!", str);
    }
}

int main(){
    int choice,x; 

    while(1){
        printf("\n1. Push"); 
        printf("\n2. Pop"); 
        printf("\n3. Display"); 
        printf("\n4, Quit"); 
        printf("\n5. Check Palindrome"); 
        printf("\nEnter your choice: "); 
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                 printf("Enter element to be pushed: "); 
                 scanf("%d", &x);
                 push(x); 
                 break; 
            case 2: 
                 x = pop(); 
                 printf("Element popped is : %d", x); 
                 break; 
            case 3:
                 display(); 
                 break; 
            case 4: 
                 exit(0); 
            case 5: 
                 check_p();
                 //check_p_2(); 
                 break; 
            default: 
                 printf("Enter valid choice!"); 
        }
    }
}

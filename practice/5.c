/*
 * =====================================================================================
 *
 *       Filename:  5.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26/12/2024 20:57:40
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
#define MAX 10
#include <ctype.h>

int stack[MAX];
int top =-1; 

void push(int x){
    if(top==MAX-1){
        printf("Stack Overflow\n");
        return;
    }

    stack[++top]=x; 
}

int pop(){
    if(top==-1){
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int main(){

    int n1,n2,n3,num;
    char exp[40];
    char *e;

    printf("Enter the expression: ");
    scanf("%s", exp); 
    
    e = exp; 
    while(*e != '\0'){
        if(isdigit(*e)){
            num = *e -48;
            push(num); 
        }

        else{
            n1 = pop();
            n2 = pop(); 

            switch(*e){
                case '+':
                    n3 = n2+n1;
                    break;
                case '-':
                    n3 = n2-n1; 
                    break;
                case '*':
                    n3 = n2*n1;
                    break;
                case '/':
                    n3 = n2/n1;
                    break;
            }

            push(n3); 
        }
        e++;
    }

    printf("\nThe value of expression %s is: %d\n", exp,pop());
    return 0; 
}



/*
 * =====================================================================================
 *
 *       Filename:  4.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26/12/2024 19:20:39
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
#include <ctype.h>
#define MAX 20


char stack[MAX];
int top =-1; 

void push(int x){
    if(top==MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x; 
}

char pop(){
    if(top==-1){
        printf("Stack Underflwo\n"); 
        return '\0'; 
    }

    return stack[top--]; 
}

int priority(char x){

    if(x=='(')
        return 0;
    else if(x=='+' || x=='-')
        return 1; 
    else if(x=='*' || x=='/')
        return 2; 
    else if(x=='$' || x=='^')
        return 3;
    else
        return -1; 
}

int main(){
    char exp[40],*e,x; 

    printf("Enter the expression: ");
    scanf("%s", exp); 
    
    //int len = strlen(exp); 
    for(e=exp; *e!='\0';e++){
      
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e == '(')
            push(*e);
        else if(*e==')'){
            while((x=pop())!= '(')
                printf("%c", x);
        }
        else {
            while(priority(stack[top]) >= priority(*e))
                printf("%c", pop());

            push(*e); 
        }
    }

    while(top!=-1)
        printf("%c",pop());

    printf("\n"); 
    return 0;


}


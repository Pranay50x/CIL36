/*
 * =====================================================================================
 *
 *       Filename:  stack.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/08/2024 14:23:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 5 

int top  = -1; 
int stack[MAX]; 

int pop(); 
void display();
void check_p(); 
void check_p_2(); 
void push(int x); 

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
                 check_p_2(); 
                 break; 
            default: 
                 printf("Enter valid choice!"); 
        }
    }
}


void push(int x){
    if(top==MAX)
        printf("Stack Overflow"); 
    else{
        top = top +1; 
        stack[top] = x; 
    }
}

int pop(){
    int x;
    if(top==-1)
        printf("Stack underflow"); 
    else{ 
        x = stack[top]; 
        top = top -1; 
        return x; 
    }
}

void display(){
    if(top==-1)
        printf("Stack is empty"); 
    else{
        printf("Stack elements are: "); 
        for(int i =top; i>=0; i--){
            printf("%d ", stack[i]); 
        }
    }
}

void check_p(){
    int flag =0; 
    char str[20]; 
    printf("Enter the string: "); 
    scanf("%s", str); 
    for(int i = 0; str[i]!='\0'; i++)
        push(str[i]); 
    for(int j =0 ; str[j]!='\0'; j++){

        if(str[j]!=pop()){
            flag = 1;
            break;
        }
    }

    if(flag==1)
        printf("String str is not a palindrome"); 
    else
        printf("String str is a palindrome");
}

void check_p_2(){
    int floor =0, ceil =top, flag =0; 
    while(floor<=ceil){
        if(stack[floor]!=stack[ceil]){
            flag =1; 
            break; 
        }
        floor++ ; 
        ceil-- ; 
    }

    if(flag == 1)
        printf("\nStack is not a palindrome\n"); 
    else
        printf("\nStack is a palindrome\n"); 
}

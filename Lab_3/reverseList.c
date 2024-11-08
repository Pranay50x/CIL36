/*
 * =====================================================================================
 *
 *       Filename:  reverseList.c
 *
 *    Descriptiiiii 
 *
 *        Version:  1.0
 *        Created:  11/08/2024 17:12:15
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

int stack[30];
int top =-1;
int pop(); 
void push(int x); 

int main(){

    int x,n,arr[10]; 
    printf("\nEnter no. of elements in the array: ");
    scanf("%d", &n);
    
    printf("\nEnter element of array: "); 
    for(int i = 0; i<n;i++){
            scanf("%d", &arr[i]); 
    }

    for(int i =0; i<n; i++){
        push(arr[i]); 
    }

    for(int i = 0; i<n; i++){
        x = pop();
        arr[i] = x;
    }

    printf("\nReversed array: "); 
    for(int i =0 ; i<n; i++)
        printf("\n%d", arr[i]); 
    printf("\n");
    return 0; 
}

void push(int x){
     stack[++top] = x; 
}

int pop(){
    return (stack[top--]); 
}


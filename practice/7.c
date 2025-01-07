/*
 * =====================================================================================
 *
 *       Filename:  7.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/01/2025 22:04:05
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
#define MAX 4

int queue[MAX]; 
int front = -1, rear= -1;

void insert(int val){
    if(rear==MAX-1){
        printf("Queue is full\n"); 
        return;
    }
    if(front==-1)
        front = 0;
    queue[++rear] = val; 
    printf("\nCallerId added: %d",val); 
}

void delete(){
    if(front ==-1){
        printf("\nQueue underflow\n"); 
        return ; 
    }

    printf("\nCallerId delted : %d",queue[front++]); 
    if(front>rear)
        front = rear -1;
}

void display(){
    if(front==-1){
        printf("\nQueue Undeflow"); 
        return; 
    }

    printf("\nCalls in Queue: "); 
    for(int i = front;i<=rear; i++){
        printf("%d ", queue[i]); 
    }
}

int main(){
    int ch, callid; 
    while(1){
        printf("\n1. Insert CallId");
        printf("\n2. Delete CallId"); 
        printf("\n3. Display Call Queue"); 
        printf("\n4. Exit"); 
        printf("\nEnter your choice: ");
        scanf("%d",&ch); 
        
        switch(ch){
            case 1: 
                printf("\nEnter the CallID to insert: ");
                scanf("%d",&callid); 
                insert(callid);
                break;
            case 2:
                delete(); 
                break;
            case 3:
                display();
                break; 
            case 4:
                exit(0);
                break;
            default:
                printf("Enter valid choice"); 
        }
    }
}


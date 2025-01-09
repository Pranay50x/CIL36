/*
 * =====================================================================================
 *
 *       Filename:  8.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/01/2025 15:41:47
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

int cqueue[MAX];
int front = -1 ,rear=-1; 

void insert(int val){
    
    if((front == 0 && rear == MAX-1) || ((rear+1)%MAX == front)){
           printf("Circular queue is full\n"); 
           return; 
    }

    if(front==-1)
        front = rear =0; 

    else if(rear == MAX -1)
        rear =0; 
    else
        rear++;
    cqueue[rear] = val;
    printf("\nValue added is:%d\n",val); 
}


int delete() {
    if(front == -1){
        printf("Circular Queue Underflow\n");
        return -1; 
    }

    int val = cqueue[front]; 
    if(front==rear)
        front = rear -1;
    else if(front == MAX-1)
        front = 0; 
    else 
        front++;

    return val;
}

void display(){
    if(front==-1){
        printf("Circular queue is empty\n"); 
        return ;
    }

    printf("\nFront -> %d\nItems in Circular Queue: ", front); 
    for(int i = front; i!=rear; i= (i+1)%MAX)
        printf("%d ",cqueue[i]); 

    printf("%d ", cqueue[rear]); 
    printf("\nRear -> %d", rear);    
}

int main(){

    int ch, val,res;
    while(1){
        printf("\n1. Insert Element");
        printf("\n2. Delete Element"); 
        printf("\n3. Display Items");
        printf("\n4. Exit"); 
        printf("\nEnter your choice: "); 
        scanf("%d",&ch);

        switch(ch){
            case 1: 
                printf("\nEnter the element: "); 
                scanf("%d",&val); 
                insert(val);
                break;
            case 2: 
                //int res;
                res = delete();
                if(res!=-1)
                    printf("\nElement removed is -> %d\n",res);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default: 
                printf("Enter valid choice\n");
        }
    }
    return 0;
}

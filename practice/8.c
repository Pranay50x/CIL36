/*
 * =====================================================================================
 *
 *       Filename:  8.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  30/01/2025 13:49:37
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

struct Cqueue{
    int data;
};

struct Cqueue cqueue[MAX];
int front = -1, rear=-1;

void insert(int x){
   if((rear==MAX-1 && front ==0) || ((rear+1)%MAX==front)){
       printf("Queue Overflow\n");
       return ;
   }

   if(front==-1)
       front = rear = 0;
   else if(rear==MAX-1)
       rear =0;
   else
       rear++;

   cqueue[rear].data =x;
   printf("%d inserted in Circu;ar queue\n",x);
}


int delete(){
    if(front==-1){
        printf("Queue Underflow\n");
        return -1;
    }

    int x = cqueue[front].data;
    if(front==rear)
        front = rear = -1;
    else if(front==MAX-1)
        front=0;
    else
        front++;
    return x;
}

void display(){
    if(front==-1){
        printf("Circular queue underflow\n");
        return ;
    }

    printf("\nFront: %d\nItems in Queue: ",front);
    for(int i = front; i!=rear;i=(i+1)%MAX)
        printf("%d ",cqueue[i].data);

    printf("%d", cqueue[rear].data);
    printf("\nRear: %d",rear);

}


int main(){
    int ch,x,res;

    while(1){
        printf("\n1. Insert ");
        printf("\n2. Delete ");
        printf("\n3. Display ");
        printf("\n4. Exit ");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &x);
                insert(x);
                break;
            case 2:
                res = delete();
                if(res!=-1)
                    printf("%d removed from the queue\n",res);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("ENter the valid choice");
        }
    }
}

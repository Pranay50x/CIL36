/*
 * =====================================================================================
 *
 *       Filename:  10.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/01/2025 18:54:29
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

typedef struct node{
    int data;
    struct node *next;
}Node;

Node *top=NULL; 

void push(int x){
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data =x;
    newNode->next = top;
    top = newNode; 

    printf("%d pushed into stack\n",x);
}

int pop(){
    if(!top){
        printf("\nStack is empty\n");
        return -1; 
    }

    Node *temp = top; 
    int x = temp->data; 

    top = top->next;
    free(temp); 
    return x; 
}

int peek(){
    if(!top){
        printf("Stack is empty\n");
        return -1;
    }
    return top->data; 
}

void display(){
        if(!top){
            printf("Stack is empty\n");
            return ;
        }

        Node *temp = top; 
        printf("Stack: ");
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
}

int main() {
    int choice, item;

    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to be pushed: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                item = pop();
                if (item != -1) {
                    printf("Popped item is: %d\n", item);
                }
                break;
            case 3:
                item = peek();
                if (item != -1) {
                    printf("Top item is: %d\n", item);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}


/*
 * =====================================================================================
 *
 *       Filename:  11.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/01/2025 19:12:23
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
    struct node *prev;

}Node;

Node *head = NULL;

void insert(int data, int key){

    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    
    if(!head){
        head = newNode;
        return;
    }

    Node *current = head;
    while(current != NULL && current->data !=key)
        current = current->next;

    if(!current){
        printf("Key not found\n");
        free(newNode);
        return;
    }

    newNode->prev = current->prev;
    current->prev = newNode; 
    newNode->next = current;

    if(newNode->prev != NULL)
        newNode->prev->next = newNode;
    else
        head=newNode;
}

void delete(int data){

    Node *temp = head;
    Node *prev, *next = NULL;

    while(temp!=NULL && temp->data != data){
        prev=temp;
        temp=temp->next; 
    }

    if(!temp){
        printf("Data not found\n");
        return;
    }

    next=temp->next;

    if(!prev)
        head=next;
    else
        prev->next=next;

    if(next!=NULL)
        next->prev = prev;

    free(temp);
}

void display(){
    Node *ptr = head;

    if(!head){
        printf("List is empty\n");
        return;
    }

    printf("List: \n");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

int main(){
    int ch;
    int val, key=-1;

    while(1){
        printf("\n1. Insert Element");
        printf("\n2. Delete Element");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        
        switch(ch){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d",&val);
                if(head!=NULL){
                    printf("Enter value of key: ");
                    scanf("%d",&key);
                }
                insert(val,key);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d",&val);
                delete(val);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Enter VALUD CHOICE"); 
        }

    }
}



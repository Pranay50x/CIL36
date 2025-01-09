/*
 * =====================================================================================
 *
 *       Filename:  9.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/01/2025 17:47:57
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

typedef struct node {
    char name[50];
    struct node *next; 
}Node;

Node *head = NULL;

void insert(char *name){
    Node *newNode = (Node *)malloc(sizeof(Node));
    
    strcpy(newNode->name, name);
    newNode->next = NULL;
    
    if(!head || strcmp(head->name, name)>=0){
        newNode->next = head;
        head=newNode;
    }
    else{
        Node *current = head; 
        while(current->next && strcmp(current->next->name, name)<0){
            current = current->next; 
        }

        newNode->next = current->next; 
        current->next = newNode;
    }
    printf("%s inserted into the List\n",name); 
}

void delete(char *name){
    Node *temp = head, *prev = NULL;

    if(strcmp(temp->name, name) == 0){
        head = head->next; 
        free(temp);
        return; 
    }

    while(temp && strcmp(temp->name,name)!=0){
        prev = temp;
        temp = temp->next;
    }

    if(!temp){
        printf("%s not fouind in the list\n",name);
        return; 
    }

    prev->next = temp->next; 
    free(temp);
    printf("%s removed from List\n",name); 
}

void display(){

    if(!head){
        printf("Empty list\n");
        return;
    }

    printf("\nNames in the list: "); 
    Node *current = head; 
    while(current){
        printf("%s ", current->name);
        current = current->next;
    }
    printf("\n");
}

int main(){

    int choice; 
    char name[50];

    while (1) {
        printf("\n1. Insert a name");
        printf("\n2. Delete a name");
        printf("\n3. Display the list");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name to be inserted: ");
                scanf("%s", name);
                insert(name);
                break;

            case 2:
                printf("Enter the name to be deleted: ");
                scanf("%s", name);
                delete(name);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }       

}




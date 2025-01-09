/*
 * =====================================================================================
 *
 *       Filename:  12.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/01/2025 21:46:36
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
    struct node *left;
    struct node *right;
    
}Node;


Node *root = NULL; 

Node *newNode(int data){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}


Node *insert(Node *node, int data){
    if(!node)
        return newNode(data);

    if(data< node->data)
        node->left =insert(node->left, data);
    else
        node->right=insert(node->right,data);

    return node;
}

void inorder(Node *root){
    if(root){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(Node *root){
    if(root){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void display(){
    if(!root){
        printf("Tree is empty\n");
        return;
    }

    printf("\nInorder traversal\n");
    inorder(root);
    printf("\nPreorder Traversal\n");
    preorder(root);
    printf("\nPostorder traversal\n");
    postorder(root);
    printf("\n");
}

int main(){
    
    int ch,val;

    while(1){
        printf("\n1.Insert Value: ");
        printf("\n2. Display All Traversal");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter value to be inserted: ");
                scanf("%d",&val);
                root = insert(root,val);
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("pls enter valid choice");
        }
    }
}


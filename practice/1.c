/*
 * =====================================================================================
 *
 *       Filename:  1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26/12/2024 14:47:56
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

void createArray(int arr[], int n){
    printf("Enter the elements of array: "); 
    for(int i =0; i<n;i++){
        scanf("%d",&arr[i]);
    }
}

void display(int arr[], int n){
    printf( "Array elements are: ");
    for(int i =0;i<n;i++){
        printf("%d ",arr[i]);  
    }
}

void insertElement(int arr[],int *n, int ele, int pos){
        for(int i =*n;i>=pos;i--){
            arr[i] = arr[i-1]; 
        }
        arr[pos-1] = ele;
        (*n) ++; 
}

void deleteElement(int arr[], int *n, int pos){
    
    for(int i =pos;i<*n;i++){
        arr[i-1] = arr[i]; 
    }
    
    
    (*n)--; 
}

int main(){
    int arr[100],n,ele,pos; 

    while(1){
                int ch; 
       
        
        printf("\n1. Create an Array");
        printf("\n2. Display array"); 
        printf("\n3. Insert an element"); 
        printf("\n4. Delete an element"); 
        printf("\n5. Exit");
        printf("\nEnter your choice: \n");

        scanf("%d",&ch); 
        switch(ch){
            case 1: 
                printf("Enter the size of array: ");
                scanf("%d",&n);
                createArray(arr,n); 
                break;
            case 2: 
                display(arr,n);
                break; 
            case 3: 
                printf("Enter the element to be insrted: ");
                scanf("%d",&ele); 
                printf("\nEnter the position: "); 
                scanf("%d", &pos); 

                insertElement(arr,&n,ele,pos); 
                break; 
            case 4: 
                printf("Enter the position to be deleted: "); 
                scanf("%d", &pos); 

                deleteElement(arr,&n,pos);
                break; 
            case 5:
                exit(0);
                break; 
            default: 
                printf("\nEnter valid choice"); 

        }
        
    }
}


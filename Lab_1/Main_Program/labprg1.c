#include <stdlib.h>
#include <stdio.h>
#define MAX 100
void createArray(int arr[], int n); 
void displayArray(int arr[], int n); 
void insertElement(int arr[], int *n, int ele, int pos); 
void deleteElement(int arr[], int *n, int pos); 

int main(){

	int arr[MAX];
	int n =0; 

	int choice, ele , pos; 
	while(1){
		printf("\nMenu"); 
		printf("\n1. Create an array of N elements"); 
		printf("\n2. Display the array");
		printf("\n3. Insert an element at a given position"); 
		printf("\n4. Delete an element"); 
		printf("\n5. Exit"); 

		printf("\nEnter your choice (1-5): "); 
		scanf("%d", &choice) ;
		switch(choice){
			case 1: 
				printf("Enter no of elements in array: ");
				scanf("%d", &n); 
				if(n> MAX){
					printf("Maximum allowed elements are %d\n", MAX);
				       n=0; 
				}
		 		
				else {
					createArray(arr, n); 
				}
				
				break;
			case 2: 
				displayArray(arr, n); 
			break;

			case 3: 
				printf("Enter the element to insert: "); 
				scanf("%d",&ele); 
				printf("Enter the position to insert element: ");
				scanf("%d", &pos);
				insertElement(arr, &n , ele, pos); 
				break; 
			case 4: 
				printf("Enter the position to delete the elements: "); 
				scanf("%d", &pos); 
				deleteElement(arr,&n,pos); 
				break; 
			case 5: 
				printf("Exit program\n");
			       	
				return 0;
				break;
				 
			default: 
				printf("ENter valid choice "); 
		}
	}

return 0; 

}

void createArray(int arr[], int n){
	int i; 
	printf("Enter %d elements\n",n); 
	for(i =0; i<n ;i++){
		scanf("%d",&arr[i]); 
	}

	printf("Array created successfully \n"); 
}


void displayArray(int arr[], int n){

	int i; 
	if(n==0){
		printf("Array is empty\n");
	}
	
	else {
		printf("Array elements are: "); 
		for(i=0;i<n;i++){
			printf("%d ",arr[i]); 
		}
		printf("\n"); 

	}

}

void insertElement(int arr[], int *n, int ele, int pos){
	int i; 
	
	if(*n == MAX){
		printf("Array is full \n"); 
	}
	else if(pos <1 || pos >*n+1){
		printf("Invalid position\n");
	}
	else{
		for(i = *n; i>=pos;i--){
			arr[i] = arr[i-1]; 
		}
	
	arr[pos -1] = ele; 
	(*n) ++ ; 
	printf("Element inserted successfully \n"); 
	}
}


void deleteElement(int arr[], int *n, int pos){

	int i; 
	if(*n == 0){
		printf("Array is empty\n"); 
	}
	else if (pos<1 || pos>*n){
		printf("Invalid position\n"); 
	}

	else{
		for(i = pos-1;i< *n-1; i++){
			arr[i] = arr[i+1]; 
		}

		(*n) -- ; 
		printf("ELement deleted successfully\n");
	}
}
		

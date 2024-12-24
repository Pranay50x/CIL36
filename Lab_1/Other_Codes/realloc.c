#include <stdlib.h>
#include <stdio.h>
int main(){

	int *ptr; 
	int n= 5, new_n = 10; 
	ptr = (int *)malloc(n* sizeof(int)); 

	if(ptr ==  NULL){
		printf("Memory allocation failed"); 
		return 1; 
	}

	for(int i =0; i<n; i++){
		ptr[i] = i+1; 
	}

	printf("Original Array: "); 

	for(int i=0; i<n; i++){
		printf("%d ", ptr[i]); 
	}

	ptr = (int *)realloc(ptr, new_n* sizeof(int));
	if(ptr == NULL){
		printf("Memory allocation failed!\n");
		return 1; 
	}

	for(int i =n; i<new_n; i++){
		ptr[i] = i+1; 

	}

	printf("\nResized Array: "); 
	
	for(int i =0; i<new_n; i++){
		printf("%d ", ptr[i]);
	}

	printf("\n"); 

	free(ptr); 
	return 0; 
}	

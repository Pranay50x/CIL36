#include <stdlib.h>
#include <stdio.h>

int main(){
	int *ptr; 
	int n=5;
	ptr= (int *)malloc(n* sizeof(int));
       	if(ptr == NULL){
		printf("Memory not allocated\n"); 
		return 1;
	}

	printf("Memory successfully allocated \n"); 
	for(int i=0; i< n ;i++){
		ptr[i] = i+1; 
		printf("%d ",ptr[i]);
	       	
	}

	printf("\n");

	free(ptr); 
	return 0;
}



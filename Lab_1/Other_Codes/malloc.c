#include <stdio.h>
#include <stdlib.h>

int main(){

	int *ptr = (int *)malloc(sizeof(int));
	if(ptr == NULL) {
		printf("Memory Allocation failed\n");
		return 1;
	}
	
	*ptr = 42; 
	printf("Vale stored at ptr: %d\n", *ptr);
	free(ptr); 
	return 0; 
}
	

 

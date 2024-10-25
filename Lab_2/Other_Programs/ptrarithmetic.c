#include <stdio.h>
int main(){
	int arr[]  ={10,20,30,40,50}; 
	int *ptr = arr; 
	printf("Array elements using pointer arithmetic: "); 
	for(int i =0; i<5;i++){
		printf("*(ptr + %d) = %d\n",i, *(ptr+i)); 
	}


	return 0; 
}

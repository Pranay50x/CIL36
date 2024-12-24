#include <stdio.h>
#include <stdlib.h>
int main(){

	int a =10; 
	float b = 5.5; 
	char c = 'A';

	void *ptr; 
	ptr = &a; 
	printf("Value of integer a = %d\n",*(int *)ptr);
       	
	ptr = &b; 
	
	printf("Value of b = %.2f\n", *(float *)ptr);
	ptr = &c;
	printf("Value of c = %c\n", *(char *)ptr);	
	
	return 0; 
}

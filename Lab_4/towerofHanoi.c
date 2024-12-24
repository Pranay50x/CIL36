#include <stdio.h>
#include <stdlib.h>

static int step =0; 

void Toh(int n, char A, char B, char C){

	if(n==1)
		printf("\nStep %d\nMove %d from %c to %c\n", ++step,n,A,C); 
       	else{
		
		Toh(n-1,A,C,B);
		Toh(1,A,B,C); 
		Toh(n-1, B,A,C);
	}
}

int main() {

	int n; 
	printf("\nEnter te number of rings: "); 
	scanf("%d", &n); 

	Toh(n,'A','B','C'); 
	return 0; 
}
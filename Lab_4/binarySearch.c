#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int low, int high, int key){

	if(low<=high){
		int mid = (low+high)/2; 

		if(arr[mid] ==key){
			return mid; 
		}

		if(arr[mid]>key)
			return binarySearch(arr, low, mid -1, key); 

		if(arr[mid]<key)
			return binarySearch(arr,mid+1,high, key); 
	}

	return -1;
}


int main() {

	int n,x; 
	printf("Enter the number of elements in the array: "); 
	scanf("%d", &n); 
	int arr[n]; 
	printf("Enter %d elements in the array: \n",n);
	
	for(int i =0; i<n; i++){
		scanf("%d", &arr[i]); 
	}

	printf("Enter the element to be searched: "); 
	scanf("%d", &x); 
	int result = binarySearch(arr,0,n-1,x); 

	if(result == -1)
		printf("Element is not present in array");
	else
		printf("Element is present in index %d\n", result); 

	return 0; 
}

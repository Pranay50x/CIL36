/*
 * =====================================================================================
 *
 *       Filename:  6a.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26/12/2024 21:55:40
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
#include <string.h>

int binarySearch(int arr[], int low, int high, int ele){
    if(low<=high){
        int mid = (low+high)/2;

        if(arr[mid] ==ele)
            return mid; 
        if(arr[mid]>ele)
            return binarySearch(arr,low,mid-1,ele);
        if(arr[mid]<ele)
            return binarySearch(arr,mid+1,high,ele); 
    }

    return -1;     
}


int main(){
    int n;

    int arr[100]; 
    int low =0;

    printf("Enter the size of array: ");
    scanf("%d",&n); 

    int high = n-1; 
    

    printf("Enter the elements of array: "); 
    for(int i =0;i<n;i++){
        scanf("%d",&arr[i]); 
    }

    printf("Enter element to be searched for: ");
    int ele; 
    scanf("%d",&ele); 


    int res = binarySearch(arr,low,high,ele);
    
    if(res>0){
        printf("Element found at %d", res); 
    }
    else{
        printf("Element not found!"); 
    }
    return 0;
}

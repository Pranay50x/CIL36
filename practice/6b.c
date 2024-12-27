/*
 * =====================================================================================
 *
 *       Filename:  6b.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26/12/2024 22:14:49
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

static int step =0;

void Toh(int n, char A, char B,char C){
    if(n==1)
        printf("\nStep %d:\nMove %d from %c to %c\n", ++step,n,A,C);
    else{
        Toh(n-1,A,C,B);
        Toh(1,A,B,C);
        Toh(n-1, B, A, C);
    }
}

int main(){
    int n; 

    printf("Enter the no of discs: ");
    scanf("%d",&n);

    Toh(n,'A','B','C');
}



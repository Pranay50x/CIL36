#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int items[MAX]; 
int front = -1, rear = -1; 

void insert(int value); 
void delete();
void display(); 

int main(){

	int ch, callid; 
	while(1) {

		printf("\nEnter Choice\n1. Add Call\n2. Remove Call\n3. Display Call List\n4. Exit\n"); 
		scanf("%d", &ch); 
		switch(ch) {

			case 1:
				printf("Enter callerid to add\n"); 
				scanf("%d", &callid); 
				insert(callid); 
				break; 
			case 2: 
				delete(); 
				break;
			case 3:
				display(); 
				break; 
			case 4:
				exit(0); 
			default: 
				printf("Invalid Choice\n"); 
		}
	}
}


void insert(int value) {
	if(rear==MAX-1) 
		printf("\nOverflow"); 
	else {
		if(front==-1)
			front = 0; 
		rear = rear+1; 
		items[rear] = value; 
		printf("\nCallerId Added -> %d",value); 
		
	}
}

void delete(){

	if(front==-1)
		printf("\nUnderflow"); 
	else {
		printf("\nCaller id deleted: %d", items[front]); 
		front++; 
		if(front>rear)
			front = rear= -1; 
	}
}


void display(){
	if(rear == -1) 
		printf("Queue is empty\n"); 
	else {
		printf("Call held in queue are: \n"); 
		for(int i = front; i<=rear; i++)
			printf("%d ", items[i]); 
	}
}
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct Cqueue{
	int data;
};

struct Cqueue queue[MAX];
int front = -1, rear = -1; 

void insert(int value) {

	if((front==0 && rear== MAX -1) || (rear+1 == front)) {
		printf("Circular queue is full\n"); 
		return;
	}
	if(front == -1) {
		front = rear = 0; 
	}

	else if(rear == MAX -1) {
		rear = 0;
	}
	else {
		rear++; 
	}
	queue[rear].data = value;
}

int delete() {

	int value; 
	if(front==-1) {
		printf("Underflow\n"); 
		return -1; 
	}
	value = queue[front].data; 

	if(front == rear) 
		front = rear =-1; 
	else if (front == MAX -1) 
		front = 0; 
	else
		front++;
	return value;
}

void display() {

	if(front==-1)
		printf("Empty Queue\n"); 
	else {
		printf("\nFront -> %d", front); 
		printf("\nItems: -> ");
	       	for(int i =  front; i!=rear; i=(i+1)%MAX)
		    printf("%d ", queue[i].data); 	
    	
    		printf("%d ", queue[rear].data);	
		printf("\nRear -> %d\n", rear); 
	}
}


int main() {

	int ch, value; 
	while(1) {

		printf("1. Insert Element\n"); 
		printf("2. Delete Element\n"); 
		printf("3. Display\n"); 
		printf("4. Exit\n");
	       	printf("Enter your choice: "); 
		scanf("%d", &ch); 
		

		switch(ch) {
			
			case 1: 
				printf("Enter value to insert: "); 
				scanf("%d", &value); 
				insert(value); 
				break;
			       	
			case 2: 
				value = delete(); 
				if(value !=-1 ) 
				 	 printf("Deleted element is %d\n", value); 
			       	break;
				
		 	case 3: 
				display();
				break;
				
			case 4: 
				exit(0); 
			default: 
				printf("Invalid choice\n");
		}
	}
	
}
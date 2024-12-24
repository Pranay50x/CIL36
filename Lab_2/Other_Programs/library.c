#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BOOK {
	char title[100]; 
	char author[50];
	int publication_year; 
	float price; 
}; 

void readBookDetails(struct BOOK *b,int n){
	for(int i =0; i<n; i++){
		printf("Enter details for books %d\n",i+1); 
		printf("Title: "); 
		scanf(" %[^\n]",b[i].title); 
		printf("Author: ");
	       	scanf(" %[^\n]", b[i].author); 
		printf("Publication Year: "); 
		scanf("%d",&b[i].publication_year); 
		printf("Price: "); 
		scanf("%f",&b[i].price); 
	}
}

void displayBookDetails(struct BOOK *b, int n){
	printf("\nBook Details: \n"); 
	for(int i =0;i<n;i++){
		printf("Title: %s\n", b[i].title); 
		printf("Author: %s\n", b[i].author); 
		printf("Publication Year: %d\n", b[i].publication_year); 
		printf("Price: %.2f\n", b[i].price); 
	}
}

void searchBookByTitle(struct BOOK *b, int n, char* title){
	int found =0; 
	for(int i =0; i<n; i++){
		if(strcmp(b[i].title, title)==0){
			printf("\nBook found!\n");
			printf("Title: %s\n", b[i].title); 
			printf("Author Name: %s\n", b[i].author); 
			printf("Publication Year: %d\n", b[i].publication_year);
			printf("Price: %.2f\n", b[i].price);
			found =1;
			break;
		}
	}

	if(!found){
		printf("\nBook with title '%s' not found\n", title);
	}
}


int main(){
	int n; 
	char title[100]; 

	printf("Enter the number of books: "); 
	scanf("%d",&n); 

	struct BOOK books[n]; 

	readBookDetails(books, n);
	displayBookDetails(books, n);

	printf("\nEnter the title of the books to be searched: "); 
	scanf(" %[^\n]", title); 
	searchBookByTitle(books, n, title); 
	return 0; 
}
		


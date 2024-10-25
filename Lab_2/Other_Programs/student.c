#include <stdio.h>

struct STUDENT{
	char name[50]; 
	int roll_no; 
	float marks;
};

void readStudentDetails(struct STUDENT *s, int n){
	for(int i =0; i<n;i++){
		printf("Enter the details for the student: %d\n",i+1); 
		printf("Name: ");
		scanf(" %[^\n]", s[i].name); 
		printf("Roll no: ");
		scanf("%d",&s[i].roll_no); 
		printf("Marks: ");
		scanf("%f",&s[i].marks);
	    }
}


void displayStudent(struct STUDENT *s, int n){
	printf("\nStudent Details \n");
	for(int i =0; i<n;i++){
		printf("\nStudent ID: \n");
		printf("Name : %s\n",s[i].name); 
		printf("Roll no: %d\n", s[i].roll_no); 
		printf("Marks: %.2f\n", s[i].marks);
	}
}


int main(){

	int n; 
	printf("Enter no of students: "); 
	scanf("%d",&n);
	struct STUDENT students[n];
	readStudentDetails(students, n); 
	displayStudent(students, n); 
	return 0; 
}

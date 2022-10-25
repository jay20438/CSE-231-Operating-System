//Student Record
#include <stdio.h>
#include <stdlib.h>
struct studentRecord
{
	char name[1000];
	int rollno;
	int yearOfJoining;
	char enrolledAcademicProgram[1000];
	
	struct studentRecord *next;
	
}*head;



void insertStudent(char* name,int rollno,int yearOfJoining,char* enrolledAcademicProgram)
{
	
	struct studentRecord* student = (struct studentRecord*) malloc(sizeof(struct studentRecord));
	strcpy(student->name,name);
	student->rollno = rollno;
	student->yearOfJoining = yearOfJoining;
	strcpy(student->enrolledAcademicProgram,enrolledAcademicProgram);
	student->next = NULL;
	
	if(head == NULL)
	{		
		head = student;		
	}
	else
	{		
		student->next = head;
		head = student;
	}
	
}

void searchStudent(int rollno)
{
	if(!head)
	{
		printf("Student not found!");
	}
	else
	{
	    struct studentRecord* p = head;
		while(p != NULL)		
		{
			if(p->rollno == rollno)
			{
				printf("Roll number is %d\n",p->rollno);
				printf("Student name %s\n",p->name);
				printf("Joining year of the student %d\n",p->yearOfJoining);
				printf("Enrolled academic program %s\n",p->enrolledAcademicProgram);
			  return;
			  break;	
			}
			p = p->next;
		}
		if(p == NULL)
		{
			printf("No such Student exists.");
		}
	}
}


void display()
{
	struct studentRecord * temp = head;
	while(temp!=NULL)
	{
		printf("Roll Number: %d\n", temp->rollno);
        printf("Name: %s\n", temp->name);
        printf("Year Of joining: %d\n",temp->yearOfJoining);
        printf("Enrolled academic program: %s\n",temp->enrolledAcademicProgram);
        temp = temp->next;
	}
}

int main()
{
	head = NULL;
	char name[1000];
	int rollno;
	int yearOfJoining;
	char enrolledAcademicProgram[1000];
	char temp;
	
	int option;
		
	
	printf("Student Record Management System \n\t1.Insert \n\t2.Search \n\t3.View the list of all students \n\t4.Exit\n");
    do{
	
	printf("Enter one of the options(Number):");
	scanf("%d",&option);
	
	int i;
	
	if(option == 1)
	{
		printf("Enter the name of the student:");
		scanf("%s",name);
		printf("Enter the roll number of the student:");
		scanf("%d",&rollno);
		printf("Enter the year of joining:");
		scanf("%d",&yearOfJoining);
		printf("Enter the academic program in which the student is enrolled:");
		scanf("%s",enrolledAcademicProgram);
		insertStudent(name,rollno,yearOfJoining,enrolledAcademicProgram);
		
	}
	else if(option == 2)
	{
		printf("Enter the roll number of the student to be searched:");
		scanf("%d",&rollno);
		searchStudent(rollno);
	}
	else if(option == 3)
	{
		display();
		
	}
	else if(option == 4)
	{
		exit(0);
	}
	else
	{
		printf("Invalid option selected!\nPlease try again.");
	}
	printf("\n");
   
	 }while(option != 0);
}

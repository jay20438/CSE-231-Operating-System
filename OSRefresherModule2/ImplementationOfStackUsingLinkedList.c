#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};

struct node *top = NULL;


void push(int value)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node*));
    
    if(newNode == NULL)
    {
    	printf("No node to push!");
	}
	else
	{		
		if(top == NULL)
		{
			newNode->data = value;
			newNode->next = NULL;
			top = newNode;
		}
		else
		{
			newNode->data = value;
			newNode->next = top;
			top = newNode;
		}
		printf("Node pushed at the top of the stack is %d",newNode->data);
	}
}

int isEmpty()
{
	return top == NULL;
}

void pop()
{
	int key;
	struct node *newNode;
	if(top == NULL)
	{
		printf("Underflow in Stack!\n");
		return;
	}
	else
	{
		key = top->data;
		newNode = top;
		top = top->next;
		free(newNode);
		printf("Top most element popped from the stack.",newNode->data);
	}
}

int peek()
{
	if(!isEmpty())
	{
		printf("%d",top->data);
	}
	else
	{
		exit(1);
	}
}

void display()
{
	struct node *newNode;
	newNode = top;
	if(newNode == NULL)
	{
		printf("Underflow in Stack.\n");
	}
	else
	{
		while(newNode->next != NULL)
		{
			printf("%d ",newNode->data);
			newNode = newNode->next;
		}
		printf("%d",newNode->data);
	}
}

int main()
{
	int option;
	
	int n;
	printf("Enter number of times you want to do operation:");
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		printf("\n1.Push \n2.Pop\n3.Display\n4.Peek");
	    printf("\nEnter the option number:");
	    scanf("%d",&option);
	if(option == 1)
	{
		int x;
		printf("Enter the value of the node to be pushed:");
		scanf("%d",&x);
		push(x);
	}
	if(option == 2)
	{
		pop();
	}
	if(option == 3)
	{
		display();
	}
	if(option == 4)
	{
		peek();
	}
	
	}
}

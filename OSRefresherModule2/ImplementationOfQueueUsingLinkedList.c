//Queue implementation using LinkeList.
#include <stdio.h>
#include <stdlib.h>
 
struct Node 
{
    int data;
    struct Node* next;
};
 

struct Queue 
{
    struct Node *rear,*front;
};
 

struct Node* newNode(int value)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}
 

struct Queue* makequeue()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
 

void enqueue(struct Queue* q, int value)
{
    
    struct Node* temp = newNode(value);
 
    
    if (q->rear == NULL) 
	{
        q->front = q->rear = temp;
        return NULL;
    }
 
    
    q->rear->next = temp;
    q->rear = temp;
    
}
 

void dequeue(struct Queue* q)
{
    
    if (q->front == NULL)
        return;
 
    
    struct Node* temp = q->front;
 
    q->front = q->front->next;
 
    
    if (q->front == NULL)
        q->rear = NULL;
 
    free(temp);
}

int main()
{
	struct Queue* q = makequeue();
	int n;
	printf("Enter the number of times you want to do the operations:");
	scanf("%d",&n);
	int i,option;
	for(i=0;i<n;i++)
	{
		printf("Choose one of the options:");
		printf("\n1.Enqueue");
		printf("\n2.Dequeue");
		printf("\nEnter the option number:");
		scanf("%d",&option);
		if(option == 1)
		{
			printf("Enter the node to be put in the queue:");
			int x;
			scanf("%d",&x);
			enqueue(q,x);
		}
		if(option == 2)
		{
			printf("Deleting the first in node.\n");
			dequeue(q);
		}
		printf("Node at front of the queue is %d\n",q->front->data);
		printf("Node at rear end of the queue is %d\n",q->rear->data);
		
	}
	
	return 0;
}

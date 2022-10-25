//Binary Search tree insertion and deletion.
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left, *right;
};

struct node* newNode(int value)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = value;
	temp->left = temp->right = NULL;
	return temp;
}

void preorder(struct node* node)
{
	if(node == NULL)
	{
		return;
	}
	
	printf("%d ",node->data);
	preorder(node->left);
	preorder(node->right);
}

struct node* nodeInsertion(struct node* node,int data)
{
	if(node == NULL)
	return newNode(data);
	
	if(data < node->data)
	{
		node->left = nodeInsertion(node->left,data);
	}
	else 
	{
		node->right = nodeInsertion(node->right,data);
	}
	return node;
}


struct node* nodeOfMinValue(struct node* node)
{
	struct node* current = node;
	while(current && current->left != NULL)
	{
		current = current->left;
	}
	return current;
}struct node* nodeDeletion(struct node* root, int data)
{
	if(root == NULL)
	{
		return root;
	}
	
	if(data < root->data)
	{
		root->left = nodeDeletion(root->left,data);
	}
	
	else if(data > root->data)
	{
		root->right = nodeDeletion(root->right,data);
	}
	
	else
	{
		if(root->right == NULL)
		{
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		
		else if(root->right == NULL)
		{
			struct node* temp = root->left;
			free(root);
			return temp;
		}
		
		struct node* temp = nodeOfMinValue(root->right);
		
		root->data = temp->data;
		
		root->right = nodeDeletion(root->right,temp->data);
		
	}
	return root;
}

int main()
{
	struct node* root = NULL;
	
	int n,value1,value2;
	printf("Enter the number of times you want to do operations on binary search tree: ");
	scanf("%d",&n);
	char string[1000];
	
	
	int j;
	for(j = 0;j<n;j++)
	{
		printf("\nEnter insert or delete:");
	    scanf("%s",string);
	    value1 = strcmp(string,"insert");
	    value2 = strcmp(string,"delete");
	    if(value1 == 0)		
	    {
	    	printf("Enter the value of the node to be inserted:");
	    	int x;
	    	scanf("%d",&x);
	    	root = nodeInsertion(root,x);
		}
		
		if(value2 == 0)		
	    {
	    	printf("Enter the value of the node to be deleted:");
	    	int y;
	    	scanf("%d",&y);
	    	root = nodeDeletion(root,y);
		}
		printf("Preorder traversal of nodes till now:");
		preorder(root);
		
	}
    
    
    return 0;
}

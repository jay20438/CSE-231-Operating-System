//Height balanced Binary Search Tree (AVL).
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *left,*right;
	int height;
};

int max(int x,int y)
{
	if(x>y)
	{
		return x;
	}
	else if(y>x)
	{
		return y;
	}
}

int height(struct Node *n1)
{
	if(n1 == NULL)
	   return 0;
	return n1->height;
}



struct Node* newNode(int data)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return(node);
}

struct Node *rightRotation(struct Node *p)
{
	struct Node *q = p->left;
	struct Node *T2 = q->right;
	
	q->right = p;
	p->left = T2;
	
	p->height = max(height(p->left),height(p->right)) + 1;
	q->height = max(height(q->left),height(q->right)) + 1;
	
	return q;
}
struct Node *leftRotation(struct Node *q)
{
	struct Node *p = q->right;
	struct Node *T2 = p->left;
	
	p->left = q;
	q->right = T2;
	
	q->height = max(height(q->left),height(q->right)) + 1;
	p->height = max(height(p->left),height(p->right)) + 1;
	
	return p;
}
	
int findBalance(struct Node *n1)
{
	if(n1 == NULL)
	{
		return 0;
	}
	return height(n1->left) - height(n1->right);
}
	
struct Node* insert(struct Node* node, int data)
{
    
    if (node == NULL)
        return(newNode(data));
 
    if (data < node->data)
        node->left  = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else 
        return node;
 
    
    node->height = 1 + max(height(node->left),
                           height(node->right));
 
    
    int balance = findBalance(node);
 
   

    if (balance > 1)
        {
        	if(data < node->left->data)
        	{
        		return rightRotation(node);
			}
			
			if(data > node->left->data)
			{
				node->left =  leftRotation(node->left);
                return rightRotation(node);
			}
		}
 
    if (balance < -1)
    {
    	if(data > node->right->data)
    	{
    		return leftRotation(node);
		}
		
		if(data < node->right->data)
		{
			node->right = rightRotation(node->right);
            return leftRotation(node);
		}
	}
 

 
    return node;
}
	
struct Node* minvalueofnode(struct Node* node)
{
	struct Node* current = node;
	while(current->left != NULL)
	{
		current = current->left;
	}
	return current;
}
	
struct Node* deleteNode(struct Node* root,int data)
{
	if(root == NULL)
	{
		return root;
	}
	if(data<root->data)
	{
		root->left = deleteNode(root->left,data);
	}
	else if(data>root->data)
	{
		root->right = deleteNode(root->right,data);
	}
	else
	{
		if((root->left == NULL) || (root->right == NULL))
		{
		struct Node *temp = root->left?root->left:root->right;
			if(temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
			{
				*root = *temp;
			}
			free(temp);
		}
		else
		{
			struct Node* temp = minvalueofnode(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right,temp->data);
		}
	}
	if(root == NULL)
	{
		return root;
	}
			
		root->height = 1 + max(height(root->left),height(root->right));
		int balance = findBalance(root);
			
		if(balance>1)
		{
			if(findBalance(root->left) >= 0)
			{
				return rightRotation(root);
			}
			
			if(findBalance(root->left) <0)
			{
			    root->left = leftRotation(root->left);
			    return rightRotation(root);	
			}
		}
		
			
		if(balance<-1)
		{
			if(findBalance(root->right)<=0)
			{
				return leftRotation(root);
			}
			
			if(findBalance(root->right)>0)
			{
				root->right = rightRotation(root->right);
			    return leftRotation(root);
			}
		}
			
		return root;
}

void preorder(struct Node *root)
{
	if(root != NULL)
	{
	
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
	
    }
}

void postorder(struct Node *root)
{
	if(root != NULL)
	{
	
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
	
    }
}
	
int main()
{
	struct Node *root = NULL;
	
	int n,value1,value2;
	printf("Enter the number of times you want to do operations on height balancing binary search tree: ");
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
	    	root = insert(root,x);
		}
		
		if(value2 == 0)		
	    {
	    	printf("Enter the value of the node to be deleted:");
	    	int y;
	    	scanf("%d",&y);
	    	root = deleteNode(root,y);
		}
		
		printf("\n");
		printf("Postorder traversal of nodes till now:");
		postorder(root);
		
	}
    
    
    return 0;
}
	
	
	


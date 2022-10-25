//Matrix with fixed columns and dynamic rows.
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int* dynamicArray[6];
	
	dynamicArray[0] = malloc(sizeof(int)*7);
	dynamicArray[1] = malloc(sizeof(int)*4);
	dynamicArray[2] = malloc(sizeof(int)*6);
	dynamicArray[3] = malloc(sizeof(int)*3);
	dynamicArray[4] = malloc(sizeof(int)*7);
	dynamicArray[5] = malloc(sizeof(int)*2);
	
	int capacity[6] = {7,4,6,3,7,2},k=0,number = 9;
	int i;
	for(i=0;i<6;i++)
	{
		int* p = dynamicArray[i];
		
		int j;
		for(j=0;j<capacity[k];j++)
		{
			*p = number;
			p++;
		}
		k++;
	}
	
	k = 0; 
	
	int x;
	for(x =0;x<6;x++)
	{
		int* p = dynamicArray[x];
		int j;
		for(j=0;j<capacity[k];j++)
		{
			printf("%d ",*p);
			p++;   
		}
		printf("\n");
		k++;
	}
	
	int y,numberOfColumns;
	k = 0;
	for(i=0;i<6;i++)
	{
		
		printf("Enter the number of columns in the row:");
		scanf("%d",&numberOfColumns);
		
		dynamicArray[i] = realloc((int*)dynamicArray[i],numberOfColumns*sizeof(int));   
		capacity[k] = numberOfColumns;  
		int j;
		int *p = dynamicArray[i];  
		for(j=0;j<numberOfColumns;j++)   
		{
			*p = number;
			p++;    
		}
		k++;
	}
	
	k = 0; 
	
	for(x =0;x<6;x++)
	{
		int* p = dynamicArray[x];
		int j;
		for(j=0;j<capacity[k];j++)
		{
			printf("%d ",*p);
			p++;
		}
		printf("\n");
		k++;
	}
	return 0;
}

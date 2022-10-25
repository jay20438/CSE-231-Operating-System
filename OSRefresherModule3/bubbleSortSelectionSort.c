//Bubble and Selection Sort
#include <stdio.h>
void bubbleSort(int arr[],int n)
{
	int i;
	for(i=0;i<n-1;i++)
	{
		if(arr[i] > arr[i+1])
		{
			int temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
		}
		
		bubbleSort(arr,n-1);
	}
}

void selectionSort(int arr[],int n)
{
	int p;
	for(p=0;p<n-1;p++)
	{
		int minIndex = p;
		int q;
		for(q=p+1;q<n;q++)
		{
			if(arr[q]<arr[minIndex])
			{
				minIndex = q;
			}
		}
		
		int temp = arr[p];
		arr[p] = arr[minIndex];
		arr[minIndex] = temp;
	}
}

int main()
{
	printf("Enter the size of the array:");
	int n;
	scanf("%d",&n);
	
	int arr[n];
	int value1;
	int value2;
	int k;
	printf("Enter the elements of the array:");
	for(k=0;k<n;k++)
	{
		scanf("%d",&arr[k]);
	}
	
	
	
	
	
	
	printf("Choose the sorting method:");
	printf("\n1.BubbleSort");
	printf("\n2.SelectionSort");
	printf("\n");
	int option;
	scanf("%d",&option);
	
	if(option==1)
	{
		bubbleSort(arr,n);
		
		int i;
		for(i = 0;i<n;i++)
		{
			printf("%d",arr[i]);
			printf("\n");
		}
	}
	
	if(option==2)
	{
	    selectionSort(arr,n);
	    int i;
		for(i = 0;i<n;i++)
		{
			printf("%d  ",arr[i]);
			
		}	
	}
}

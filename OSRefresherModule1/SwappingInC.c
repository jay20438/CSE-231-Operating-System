#include <stdio.h>
void main(int a,int b)
{
	printf("Enter the value of a:");
	scanf("%d",&a);
	printf("\n");
	printf("Enter the value of b:");
	scanf("%d",&b);
	
	int temp;
	temp = a;
	a = b;
	b = temp;
	
	printf("The value of a after being swapped is %d",a);
	printf("\n");
	printf("The value of b after being swapped is %d",b);
	
	int n;
	printf("\n");
	printf("Enter the size of the array:");
	scanf("%d",&n);
	
	int arr1[n],arr2[n],i;
	printf("Enter the elements of arr1:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr1[i]);
	}
	printf("Enter the elements of arr2:");
	for(i =0;i<n;i++)
	{
		scanf("%d",&arr2[i]);
	}
	
	
	for(i=0;i<n;i++)
	{
		
		arr1[i] = arr1[i] + arr2[i];
		arr2[i] = arr1[i] - arr2[i];
		arr1[i] = arr1[i] - arr2[i];
		
	}
	
	printf("\n");
	
	for(i =0;i<n;i++)
	{
		printf("%d ",arr1[i]);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr2[i]);
	}
	return 0;
}

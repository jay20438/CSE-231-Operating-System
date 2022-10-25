// Binary Search
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[],int l,int m,int h)
    {
        int p = m-l+1;
        int q = h-m;

        int left1[p],right1[q],i;
        for(i =0;i<p;i++)
            left1[i] = arr[l+i];
            int j;
        for(j =0;j<q;j++)
            right1[j] = arr[m+j+1];

        i = 0;
		j =0;
		int k = l;

        while(i < p && j < q)
        {
            if(left1[i] <= right1[j])
            {
                arr[k] = left1[i];
                i++;
        }
            else
            {
                arr[k] = right1[j];
                j++;
            }
        k++;
    }

    while(i<p)
    {
        arr[k] = left1[i];
        i++;
        k++;
    }
    while(j<q)
    {
        arr[k] = right1[j];
        j++;
        k++;
    }
    return 0;
}
void divide(int arr[],int l,int h)
{
    if(l<h)
    {
        int m = (l+h)/2;

        divide(arr,l,m);
        divide(arr,m+1,h);

        merge(arr,l,m,h);
    }
    return 0;
}

int binarySearch(int arr[],int l,int h,int x)
{
	if(h>=l)
	{
		int mid = l + (h-l)/2;
		
		if(arr[mid] == x)
		{
			return mid;
		}
		
		if(arr[mid]>x)
		{
			return binarySearch(arr,l,mid-1,x);
		}
		
		return binarySearch(arr,mid+1,h,x);
	}
	return -1;
}

int main(void)
{
	int n;
	printf("Enter the size of the array:");
	scanf("%d",&n);
	
	int i;
	int arr[n];
	
	printf("Enter the elements in the array:");
	for(i =0;i<n;i++)
	{
		scanf("%u",&arr[i]);
	}
	divide(arr, 0, n - 1);	

	int x;
	printf("Enter the number to be searched: ");
	scanf("%u",&x);

	int search = binarySearch(arr,0,n-1,x);
	
	if(search == -1)
	{
		printf("Element not found.");
	}
	
	else
	{
		printf("Element found at index : %u",search);
	}
	
	return 0;
	
}

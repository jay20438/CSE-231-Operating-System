//Store bits in an array.
#include <stdio.h>

void addNumbers(char A[32],char B[32])
{
	int i,sum;
	char ansArray[33];
	int carry = 0;
	for(i=32;i>=0;i++)
	{
		int digitOfA = A[i];
		int digitOfB = B[i];
		sum = digitOfA + digitOfB + carry;
		
		if(sum>=10)
		{
			ansArray[i] = sum%10;
			carry = sum/10;
		}
		
	}
	
	printf("The sum of array is:");
	for(i=0;i<33;i++)
	{
		printf("%u",&ansArray[i]);
	}
}

int main()
{
	int n;
	int j;
	char A[32],B[32];
	
	printf("Enter digits for A:");
	for(j=0;j<32;j++)
	{
		scanf("%c",&A[j]);
	}
	
	printf("Enter digits for B:");
	for(j=0;j<32;j++)
	{
		scanf("%c",&B[j]);
	}
	
	
		
		
	addNumbers(A,B);
	
	return 0;
}

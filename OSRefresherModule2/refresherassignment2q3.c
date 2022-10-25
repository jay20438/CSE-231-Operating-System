// Array pointer of length 5.
#include <stdio.h>
#include <math.h>
void add(int x,int y)
{
	printf("%d",x+y);
}

void sub(int x,int y)
{
	printf("%d",x-y);
}

void div(int x,int y)
{
	printf("%d",x/y);
}

void mul(int x,int y)
{
	printf("%d",x*y);
}

void expon(int x,int y)
{
	printf("%d",pow(x,y));
}


int main()
{
	int arr[5];
	int x, y;
  int (*operation[5])(int, int) = {add,sub,mul,div,expon};
  printf("Enter the value of a:");
  scanf("%d",&x);
  
  printf("Enter the value of b:");
  scanf("%d",&y);
  printf("\n");
  
  
  int j;
  for(j=0;j<5;j++)
  {
  	printf("%p",&arr[j]);
  	printf("\n");
  }
return 0;
}

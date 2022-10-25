//Reverse String
#include <stdio.h>

int stringLength(char* str)
{
	int count = 0;
	
	while(str[count] != '\0')
	{
		++count;
	}
	return count;
}


int main()
{
	char str[1000];
	char revstr[1000];
	printf("Enter the string to be reversed: ");
	fgets(str,1000,stdin);
	
	int n = stringLength(str);
	int i,j=0;
	for(i=n-1;i>=0;i--)
	{
		revstr[j++] = str[i];
	}
	revstr[j]='\0';
	
	printf("\n");
	
	printf("String after being reversed: %s",revstr);
}

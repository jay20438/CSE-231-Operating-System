//Copy from source file to destination file.
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *pointerToSourceFile,*pointerToDestinationFile;
	char sourceFile[1000],c;
	
	printf("Enter the name of the source file");
	scanf("%s",sourceFile);
	
	pointerToSourceFile = fopen(sourceFile,"r");
	if(pointerToSourceFile == NULL)
	{
		printf("The file %s cannot be opened \n",sourceFile);
		exit(0);
	}
	
	printf("Enter the destination file for writing:");
	scanf("%s",sourceFile);
	
	pointerToDestinationFile = fopen(sourceFile,"w");
	if(pointerToDestinationFile == NULL)
	{
		printf("The file %s cannot be opened",sourceFile);
		exit(0);
	}
	
	c = fgetc(pointerToSourceFile);
	while(c != EOF)
	{
		fputc(c,pointerToDestinationFile);
		c = fgetc(pointerToSourceFile);
	}
	
	printf("\n");
	printf("Contents copied to the file %s",sourceFile);
	fclose(pointerToSourceFile);
	fclose(pointerToDestinationFile);
	return 0;
}

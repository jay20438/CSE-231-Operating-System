#include _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <sys/syscall.h>
#define SYSTEM 448
int main()
{
	float sourceArray[3][3];
	sourceArray[3][3] = {{1.23,2.34,3.56},{4.78,5.97,6.47},{7.37,8.53,9.12}};
	
	float *pointer;
	pointer = &sourceArray;
	long answer = syscall(SYSTEM,pointer);
	return answer;
}

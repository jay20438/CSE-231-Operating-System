#include "A.h"
#include "B.h"

void A( unsigned long long a)
{
	printf("I'm inside func A. %llu \n", a);
	B(a);
	return;
}    

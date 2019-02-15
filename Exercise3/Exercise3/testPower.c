#include <stdio.h>
#include "power.c"
int main()
{
	printf("0 to the power of 4 is %d\n", power(0, 4));
	printf("2 to the power of 0 is %d\n", power(2, 0));
	printf("1 to the power of 4 is %d\n", power(1, 4));
	printf("2 to the power of 1 is %d\n", power(2, 1));
	printf("2 to the power of 4 is %d\n", power(2, 4));
	return 0;
}
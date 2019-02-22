#include <stdio.h>
#include "multiswap.c"

int main()
{
	int x = 2;
	int y = 6;
	int z = 4;
	/*& is for pointers*/
	multiswap(&x, &y, &z);
	printf("x = 6 & %d y = 4 & %d z = 2 & %d", x, y, z);
	return 0;
}
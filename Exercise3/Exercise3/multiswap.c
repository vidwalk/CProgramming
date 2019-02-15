#include <stdio.h>
#include "multiswap.h"

void multiswap(int* x, int* y, int* z)
{
	/*Aux is used to keep the value that x is currently pointing to*/
	int aux = *x;
	*x = *y;
	*y = *z;
	*z = aux;
}

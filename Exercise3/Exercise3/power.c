#include <stdio.h>
#include "power.h"

int power(int x, int y)
{
	if (x == 0)
		return 0;
	if (y == 0)
		return 1;
	if (x == 1)
		return 1;
	if (y == 1)
		return x;
	int aux = x;
	for(int i = 1; i < y; i++)
	{
		aux = aux * x;
	}
	return aux;
}
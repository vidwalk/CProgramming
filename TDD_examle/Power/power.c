#include "power.h"

int power(int base , int exp)
{
	int result;
	if( exp == 0)
	{
		return 1;
	}
	if(exp % 2 == 0)
	{
		result = power(base, exp / 2);
		return result * result;
	}
	return base * power(base, --exp);
}
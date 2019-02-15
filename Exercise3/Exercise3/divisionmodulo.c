#include <stdio.h>

int main()
{
	int a = 7;
	int b = 3;
	float c = 7;
	float d = 3;
	char e = '7';
	char f = '3';
	/*modulo for integer*/
	printf("Normal modulo = %d\n", a % b);
	printf("Normal division = %d\n", a / b);
	/*modulo is not accessible to float*/
	printf("Normal modulo with floats = %d\n", (int)c % (int)d);
	printf("Normal division with floats = %lf\n", c / d);
	/*divides and does the modulo of the integer values of the chars*/
	printf("Normal modulo with char = %d\n", e % f);
	printf("Normal division with char= %d\n", e / f);
	return 0;
}
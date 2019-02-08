#include <stdio.h>
/* print Celsius-Fahrenheit table for fahr = 0, 20, ..., 300 */
main()
{
	int fahr, celsius;
	int lower, upper, step;
	lower = 0; /* lower limit of temperature scale */
	upper = 300; /* upper limit */
	step = 20; /* step size */
	fahr = lower;
	printf("---Celsius-Fahrenheit table---\n");
	while (fahr <= upper) {
		celsius = 5 * (fahr - 32) / 9;
		printf("%d\t%d\n", celsius, fahr);
		fahr = fahr + step;
	}

}
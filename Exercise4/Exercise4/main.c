#include "my_strdiff.c"
#include <stdio.h>

int main()
{
	char a[] = "car";
	char b[] = "cac";
	my_strdiff(a, b);
	printf("%s", a);
	printf("%s", b);
}

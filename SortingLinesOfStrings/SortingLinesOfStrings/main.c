#include <stdio.h> 
#include <string.h>
#include "InputOutputLines.c"
#include "QuickSort.c"
#define MAXLINES 5000
char *lineptr[MAXLINES];
char storage[MAXLINES][256];
/* sort input lines */
int main()
{
	int nlines;
	if ((nlines = readlines(lineptr, MAXLINES, storage)) >= 0) {
		printf("%s\n", "before quicksort");
		writelines(lineptr, nlines);
		qsort(lineptr, 0, nlines - 1);
		printf("%s\n", "after quicksort");
		writelines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("error: input too big to sort\n");
		return 1;
	}
}

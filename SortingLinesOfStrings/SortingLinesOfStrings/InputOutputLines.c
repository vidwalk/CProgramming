#include <stdio.h>
#include <string.h>
#include "InputOutputLines.h"
#include "GetLine.c"

#define MAXLEN 1000 /* max length of any input line */

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char storage[][256])
{
	int len, nlines;
	char line[MAXLEN];
	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || nlines > 5)
			return -1;
		else
		{
			line[len - 1] = '\0'; /* delete newline */
			strcpy(storage[nlines], line);
			lineptr[nlines] = storage[nlines];
			nlines++;
		}
	return nlines;
}

/*writelines: write output line*/
void writelines(char *lineptr[], int nlines)
{
	int i;

	while (nlines-- > 0) 
		printf("%s\n", *lineptr++);


}
#include <stdio.h>
#include "my_string_func.c"
#define MAX_LENGTH 1000
int main()
{
	char line[MAX_LENGTH];
	char upper[MAX_LENGTH];
	int line_length = read_line(line);;
	/* Use a while loop to read input lines as long as there are any.
	For each input line, print the length of the line as well as the upper case version of the line
	NOTE You are NOT allowed to use the standard toupper(...) function in string.h*/
	while(line_length != 0) {
		my_to_upper(line, upper);
		printf("Length: %d\t%s\n", line_length, upper);
		line_length = read_line(line);
		upper[line_length] = '\0';
	}
	return 0;
}
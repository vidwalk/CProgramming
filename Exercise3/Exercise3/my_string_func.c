#include <stdio.h>
#include "my_string_func.h"
#include <string.h>
#include <ctype.h>
/* read_line: read a line into s, return length */
int read_line(char s[])
{
	int c = 0;
	int i = 0;
	int done = 0;
	do
	{
		c =getchar();
		if(c ==EOF|| c =='\n')
		{
			done = 1;
		}
		else
		{
			s[i++] = c;
		}
	} while(!done);
	s[i] ='\0';
	return i;
}
void my_to_upper(char* str_in, char* str_out)
{
	unsigned int i = 0;
	/* You must implement your own version of to-upper using the two strings str_in and str_out.
	Loop over the str_in (as long as it "contains" something).
	Look at the "current" character and check if its a lowercase letter.
	If it is, convert it to the upper case version and add that to the str_out character array
	*/
	int length = strlen(str_in);
	for (i = 0; i < length; i++) {
		if (islower(str_in[i]))
		{
			str_out[i] = toupper(str_in[i]);
		}
		else
			str_out[i] = str_in[i];
		/*weird characters if this is not added to the end of the array of chars*/
		str_out[length] = '\0';
	}
}

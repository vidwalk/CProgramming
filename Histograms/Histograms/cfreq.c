#include <stdio.h>
#include <ctype.h>

#define IN 1 /*inside a word*/
#define OUT 0 /*outside a word*/
main()
{
	int c, i;

	int alphabet[25];
	for (i = 0; i < 26; ++i)
		alphabet[i] = 0;

	/*Put a space before pressing enter*/
	while ((c = getchar()) != ' ')
	{
		c = toupper(c);
		if ('A' <= c && c <= 'Z')
			++alphabet[c - 'A'];
	}

	for (i = 0; i < 26; ++i)
		if(alphabet[i] != 0)
		printf("%c %d\n------\n",'A'+i, alphabet[i]);
}
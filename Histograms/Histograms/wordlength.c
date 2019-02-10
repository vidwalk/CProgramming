#include <stdio.h>

#define IN 1 /*inside a word*/
#define OUT 0 /*outside a word*/
main()
{
	int c, nw, nc, state;

	state = IN;
	nw = nc = 0;
	while((c = getchar())!= EOF)
	{
		if (c == ' ' || c == '\n' || c == '\t')
		{
			state = OUT;
		}
		if (state != OUT)
			++nc;
		if (state == OUT )
		{
			if(nc != 0)
			{ 
			printf("%d\n", nc);
			printf("-----\n");
			nc = 0;
			}
			state = IN;
			++nw;
		}
	}
	printf("%d %d\n", nw, nc);
}
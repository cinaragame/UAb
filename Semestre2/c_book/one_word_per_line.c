#include <stdio.h>

#define IN	1 //inside word
#define OUT	0 //outside word

/*	Prints inpus one word per line */
int main()
{
	int c, state;

	state = OUT;

	while ((c = getchar()) != EOF)
	{
		//when encountering ' ', new line or tab, print '\n' only for the first
		if(c == ' ' || c == '\n' || c == '\t')
		{
			if(state == IN)
			{
				putchar('\n');
				state = OUT;
			}
			continue;
		}
		//count new word
		else if(state == OUT)
			state = IN;
		
		putchar(c);
	}
}

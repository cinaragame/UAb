#include <stdio.h>

/*
	Substitutes sequences of blank spaces for a single blank
*/
int main()
{
	int c;

	while((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			while(c == ' ')
			{
				c = getchar();
			}
			printf(" ");
		}
		putchar(c);
	}
}

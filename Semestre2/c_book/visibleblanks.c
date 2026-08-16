#include <stdio.h>

/*
	Substitutes sequences of blank spaces for a single blank
	Substitutes tabs for \t, backspace by \b and backslash by \\
*/
int main()
{
	int c;

	while((c = getchar()) != EOF)
	{
		/*Dealing with blankspaces*/
		if (c == ' ')
		{
			while(c == ' ')
			{
				c = getchar();
			}
			printf(" ");
		}
		/*Dealing with tabs*/
		if(c == '\t')
		{
			printf("\\t");
			continue;
		}
		/*Dealing with backspaces*/
		if(c == '\b')
		{
			printf("\\b");
			continue;
		}
		/*Dealing with backslash*/
		if(c == '\\')
		{
			printf("\\\\");
			continue;
		}

		putchar(c);
	}
}

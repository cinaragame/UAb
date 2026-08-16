#include <stdio.h>

/*
	Counts lines in input, including blank ones
*/
int main()
{
	int c;
	long char_count, line_count;
	
	//Counts new-line characters
	char_count = 0;
	line_count = 0;
	while((c = getchar()) != EOF)
	{
		char_count++;
		if(c == '\n')
			line_count++;
	}

	//Acounts for the first line of text
	if(char_count != 0)
		line_count++;

	//Prints results
	printf("\nNumber of lines: %ld\n", line_count);
}

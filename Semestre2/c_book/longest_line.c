#include <stdio.h>

#define MAX_LINE 5

int getLine(char line[], int max_size);
void copyLine(char new_line[], char original_line[]);

int main()
{
	char present_line[MAX_LINE], longest_line[MAX_LINE];
	int present_size, longest_size;

	present_size = longest_size = 0;
	while((present_size = getLine(present_line, MAX_LINE)) != 0)
		if(present_size > longest_size)
		{
			longest_size = present_size;
			copyLine(longest_line, present_line);
		}
	if(longest_size > 0)
		printf("\nLongest line size: %d\nInput (up to %d characters): %s\n",
			longest_size, MAX_LINE-1, longest_line);
	else
		printf("No input\n");
	
	return 0;
}

int getLine(char line[], int max_size)
{
	int c, i;

	i = 0;
	while((c = getchar()) != EOF && c != '\n')
	{
		if(i < max_size-1)
			line[i] = c;
		i++;
	}
	if(c == '\n')
	{
		if(i < max_size-1)
			line[i] = c;
		i++;
	}
	if(i < max_size)
		line[i] = '\0';
	else
		line[max_size-1] = '\0';

	return i;
}

void copyLine(char new_line[], char original_line[])
{
	int i;

	i = 0;
	while((new_line[i] = original_line[i]) != '\0')
		i++;
}

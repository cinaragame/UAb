#include <stdio.h>

#define MAX_LINE 50

int getLine(char line[], int max_size);
void reverse(char string[]);

int main()
{
	char line[MAX_LINE];

	while(getLine(line, MAX_LINE))
	{
		reverse(line);
		printf("%s\n", line);
	}
}

int getLine(char line[], int max_size)
{
	int i, c;

	i = 0;
	while(i < max_size-1 && (c = getchar()) != EOF && c != '\n')
	{
		line[i] = c;
		i++;
	}	
	if(c == '\n')
	{
		line[i] = c;
		i++;
	}
	line[i] = '\0';

	return i;
}

void reverse(char string[])
{
	int i, c, length;

	length = 0;
	while(string[length] != '\0')
		length++;

	i = 0;
	length--;
	while(i < length)
	{
		c = string[i];
		string[i] = string[length];
		string[length] = c;
		i++;
		length--;
	}
}

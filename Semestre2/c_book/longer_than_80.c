#include <stdio.h>

#define MIN_PRINT_SIZE	80
#define MAX_BUFFER_SIZE	1000

int getLine(char string[], int max_size);

/*
 *	Receives input from stdin, if line longer than 10 characters, prints it back
 */
int main ()
{
	char line[MAX_BUFFER_SIZE];
	int size;

	while((size = getLine(line, MAX_BUFFER_SIZE)) != 0)
		if(size > MIN_PRINT_SIZE)
			printf("Line longer than %d characters detected: %s\n", MIN_PRINT_SIZE, line);
	return 0;
}

/*
 *	Reads input from stdin and stores it in array, up until given size
 *	Parameters: array to receive input
 *				maximum allowed chars
 *	Returns:	line size
 */
int getLine(char string[], int max_size)
{
	int i, c;

	i = 0;
	while(i < max_size-1 && (c = getchar()) != EOF && c != '\n')
	{
		string[i] = c;
		i++;
	}
	/*	if got out of loop because of '\n', now insert it in array
		OBS: there is no need to check for max_size-1 here, getting out because of '\n' means that it first passed the max_size-1 check, so there is at least 2 more spaces in the array (the present i, yet to be filled, and max_size-1: one for this '\n' and one for the '\0'
	*/
	if(c == '\n')
	{
		string[i] = c;
		i++;
	}
	string[i] = '\0';

	return i;
}


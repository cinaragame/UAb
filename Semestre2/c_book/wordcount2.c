#include <stdio.h>

#define IN	1	/*inside word*/
#define OUT	0	/*outside word*/

/*
	Counts char, words and lines in text input
*/
int main()
{
	int c, state;
	long char_cnt, word_cnt, line_cnt;

	state = OUT;
	char_cnt = word_cnt = line_cnt = 0;

	while((c = getchar()) != EOF)
	{
		char_cnt++;

		if(c == '\n')
			line_cnt++;

		if(c == '\n' || c == ' ' || c == '\t')
			state = OUT;
		else if(state == OUT)
		{
			state = IN;
			word_cnt++;
		}

	}
	
	/*Accounting for first line*/
	if(char_cnt != 0)
		line_cnt++;

	/*Print results*/
	printf("\nCharacters: %ld\nWords: %ld\nLines: %ld\n", char_cnt, word_cnt, line_cnt);
}

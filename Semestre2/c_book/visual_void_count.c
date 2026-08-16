#include <stdio.h>

/*
	Counts blanks, tabs and new-line characters in a text input
*/
int main()
{
	int c;
	long blank_cnt, tab_cnt, newline_cnt;

	for(blank_cnt=0, tab_cnt=0, newline_cnt=0; (c = getchar()) != EOF; )
	{
		if(c == ' ')
			blank_cnt++;
		else if(c == '\t')
			tab_cnt++;
		else if(c == '\n')
			newline_cnt++;
		else
			;
	}

	//Print Results
	printf("\nNumber of:\nBlanks: %ld\nTabs: %ld\nNew-lines: %ld\n",
		blank_cnt, tab_cnt, newline_cnt);

}

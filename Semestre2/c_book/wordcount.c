#include <stdio.h>

/*
	Counts words from stdin
*/
int main()
{
	long wc;

	for(wc = 0; getchar() != EOF; wc++)
		;
	printf("Number of words: %ld\n", wc);
}

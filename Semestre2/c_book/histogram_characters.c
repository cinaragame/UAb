#include <stdio.h>

#define CHAR_COUNT		36 // (0-9) + (a-z OR A-Z)
#define NUMBER_DIGITS	10

/*
	Returns 1 int is a digit between 0-9, a-z, A-Z
	Returns 0 otherwise
*/
int is_digit(int c)
{
	if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z'))
		return 1;
	return 0;
}

/*
	Makes a historgram for accounting use of each character in a text
*/
int main()
{

	int word_size[CHAR_COUNT];
	int c;

	//start counters at 0
	for(int i = 0; i < CHAR_COUNT; ++i)
		word_size[i] = 0;
	
	//get text input and count word sizes
	while((c = getchar()) != EOF)
	{
		if(is_digit(c))
		{
			if(c >= '0' && c <= '9')
				word_size[c - '0']++;
			else if (c >= 'A' && c <= 'Z')
				word_size[c - 'A' + NUMBER_DIGITS]++;
			else
				word_size[c - 'a' + NUMBER_DIGITS]++;
		}
	}

	//Print horizontal histogram
	printf("\n\nHistogram of digit use in text:\n\n");
	for(int i = 0; i < CHAR_COUNT; ++i)
	{
		if(i < NUMBER_DIGITS)
			printf("%d ", i);
		else printf("%c ", i - NUMBER_DIGITS + 'A');

		for(int j = 0; j < word_size[i]; ++j)
			putchar('x');
		putchar('\n');
	}
}

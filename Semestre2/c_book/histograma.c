#include <stdio.h>

#define WORD_SIZE	15
#define WORD_IN		1
#define WORD_OUT	0

/*
	Returns value inserted if lower than MAX VALUE, returns MAX VALUE if higher
	Parameters: size (value to return); max_size (MAX VALUE)
*/
int number_threshold(int max_size, int size)
{
	if(size >= max_size)
		return max_size;
	return size;
}

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
	Makes a historgram for the number of characters of the words in a text
*/
int main()
{

	int word_size[WORD_SIZE];
	long word_char_cnt;
	int c, status;

	//start counters at 0
	for(int i = 0; i < WORD_SIZE; ++i)
		word_size[i] = 0;
	word_char_cnt = 0;
	status = WORD_OUT;
	
	//get text input and count word sizes
	while((c = getchar()) != EOF)
	{
		if(is_digit(c))
		{
			if(status == WORD_OUT)
			{
				status = WORD_IN;
				word_char_cnt = 0;
			}
			++word_char_cnt;
		}
		else if(!is_digit(c))
		{
			if(status == WORD_IN)
			{
				status = WORD_OUT;
				word_char_cnt = number_threshold(WORD_SIZE, word_char_cnt);
				++word_size[word_char_cnt - 1];
			}
		}
	}

	//Account for possible last word or only word input
	if(status == WORD_IN)
	{
		word_char_cnt = number_threshold(WORD_SIZE, word_char_cnt);
		++word_size[word_char_cnt - 1];
	}
	
	//Print horizontal histogram
	printf("\n\nHistogram of the number of characters per word:\n\n");
	for(int i = 0; i < WORD_SIZE; ++i)
	{
		if(i == WORD_SIZE - 1)
			printf("%5d+ ", i+1);
		else printf("%5d  ", i+1);

		for(int j = 0; j < word_size[i]; ++j)
			putchar('x');
		putchar('\n');
	}
}

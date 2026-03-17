#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>


int CheckUsage(int n)
{
	if(n < 2)
	{
		printf("Usage: ./palindromos.c text\n");
		return 0;
	}
	return 1;
}

int InputLength(int n_words, char* input)
{
	int n;
	n = 0;

	while(*input != '\0' || n_words > 1)
	{
		if(*input == '\0')
			n_words--;

		n++;
		input++;
	}
	return n;
}

char Normalize(char *c)
{
	switch(c[1])
	{
		case '\200': case '\201': case '\202': case '\203':
			return 'A';
		case '\240': case '\241': case '\242': case '\243':
			return 'a';
		case '\210': case '\211': case '\212':
			return 'E';
		case '\250': case '\251': case '\252':
			return 'e';
		case '\214': case '\215':
			return 'I';
		case '\254': case '\255':
			return 'i';
		case '\222': case '\223': case '\224': case '\225':
			return 'O';
		case '\262': case '\263': case '\264': case '\265':
			return 'o';
		case '\231': case '\232':
			return 'U';
		case '\271': case '\272':
			return 'u';
		case '\207':
			return 'C';
		case '\247':
			return 'c';
	}
	return c[0];
}

char ReturnSimpleChar(char* c)
{
	if(c[0] != '\303')
		return c[0];
	else
		return Normalize(c);
}


int IfLetter(char c)
{
	if(c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
		return 1;
 	
	return 0;
}

int LastWordSize(char *input, int last_char)
{
	int i = 0;
	do
	{
		i++;
		last_char--;
	} while(input[last_char] != '\0' && input[last_char] != ' ');
	return i;
}

void PrintResult(char *input, int first_half, int second_half)
{
	printf("\"");
	while(first_half <= second_half)
	{
		if(input[first_half] == '\0' && first_half == second_half);
		else if(input[first_half] == '\0')
			printf(" ");
		else
			printf("%c", input[first_half]);
		first_half++;
	}
	printf("\"\n");
}

void CheckIfPalindromo(char *input, int first_half, int second_half)
{
	int temp_a = 0;
	int temp_b = 0;
	int c_start = first_half;
	int i = first_half;
	int c_end = second_half;
	int j = second_half;
	int size = second_half - first_half;
	
	for(i = 0; i < j; i += strlen(&input[c_start]))
	{
		c_start = i;
		first_half = i;
		for(j = second_half; j > i; j -= LastWordSize(input, c_end))
		{
			c_end = j;
			second_half = j;
				while(second_half > c_start && first_half < c_end &&
					first_half <= second_half)
				{
					if(first_half == second_half)
						break;
					if(!IfLetter(ReturnSimpleChar(&input[first_half])))
					{
						first_half++;
						continue;
					}
					if(!IfLetter(ReturnSimpleChar(&input[second_half])))
					{
						second_half--;
						continue;
					}
					if(toupper(ReturnSimpleChar(&input[first_half]))
						!= toupper(ReturnSimpleChar(&input[second_half])))
						break;
					first_half++;
					second_half--;
				}
				if(toupper(ReturnSimpleChar(&input[first_half]))
					== toupper(ReturnSimpleChar(&input[second_half])))
					if(temp_b - temp_a < j - i)
					{
						temp_a = i;
						temp_b = j;
					}
		}
	}
	if(temp_a != 0 || temp_b != 0)
		PrintResult(input, temp_a, temp_b);
	else printf("There's no palindrome.\n");
}

int CheckForWord(int length, char* input)

{
	while(length > 0)
	{
		if(IfLetter(input[length]))
			return 1;		
		length--;
	}
	printf("Insert text to check for palindrome.\n");
	return 0;
}

int main (int argc, char* argv[])
{
	setlocale(LC_ALL, "");
	int length;
	int first_half, second_half;

	if(!CheckUsage(argc))
		return 1;
	length = InputLength(argc - 1, argv[1]);
	if(!CheckForWord(length, argv[1]))
		return 1;

	first_half = 0;
	second_half = length -1;

	CheckIfPalindromo(argv[1], first_half, second_half);
}

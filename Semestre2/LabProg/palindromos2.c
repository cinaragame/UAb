/*
This program checks if there are palindromes in a given text - if positive, it gives back the biggest one, writting it on the command line.

The program takes into account only the standard ASCII letters and special Portuguese letters (such as ç). Any other special character, letter, number or punctiation will be ignored by the program, not interfering with its search for palindromes.

Usage: ./palindromes2 lorem ipsum text

Note: Do not use quotes for input
*/

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

int CheckUsage(int n)
{
	if(n < 2)
	{
		printf("Usage: ./palindromos.c lorem ipsum text\n");
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
	if(second_half - first_half == 0)
	{
		printf("There's no palindrome in the text.\n");
		return;
	}
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

void CheckIfPalindromo(char *input, int input_end)
{
	int iteration_start = 0;
	int iteration_end = input_end;
	int i, j;
	int palindrome_start = 0;
	int palindrome_end = 0;

	//iterates word for word in user input up until the middle
	for(iteration_start = 0; iteration_start < input_end; iteration_start += strlen(&input[iteration_start]) + 1)
	{
		//iterates word for word backwards, while number is bigger than the start of the analysis (iteration_start)
		for(iteration_end = input_end; iteration_end > iteration_start; iteration_end += -LastWordSize(input, iteration_end) - 1)
		{
			i = iteration_start;
			j = iteration_end;
			//iterate while letters match
			while(toupper(ReturnSimpleChar(&input[i])) == toupper(ReturnSimpleChar(&input[j])) && i < j)
			{
				i++;
				j--;
				//Check anything that is not an ASCII letter, and skip it
				while(!IfLetter(input[i]) || input [i] == '\0')
					i++;
				while(!IfLetter(input[j]) || input [j] == '\0')
					j--;
			}
			//if i and j have crossed paths, means it's a palindrome
			if(i >= j)
			{
				//printf("Palindrome\n");
				//Store the bigger palindrome start and finish
				if(palindrome_end - palindrome_start < iteration_end - iteration_start)
				{
					palindrome_start = iteration_start;
					palindrome_end = iteration_end;
				}
			}
		}
	}
	PrintResult(input, palindrome_start, palindrome_end);
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

	CheckIfPalindromo(argv[1], second_half);
}

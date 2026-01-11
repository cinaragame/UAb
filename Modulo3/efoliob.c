#include <stdio.h>

typedef struct camara
{
	char *nome[100];
	struct camara *next;
} camara;

enum
{
	INVALIDO,	//0
	CAMARA,		//1
	COMANDO		//2
};

int Parse(char*input);

void Input(void)
{
	char input[100];
	int parse = 0; //check enumerate for return value
	
	scanf("%[^\n]%*c", input);	//pattern match all characters that are not new line
	parse = Parse(input);
	printf("Parse value: %d\n", parse);
}

int Parse(char *input)
{
	//CHECK FOR CAMARA NAME STRUCTURE "# name-name"
	if(*input == '#')
	{
		input++;
		if(*input == ' ')
		{
			input++;
			if((*input >= 'A' && *input <= 'Z')||(*input >= 'a' && *input <= 'z'))
			{
				while((*input >= 'A' && *input <= 'Z') ||
					(*input >= 'a' && *input <= 'z'))
					input++;

				if(*input == '-')
				{
					input++;
					if((*input >= 'A' && *input <= 'Z') ||
						(*input >= 'a' && *input <= 'z'))
					{
						while((*input >= 'A' && *input <= 'Z') ||
							(*input >= 'a' && *input <= 'z'))
							input++;
						if(*input == '\0')
							return CAMARA;
					}
				}
			}
		}
	}
	return INVALIDO;
}

int main()
{
	//ask for input
	Input();
	//parse input
	//add to list OR
	//do command OR
	//end program
}

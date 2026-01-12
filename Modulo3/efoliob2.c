#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct camara
{
	char name[100];
	struct camara *next;
} camara;

enum
{
	INVALIDO,	//0
	CAMARA,		//1
	COMANDO		//2
};

int Parse(char *input);

int Input(char input[])
{
	int parse = 0; //check enumerate for return value
	
	scanf("%[^\n]%*c", input);	//pattern match all characters that are not new line
	parse = Parse(input);
	printf("Parse value: %d\n", parse); //DELETE
	return parse;
}

int CountNodes(camara *pt)
{
	int count = 0;
	if(pt != NULL)
	{
		count = 1;
		while(pt->next != NULL)
		{
			count++;
			pt = pt->next;
		}
	}
	return count;
}

camara *AddNode(char input[], camara *camaras)
{
	camara *new_node = NULL;
	//camara *pt = camaras;
	
	new_node = malloc(sizeof(camara));
	if(new_node == NULL)
		return camaras; //error malloc
	
	input += 2; // skip "# " part
	strcpy(new_node->name, input);
	new_node->next = NULL;

	if(camaras == NULL) //if it is the first node on list
	{
		camaras = new_node;		
	}
	else //add to the end of list
	{
		while(camaras->next != NULL)
			camaras = camaras->next;
		camaras->next = new_node;
	}
	return camaras;
}

int Parse(char input[])
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
	int parse = 0;
	int n_aqualins = 0;
	int n_camaras = 0;
	char input[100];
	camara *camaras = NULL;
	//ask for input

	do
	{
		parse = Input(input);
		if(parse == 1)
			camaras = AddNode(input, camaras);
	} while(parse != 0);
	n_camaras = CountNodes(camaras);

	printf("Aqualins: %d\n", n_aqualins);
	printf("Camaras: %d\n", n_camaras);
	//add to list OR
	//do command OR
	//end program
	//PART 1 AQUALINS AND CAMERAS COUNT
}

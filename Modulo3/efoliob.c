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
	INVALIDO,		//0
	CAMARA,			//1
	RELATORIO,		//2
	IGNORE_COMMAND	//3
};

int Parse(char *input);

int Input(char input[])
{
	int parse = 0; 				//check enumerate for return value
	
	input[0] = '\0';			//reset input
	scanf("%[^\n]%*c", input);	//pattern match all characters that are not new line
	parse = Parse(input);
	printf("Parse value: %d\n", parse); //DELETE
	return parse;
}

void RelatorioGlobal(camara *pt)
{
	int n_aqualins = 0;
	int n_camaras = 0;
	if(pt != NULL)
	{
		n_camaras = 1;
		while(pt->next != NULL)
		{
			n_camaras++;
			pt = pt->next;
		}
	}
	printf("Aqualins: %d\n", n_aqualins);
	printf("Camaras: %d\n", n_camaras);
}

camara *AddNode(char input[], camara *camaras)
{
	camara *pt = NULL;
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
		pt = camaras;
		while(pt->next != NULL)
			pt = pt->next;
		pt->next = new_node;
	}
	return camaras;
}

int Parse(char input[])
{

	//CHECK FOR RELATORIO GLOBAL
	if(strcmp(input, "# relatorio global") == 0)
		return RELATORIO;
	//CHECK FOR "# + 1 to 3 words" OR "# name-name"
	else if(*input == '#')
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
				if(*input == '\0') // checked "# command" format
					return IGNORE_COMMAND;
				else if(*input == '-') // keep checking for "# name-name" format
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
				else if(*input == ' ') // keep checking for "# command command" format
				{
					input++;
					if((*input >= 'A' && *input <= 'Z') ||
						(*input >= 'a' && *input <= 'z'))
					{
						while((*input >= 'A' && *input <= 'Z') ||
							(*input >= 'a' && *input <= 'z'))
							input++;
						if(*input == '\0') // checked for "# command command"
							return IGNORE_COMMAND;
						else if(*input == ' ') //keep checking for "#command command command"
						{
							input++;
							if((*input >= 'A' && *input <= 'Z') ||
								(*input >= 'a' && *input <= 'z'))
							{	
								while((*input >= 'A' && *input <= 'Z') ||
									(*input >= 'a' && *input <= 'z'))
									input++;
								if(*input == '\0') // checked for "# command command"
									return IGNORE_COMMAND;
							}
						}
					}	
				}
			}
		}
	}
	return INVALIDO;
}

int CheckDouble(char input[], camara *camaras)
{
	input +=2;
	while(camaras != NULL)
	{
		if(strcmp(camaras->name, input) == 0)
			return 1;
		camaras = camaras->next;
	}
	return 0;
}

int main()
{
	int parse = 0;
	int n_aqualins = 0;
	int n_camaras = 0;
	char input[100];
	camara *camaras = NULL;

	do
	{
		parse = Input(input);
		if(parse == 1)
		{
			if(CheckDouble(input, camaras) == 0)
				camaras = AddNode(input, camaras);
		}
		else if(parse == 2)
			RelatorioGlobal(camaras);
	} while(parse != 0);
}

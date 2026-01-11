#include <stdio.h>

typedef struct camara
{
	char *name[100];
	struct camara *next;
} camara;

enum
{
	INVALIDO,	//0
	CAMARA,		//1
	COMANDO		//2
};

int Parse(char *input);

void Input(*camara camaras)
{
	char input[100];
	int parse = 0; //check enumerate for return value
	
	scanf("%[^\n]%*c", input);	//pattern match all characters that are not new line
	parse = Parse(input);
	printf("Parse value: %d\n", parse); //DELETE
	if(parse = 1)
		AddNode(input, camaras);
}

camara *AddNode(char *input, camara *camaras)
{
	char c;
	int i = 0;
	camara *aux = NULL;
	camara *new_node = NULL;

	new_node = malloc(sizeof(camara);
	if(new_node == NULL)
		return -1; //error malloc
	
	//write camara name in new node
	while(*input != '\0')
	{
		new_node->name[i] = *input;
		input++;
		i++;
	}
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
	int aqualins = 0;
	camara *camaras = NULL;
	//ask for input
	Input(camaras);
	//parse input
	//add to list OR
	//do command OR
	//end program
	//PART 1 AQUALINS AND CAMERAS COUNT
}

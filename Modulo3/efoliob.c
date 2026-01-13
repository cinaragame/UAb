#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct camara
{
	char name[100];
	struct camara *next;
} camara;

typedef struct aqualin
{
	char name[100];
	long saude;
	long instante;
	struct aqualin *next;
} aqualin;

enum
{
	INVALIDO,		//0
	CAMARA,			//1
	RELATORIO,		//2
	IGNORE_COMMAND,	//3
	OUTRO,			//4
	AQUALIN			//5
};

int Parse(char *input);
int CheckAqualin(char input[]);
int CheckDoubleAqualin(char input[], aqualin *aqualins);

int Input(char input[])
{
	int parse = 0; 				//check enumerate for return value
	
	input[0] = '\0';			//reset input
	scanf("%[^\n]%*c", input);	//pattern match all characters that are not new line
	parse = Parse(input);
	printf("Parse value: %d\n", parse); //DELETE
	return parse;
}

void RelatorioGlobal(aqualin *aqua, camara *cam)
{
	int n_aqualins = 0;
	int n_camaras = 0;
	if(cam != NULL)
	{
		n_camaras = 1;
		while(cam->next != NULL)
		{
			n_camaras++;
			cam = cam->next;
		}
	}
	if(aqua != NULL)
	{
		n_aqualins = 1;
		while(aqua->next != NULL)
		{
			n_aqualins++;
			aqua = aqua->next;
		}
	}
	printf("Aqualins: %d\n", n_aqualins);
	printf("Camaras: %d\n", n_camaras);
}

camara *AddCamara(char input[], camara *camaras)
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

aqualin *AddAqualin(char input[], aqualin *aqualins)
{
	aqualin *pt = NULL;
	aqualin *new_node = NULL;
	int i;
	char aux[100];

	new_node = malloc(sizeof(aqualin));
	if(new_node == NULL)
		return aqualins; //error malloc
	
	input += 2; // skip "# " part
	//COPY JUST NAME
	strcpy(new_node->name, input);
	for(i = 0; i < 100; i++)
	{
		if(new_node->name[i] == ' ')
		{
			new_node->name[i] = '\0';
			break;
		}
	}
	//HEALTH
	i++; //go to start of number
	input += i;
	for(i = 0; i < 100; i++)
	{
		if(input[i] == ' ')
		{
			input[i] = '\0';
			break;
		}
	}
	new_node->saude = atol(input);
	//INSTANTE
	while(*input != '\0')
	{
		input++;
	}
	input++; //ir além do \0
	new_node->instante = atol(input);
	//NEXT ON LIST
	new_node->next = NULL;

	//if it is the first node on list
	if(aqualins == NULL && new_node->saude > 0 && new_node->saude < 100)
	{
		aqualins = new_node;		
	}
	//check for double entry, health, instante and add to the end of list
	else if(CheckDoubleAqualin(new_node->name, aqualins) == 0 &&
		new_node->saude > 0 && new_node->saude < 100)
	{
		pt = aqualins;
		while(pt->next != NULL)
			pt = pt->next;
		if(pt->instante <= new_node->instante) // check for time of entry
			pt->next = new_node;
	}
	return aqualins;
}
int CheckInvalido(char input[])
{
	int letters = 0;

	if(*input != '#')
		return INVALIDO;
	else
	{
		while(*input != '\0')
		{
			if((*input >= 'A' && *input <= 'Z')||(*input >= 'a' && *input <= 'z'))
				return OUTRO;	// segue programa
			input++;
		}
	}
		return INVALIDO;	//encerrar programa
}

int Parse(char input[])
{
	if(CheckInvalido(input) == INVALIDO)
		return INVALIDO;
	//CHECK FOR RELATORIO GLOBAL
	else if(strcmp(input, "# relatorio global") == 0)
		return RELATORIO;
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
						else if(*input == ' ')
							return CheckAqualin(input);
					}
				}
			}
		}
	}
	return IGNORE_COMMAND;
}

int CheckAqualin(char input[])
{
	input++;
	if(*input >= '0' && *input <= '9')
	{
		while(*input >= '0' && *input <= '9')
		{
			input++;
		}
		if(*input == ' ')
		{
			input++;
			while(*input >= '0' && *input <= '9')
			{
				input++;
			}
			if(*input == '\0')
				return AQUALIN;
		}
	}
	return IGNORE_COMMAND;
}

int CheckDoubleCamara(char input[], camara *camaras)
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

int CheckDoubleAqualin(char input[], aqualin *aqualins)
{
	//input +=2;
	while(aqualins != NULL)
	{
		if(strcmp(aqualins->name, input) == 0)
			return 1;
		aqualins = aqualins->next;
	}
	return 0;
}
int main()
{
	int parse = 0;
	char input[100];
	camara *camaras = NULL;
	aqualin *aqualins = NULL;

	do
	{
		parse = Input(input);
		if(parse == CAMARA)
		{
			if(CheckDoubleCamara(input, camaras) == 0)
				camaras = AddCamara(input, camaras);
		}
		else if(parse == AQUALIN)
		{
			if(CheckDoubleAqualin(input, aqualins) == 0)
				aqualins = AddAqualin(input, aqualins);
		}
		else if(parse == RELATORIO)
			RelatorioGlobal(aqualins, camaras);
	} while(parse != INVALIDO);
}

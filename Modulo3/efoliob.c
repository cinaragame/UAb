#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aqualin
{
	char name[100];
	long saude;
	long entry;
	long vida;
	long espera;
	long entrada_camara;
	long alta;
	struct aqualin *next;
} aqualin;

typedef struct paciente
{
	aqualin *patient;
	struct paciente *next;
} paciente;

typedef struct camara
{
	char name[100];
	long time_free;
	paciente *pacientes;
	struct camara *next;
} camara;

enum
{
	INVALIDO,		//0
	CAMARA,			//1
	RELATORIO,		//2
	IGNORE_COMMAND,	//3
	OUTRO,			//4
	AQUALIN,		//5
	TRATAMENTO,		//6
	VIVO,			//7
	MORTO,			//8	
	R_AQUALINS,		//9
	R_CAMARAS,		//10
	I_ESPERA,		//11
	I_TRABALHO,		//12
	I_SALVOS		//13
};

int Parse(char *input);
int CheckAqualin(char input[]);
int CheckDoubleAqualin(char input[], aqualin *aqualins);
void AqualinInCamara(camara *cam, aqualin *aqua);

int Input(char input[])
{
	int parse = 0; 				//check enumerate for return value
	
	input[0] = '\0';			//reset input
	scanf("%[^\n]%*c", input);	//pattern match all characters that are not new line
	parse = Parse(input);
	//printf("Parse value: %d\n", parse); //DELETE
	return parse;
}

void FirstCamFree(camara *cam, aqualin *aqua)
{
	long n;
	camara *first_free = NULL;
	aqualin *pt = aqua;

	if(cam != NULL) //assign first camara values
	{
		n = cam->time_free;
		first_free = cam;
		cam = cam->next;
		while(cam != NULL) //replace values if other cam is free before
		{
			if(cam->time_free < n)
			{
				n = cam->time_free;
				first_free = cam;
			}
			cam = cam->next;
		}
	}
	AqualinInCamara(first_free, aqua);	
}

void AqualinInCamara(camara *cam, aqualin *aqua)
{
	long wait_time = 0;
	long wait_time_update = 0;
	long health_update = aqua->saude; // for tracking health loss
	long i;
	paciente *new_node = NULL;
	paciente *pt;
	//CHECK AQUALIN HEALTH WHEN CAMERA IS FREE
	if (cam->time_free > aqua->entry)
	{
		wait_time = cam->time_free - aqua->entry;
		wait_time_update = wait_time;
		while(wait_time_update != 0)
		{
			if(health_update > 50)
			{
				if(wait_time_update > 1000)
				{
					health_update--;
					wait_time_update -= 1000;
				}
				else break;
			}
			else if(health_update > 20)
			{
				if(wait_time_update > 100)
				{
					health_update--;
					wait_time_update -= 100;
				}
				else break;
			}
			else if(health_update > 10)
			{
				if(wait_time_update > 10)
				{
					health_update--;
					wait_time_update -= 10;
				}
				else break;
			}
			else// WAIT TIME UPDATE > 1 ??????????????????????????
			{
				health_update--;
				wait_time_update--;
			}
		}
	}
	if(health_update <= 0)
	{
		aqua->vida = MORTO;
		aqua->espera = wait_time;
		aqua->alta = (aqua->entry + wait_time);
		if(cam->time_free > aqua->entry)
			aqua->entrada_camara = cam->time_free;
		else
			aqua->entrada_camara = aqua->entry;
		//return;
	}
	//REGISTER AS PATIENT TREATED
	new_node = malloc(sizeof(paciente));
	if(new_node != NULL)
	{
		new_node->patient = aqua;
		new_node->next = NULL;
		pt = cam->pacientes;
		if(cam->pacientes == NULL)
			cam->pacientes = new_node;
		else
		{
			while(pt->next != NULL)
			{
				pt = pt->next;
			}
			pt->next = new_node;
		}
	}

	if(health_update <= 0)
		return;

	aqua->alta = aqua->entry + wait_time;
	while(health_update < 100)
	{
		if(health_update > 50)
		{
			health_update++;
			aqua->alta += 1;
		}
		else if(health_update > 20)
		{
			health_update++;
			aqua->alta += 10;
		}
		else if(health_update > 10)
		{
			health_update++;
			aqua->alta += 100;
		}
		else
		{
			health_update++;
			aqua->alta += 1000;
		}
	}
	aqua->vida = VIVO;
	aqua->espera = wait_time;
	if(cam->time_free > aqua->entry)
		aqua->entrada_camara = cam->time_free;
	else
		aqua->entrada_camara = aqua->entry;
	cam->time_free = aqua->alta;
}

void Mortes(aqualin *aqua)
{
	long n = 0;
	long menor_saude;
	long maior_saude;
	aqualin *pt = aqua;

	while(pt != NULL)
	{
		if(pt->vida == MORTO)
		{
			n++;
			menor_saude = pt->saude;
			maior_saude = pt->saude;
		}
		pt = pt->next;
	}
	while(aqua != NULL)
	{
		if(aqua->vida == MORTO)
		{
			if(aqua->saude < menor_saude)
				menor_saude = aqua->saude;
			if(aqua->saude > maior_saude)
				maior_saude = aqua->saude;
		}
		aqua = aqua->next;
	}
	if(n != 0)
		printf("[Mortes: %ld %ld %ld]\n", n, menor_saude, maior_saude);
}

void Ultimo(aqualin *aqua)
{
	int aux;
	int n;
	aqualin *ultimo;
	aqualin *pt = aqua;

	n = 0;
	while(pt != NULL)
	{
		if(pt->vida == VIVO)
		{
			n++;
			aux = pt->alta;
			ultimo = pt;
			break;
		}
		pt = pt->next;
	}
	
	if(n != 0)
	{
		while(aqua != NULL)
		{
			if(aqua->vida == VIVO && aqua->alta > aux)
			{
				aux = aqua->alta;
				ultimo = aqua;
			}
			aqua = aqua->next;
		}
		printf("- ultima: %s %ld %ld %ld %ld\n", ultimo->name, ultimo->saude,
			ultimo->entry, ultimo->espera, ultimo->alta);
	}
}

void Primeiro(aqualin *aqua)
{
	int aux;
	int n;
	aqualin *primeiro;
	aqualin *pt = aqua;

	n = 0;
	while(pt != NULL)
	{
		if(pt->vida == VIVO)
		{
			n++;
			aux = pt->alta;
			primeiro = pt;
			break;
		}
		pt = pt->next;
	}
	
	if(n != 0)
	{
		while(aqua != NULL)
		{
			if(aqua->vida == VIVO && aqua->alta < aux)
			{
				aux = aqua->alta;
				primeiro = aqua;
			}
			aqua = aqua->next;
		}
		printf("- primeira: %s %ld %ld %ld %ld\n", primeiro->name, primeiro->saude,
			primeiro->entry, primeiro->espera, primeiro->alta);
	}
}

void Restart(aqualin *aqua, camara *cam)
{
	paciente *aux;
	//MARK ALL AQUALIN AS ALIVE
	while(aqua != NULL)
	{
		aqua->vida = VIVO;
		aqua->espera = 0;
		aqua->alta = 0;
		aqua->entrada_camara = 0;
		aqua = aqua->next;
	}
	//MARK ALL CAMARAS AS FREE ON TIC = 0
	while(cam != NULL)
	{
		cam->time_free = 0;
		//FREE ALL PACIENTES
		while(cam->pacientes != NULL)
		{
			aux = cam->pacientes;
			cam->pacientes = cam->pacientes->next;
			free(aux);
		}
		cam->pacientes = NULL;//maybe overkill
		cam = cam->next;
	}
}

void Tratamentos(aqualin *aqua, camara *cam)
{
	aqualin *pt = aqua;

	Restart(aqua, cam);
	while(pt != NULL)
	{
		FirstCamFree(cam, pt);
		pt = pt->next;
	}

	printf("Altas:\n");
	Primeiro(aqua);
	Ultimo(aqua);
	Mortes(aqua);
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
	new_node->pacientes = NULL;
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
	new_node->entry = atol(input);
	//DEFALUT THINGS
	new_node->vida = VIVO;
	new_node->espera = 0;
	new_node->entrada_camara = 0;
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
		if(pt->entry <= new_node->entry) // check for time of entry
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
	//CHECK FOR TRATAMENTOS
	else if(strcmp(input, "# tratamentos") == 0)
		return TRATAMENTO;
	else if(strcmp(input, "# relatorio aqualins") == 0)
		return R_AQUALINS;
	else if(strcmp(input, "# relatorio camaras") == 0)
		return R_CAMARAS;
	else if(strcmp(input, "# indicador espera") == 0)
		return I_ESPERA;
	else if(strcmp(input, "# indicador trabalho") == 0)
		return I_TRABALHO;
	else if(strcmp(input, "# indicador salvos") == 0)
		return I_SALVOS;
	//CHECK FOR CAMARA NAME STRUCTURE "# name-name"
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

void RelatorioAqualins(aqualin *aqua, int tratamentos)
{
	if(tratamentos == 1)
	{
		while(aqua != NULL)
		{
			if(aqua->vida == VIVO)
			{
				printf("%s %ld %ld %ld alta:%ld\n", aqua->name, aqua->saude,
					aqua->entry, aqua->espera, aqua->alta);
			}
			else
			{
				printf("%s %ld %ld %ld morte:%ld\n", aqua->name, aqua->saude,
					aqua->entry, aqua->espera, aqua->alta);
			}
			aqua = aqua->next;
		}
	}
}

void RelatorioCamaras(camara *cam)
{
	paciente *aux;
	while(cam != NULL)
	{
		printf("%s:\n", cam->name);
		aux = cam->pacientes;
		while(aux != NULL)
		{
			printf("- %s %ld %ld %ld\n", aux->patient->name,
				aux->patient->saude,
				aux->patient->entrada_camara,
				aux->patient->alta);
			aux = aux->next;
		}
		cam = cam->next;
	}
}

void IndicadorEspera(aqualin *aqua, int tratamentos)
{
	long n = 0;
	long tempo_total = 0;

	if(tratamentos == 0)
	{
		printf("0\n");
		return;
	}
	while(aqua != NULL)
	{
		n++;
		tempo_total += aqua->espera;
		aqua = aqua->next;
	}
	if(n != 0)
		printf("%ld\n", tempo_total/n);
	else
		printf("0\n");
}

void IndicadorTrabalho(aqualin *aqua, int tratamentos)
{
	long tempo_total = 0;
	if(tratamentos == 0)
	{
		printf("0\n");
		return;
	}
	while(aqua != NULL)
	{
		tempo_total += aqua->alta - aqua->entry;	
		aqua = aqua->next;
	}
	printf("%ld\n", tempo_total);
}

void IndicadorSalvos(aqualin *aqua, int tratamentos)
{
	long n = 0;
	if(tratamentos == 0)
	{
		printf("0\n");
		return;
	}
	while(aqua != NULL)
	{
		if(aqua->vida == VIVO)
			n++;
		aqua = aqua->next;
	}
	printf("%ld\n", n);
}

void FreeAll(aqualin *aqua, camara *cam)
{
	aqualin *aux_aqua;
	camara *aux_cam;
	paciente *aux_pac;

	while(aqua != NULL)
	{
		aux_aqua = aqua;
		aqua = aqua->next;
		free(aux_aqua);
	}
	while(cam != NULL)
	{
		while(cam->pacientes != NULL)
		{
			aux_pac = cam->pacientes;
			cam->pacientes = cam->pacientes->next;
			free(aux_pac);
		}
		aux_cam = cam;
		cam = cam->next;
		free(aux_cam);
	}
}

int main()
{
	int parse = 0;
	int n_tratamentos = 0;
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
		else if(parse == TRATAMENTO)
		{
			n_tratamentos = 1;
			Tratamentos(aqualins, camaras);
		}	
		else if(parse == R_AQUALINS)
			RelatorioAqualins(aqualins, n_tratamentos);
		else if(parse == R_CAMARAS)
			RelatorioCamaras(camaras);
		else if(parse == I_ESPERA)
			IndicadorEspera(aqualins, n_tratamentos);
		else if(parse == I_TRABALHO)
			IndicadorTrabalho(aqualins, n_tratamentos);
		else if(parse == I_SALVOS)
			IndicadorSalvos(aqualins, n_tratamentos);
	} while(parse != INVALIDO);
	FreeAll(aqualins, camaras);
}

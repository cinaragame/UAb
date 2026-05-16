#include <stdio.h>
#include <string.h>
#include "senha.h"

void testar_senha()
{
	int retorno = -1;
	char classe[1];
	char *ptr_nulo = NULL;
	// testar ponteiro nulo
	retorno = classificar_senha(1, ptr_nulo);
	if(retorno != 0)
		printf("Erro: ponteiro = NULL, return %d\n", retorno);
	// testar comprimentos e classificações	
	for(int i = -1; i <= 50; i++)
	{
		retorno = -1;
		classe[0] = '\0';
		retorno = classificar_senha(i, classe);

		if(i < 0)
			if(retorno != 0)
				printf("Erro: comprimento = %d, return %d\n", i, retorno);

		if(i >= 0 && i <= 3)
		{
			if(retorno != 1)
				printf("Erro: comprimento = %d, return = %d\n", i, retorno);
			if(strcmp(classe, "Fraca") != 0)
				printf("Erro: comprimento = %d, classe = %s\n", i, classe);
		}

		if(i >= 4 && i <= 7)
		{
			if(retorno != 1)
				printf("Erro: comprimento = %d, return = %d\n", i, retorno);
			if(strcmp(classe, "Media") != 0)
				printf("Erro: comprimento = %d, classe = %s\n", i, classe);
		}

		if(i >= 8 && i <= 15)
		{
			if(retorno != 1)
				printf("Erro: comprimento = %d, return = %d\n", i, retorno);
			if(strcmp(classe, "Forte") != 0)
				printf("Erro: comprimento = %d, classe = %s\n", i, classe);
		}

		if(i >= 16)
		{
			if(retorno != 1)
				printf("Erro: comprimento = %d, return = %d\n", i, retorno);
			if(strcmp(classe, "Muito Forte") != 0)
				printf("Erro: comprimento = %d, classe = %s\n", i, classe);
		}
	}
}

int main(void)
{
	testar_senha();
	printf("---- TESTE ENCERRADO ----\n");
}



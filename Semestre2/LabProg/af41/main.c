#include <stdio.h>
#include <string.h>
#include "senha_corrigido.h"

void testar_senha()
{
	int retorno = -1;
	char classe[20];
	int tamanho_classe = 20;
	char classe_pequena[1];
	int tamanho_classe_pequena = 1;
	char *ptr_nulo = NULL;

	//testar ponteiro nulo
	printf("Teste ponteiro nulo\n");
	retorno = classificar_senha(1, ptr_nulo, 20);
	if(retorno != 0)
		printf("Erro: ponteiro = NULL, return %d\n", retorno);
	// testar comprimentos e classificações, com buffer de tamanho adequado	
	printf("Teste comprimentos e classificação, buffer adequado\n");
	for(int i = -1; i <= 50; i++)
	{
		retorno = -1;
		classe[0] = '\0';
		retorno = classificar_senha(i, classe, tamanho_classe);

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
	// testar comprimentos e classificações, com buffer de tamanho NÃO adequado	
	printf("Teste comprimentos e classificação, buffer não adequado(pequeno)\n");
	for(int i = -1; i <= 50; i++)
	{
		retorno = -1;
		classe_pequena[0] = '\0';
		retorno = classificar_senha(i, classe_pequena, tamanho_classe_pequena);

		if(i < 0)
			if(retorno != 0)
				printf("Erro: comprimento = %d, return %d\n", i, retorno);

		if(i >= 0 && i <= 3)
		{
			if(retorno != 0)
				printf("Erro: comprimento = %d, return = %d\n", i, retorno);
			if(classe_pequena[0] != '\0')
				printf("Erro: comprimento = %d, classe = %s\n", i, classe_pequena);
		}

		if(i >= 4 && i <= 7)
		{
			if(retorno != 0)
				printf("Erro: comprimento = %d, return = %d\n", i, retorno);
			if(classe_pequena[0] != '\0')
				printf("Erro: comprimento = %d, classe = %s\n", i, classe_pequena);
		}

		if(i >= 8 && i <= 15)
		{
			if(retorno != 0)
				printf("Erro: comprimento = %d, return = %d\n", i, retorno);
			if(classe_pequena[0] != '\0')
				printf("Erro: comprimento = %d, classe = %s\n", i, classe_pequena);
		}

		if(i >= 16)
		{
			if(retorno != 0)
				printf("Erro: comprimento = %d, return = %d\n", i, retorno);
			if(classe_pequena[0] != '\0')
				printf("Erro: comprimento = %d, classe = %s\n", i, classe_pequena);
		}
	}
}

int main(void)
{
	testar_senha();
	printf("---- TESTE ENCERRADO ----\n");
}



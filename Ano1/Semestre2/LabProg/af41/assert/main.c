#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "senha.h"

void testar_senha_assert()
{
	char classe[20];
	char *ptr_nulo = NULL;

	//pointer nulo
	assert(classificar_senha(1, ptr_nulo) == 0);
	//tamanho negativo
	assert(classificar_senha(-1, classe) == 0 && classe[0] == '\0');
	//valores limite válidos	
	classe[0] = '\0';
	assert(classificar_senha(0, classe) == 1);
	assert(strcmp(classe, "Fraca") == 0);
	classe[0] = '\0';
	assert(classificar_senha(3, classe) == 1);
	assert(strcmp(classe, "Fraca") == 0);
	classe[0] = '\0';
	assert(classificar_senha(4, classe) == 1);
	assert(strcmp(classe, "Media") == 0);
	classe[0] = '\0';
	assert(classificar_senha(7, classe) == 1);
	assert(strcmp(classe, "Media") == 0);
	classe[0] = '\0';
	assert(classificar_senha(8, classe) == 1);
	assert(strcmp(classe, "Forte") == 0);
	classe[0] = '\0';
	assert(classificar_senha(15, classe) == 1);
	assert(strcmp(classe, "Forte") == 0);
	classe[0] = '\0';
	assert(classificar_senha(16, classe) == 1);
	assert(strcmp(classe, "Muito Forte") == 0);
	classe[0] = '\0';
	assert(classificar_senha(31, classe) == 1);
	assert(strcmp(classe, "Muito Forte") == 0);
	classe[0] = '\0';
	assert(classificar_senha(50, classe) == 1);
	assert(strcmp(classe, "Muito Forte") == 0);
}

int main(void)
{
	testar_senha_assert();
	printf("---- TESTE ENCERRADO ----\n");
}



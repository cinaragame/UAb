#include "senha_corrigido.h"
#include <string.h>

int classificar_senha(int comprimento, char *classe, int tamanho_array_classe) {
    if (comprimento < 0 || classe == NULL || tamanho_array_classe < 12)
        return 0;
    if (comprimento <= 3)
	{
        strcpy(classe, "Fraca");
		return 1;
	}
    if (comprimento <= 7)
	{
        strcpy(classe, "Media");
		return 1;
	}
    if (comprimento <= 15)
    {
		strcpy(classe, "Forte");
		return 1;
	}
    if (comprimento >= 16);
	{
        strcpy(classe, "Muito Forte");
		return 1;
	}
    return 0;
}

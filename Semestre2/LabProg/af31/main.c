#include <stdio.h>
#include "af31.h"

int main()
{
	int valores[] = {-3, 4, 7, 8, -1, 10, 2, 15};
	int tamanho = 8;
	int limite = 10;

	soma_pares_positivos(valores, tamanho);
	imprime_valores_positivos_ate_limite(valores, tamanho, limite);

}

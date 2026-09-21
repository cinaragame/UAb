/* Programa teste da biblioteca GEOMETRIA_H */

#include <stdio.h>
#include "geometria.h"

int main(void)
{
	/* TESTE ÁREA CIRCULO */
	printf("Teste circulo\n");
	/* Erro */
	printf("Raio -1: área esperada = 0.00, área obtida %.2f\n", areaCirculo(-1));
	/* Limite */
	printf("Raio 0: área esperada = 0.00, área obtida %.2f\n", areaCirculo(0));
	/* Normal */
	printf("Raio 15: área esperada = 706.86, área obtida %.2f\n", areaCirculo(15));

	/* TESTE ÁREA RETÂNGULO */
	printf("Teste retangulo\n");
	/* Erro */
	printf("Base -1, Altura 2: área esperada = 0.00, área obtida %.2f\n", areaRetangulo(-1,2));
	/* Limite */
	printf("Base 0, Altura 0: área esperada = 0.00, área obtida %.2f\n", areaRetangulo(0,0));
	/* Normal */
	printf("Base 12, Altura 16.17: área esperada = 194.04, área obtida %.2f\n", areaRetangulo(12,16.17));
}

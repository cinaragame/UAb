/* PROGRAMA DE DEMONSTRAÇÃO DO MODULO STATS */

#include <stdio.h>
#include "stats.h"

int main(void)
{
	/* Caso erro: divisão por 0 */
	printf("Início: sem números inseridos\nMédia = %.2f\n", calcular_media());
	/* Caso normal: media de dois valores */
	printf("Insere número 10.5\n");
	adicionar_valor(10.5);
	printf("Insere número 20.0\n");
	adicionar_valor(20.0);
	printf("Media esperada = 15.25, média obtida = %.2f\n", calcular_media());
}

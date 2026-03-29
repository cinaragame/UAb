#include <stdio.h>
#include "geometria.h"

int main(void)
{
	int opcao = 0;
	double raio = 0;
	double base = 0;
	double altura = 0;
	do
	{
		/*MENU OPÇÕES*/
		printf("=== MENU ===\n");
		printf("1. Calcular área do círculo\n");
		printf("2. Calcular área do retângulo\n");
		printf("*Insira qualquer outro valor para encerrar*\n");
		printf("Opção: ");
		scanf("%d", &opcao);

		/*OPERAÇÃO*/
		switch(opcao)
		{
			case 1:
				printf("Insira o raio do círculo: ");
				scanf("%lf", &raio);
				printf("Área círculo (r=%.2lf): %.2lf\n", raio, areaCirculo(raio));
				break;
			case 2:
				printf("Insira base e altura do retângulo: ");
				scanf("%lf", &base);
				scanf("%lf", &altura);
				printf("Área retângulo (%.2lfx%.2lf): %.2lf\n", base, altura,
					areaRetangulo(base, altura));
				break;
		}
	}while(opcao == 1 || opcao == 2);
	printf("Programa encerrado\n");
}

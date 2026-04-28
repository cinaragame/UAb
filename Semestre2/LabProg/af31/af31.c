#include "af31.h"

/*
* Função verifica validade de uma array
*
* Parâmetros:
* valores	- array de valores inteiros
* tamanho	- quantidade de elementos na array
*
* Retorno:
* 0			- se array é inválida
* 1			- se array é válida
*
*/

static int validar_array_de_inteiros(const int *valores, int tamanho)
{
	if(valores == NULL || tamanho <= 0)
		return 0;
	return 1;
}

// Função calcula soma dos numeros pares positivos de uma array

static int stt_soma_pares_positivos(const int *valores, int tamanho)
{
	int i;
	int soma = 0;
	// valida parâmetros de entrada
	if(!validar_array_de_inteiros(valores, tamanho))
		return 0;
	for(i = 0; i < tamanho; i++)
	{
		// ignora valores igual a 0 ou negativos
		if(valores[i] == 0)
			continue;
		// soma valores pares
		if(valores[i] % 2 == 0)
			soma += valores[i];
	}
	return soma;
}

void soma_pares_positivos(const int *valores, int tamanho)
{
	int soma = 0;
	soma = stt_soma_pares_positivos(valores, tamanho);
	printf("Resultado: %d\n", soma);
}

// Função imprime valores positivos, se menores que um valor limite

static int stt_imprime_valores_positivos_ate_limite(const int *valores, int tamanho, int limite)
{
	int i;
	int contador = 0;
	// verificar validade da array
	if(!validar_array_de_inteiros(valores, tamanho))
		return 0;
	for(i = 0; i < tamanho; i++)
	{
		// ignorar valores negativos ou zero
		if(valores[i] <= 0)
			continue;
		// imprimir valores até limite
		if(valores[i] <= limite)
		{
			printf("%d ", valores[i]);
			contador++;
		}
	}
	return contador;
}

void imprime_valores_positivos_ate_limite(const int *valores, int tamanho, int limite)
{
	int contador = 0;
	contador = stt_imprime_valores_positivos_ate_limite(valores, tamanho, limite);
	printf("Contagem: %d\n", contador);
}

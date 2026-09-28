/* programa_original.c */
#include <stdio.h>

/* Calcula a soma dos pares positivos */
int SomaPositivos(int *array, int quantidade_numeros)
{
    int i, soma = 0;
    for(i = 0; i < quantidade_numeros; i++)
	{
        if(array[i] > 0 && array[i] % 2 == 0)
		{
            soma += array[i];
        }
    }
    return soma;
}

/* Imprime os valores do array */
int ValoresDeZeroAteLimite(int *array, int quantidade_numeros, int limite)
{
    int i, contador = 0;
	printf("Valores dentro do intervalo definido de 0 a %d: ", limite);
    for(i = 0; i < quantidade_numeros; i++)
	{
        if(array[i] > 0 && array[i] <= limite)
		{
            printf("%d ", array[i]);
            contador++;
        }
    }
	printf("\n");
    return contador;
}

int main()
{
    int valores[] = {-3, 4, 7, 8, -1, 10, 2, 15};
    int soma_positivos = 0;
    int valores_no_intervalo = 0;
	
	soma_positivos = SomaPositivos(valores, 8);
	printf("Resultado soma dos pares positivos: %d\n", soma_positivos);

    valores_no_intervalo = ValoresDeZeroAteLimite(valores, 8, 10);
    printf("Contagem de valores: %d\n", valores_no_intervalo);
    return 0;
}

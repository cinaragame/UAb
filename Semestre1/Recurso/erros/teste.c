#include <stdio.h>

int somaParesPositivos(const int *array, int tamanho)
{
    int i, soma;

    if(tamanho <= 0 || array == NULL)
        return -1;

    i = soma = 0;
    while(i < tamanho)
    {
        soma += array [i];
        i++;
    }
    return soma;
}

int main(void)
{
    int array []= {0, 1, 2};
    int tamanho = 3;

    printf("Teste enviar int pra const int deu: %d\n", somaParesPositivos(array, tamanho));
}

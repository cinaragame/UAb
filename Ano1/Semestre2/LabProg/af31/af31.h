#ifndef AF31_H
#define AF31_H

#include <stdio.h>

/*
* Função calcula soma dos numeros pares positivos de uma array
*
* Parâmetros:
* valores - array de valores inteiros a processar
* tamanho - número de elementos da array
*
* Retorno:
* 0    - se array tiver endereço inválido ou tamanho menor que 1
* soma - soma dos valores pares e positivos da array
*
*/
extern void soma_pares_positivos(const int *valores, int tamanho);

/*
* Função imprime valores positivos, se menores que um valor limite
*
* Parâmetros:
* valores	- array de valores inteiros
* tamanho	- quantidade de elementos na array
* limite	- valor máximo a imprimir
*
* Retorno:
* 0			- se array for inválida
* contador	- quantidade de valores impressos
*
*/
extern void imprime_valores_positivos_ate_limite(const int *valores, int tamanho, int limite);

#endif

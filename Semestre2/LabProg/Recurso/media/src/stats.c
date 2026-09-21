/* IMPLEMENTAÇÃO MÓDULO STATS */

#include "stats.h"

/* Variaveis que mantem valor entre chamadas da função
 * Static mantem encapsulamento das mesmas no modulo
 * (variáveis internas, privadas ao módulo)
 */
static int contador = 0;
static float soma = 0;

/* Adiciona valor @param à variavel 'soma'
 * Incrementa variavel 'contador
 */
void adicionar_valor(float v)
{
	contador ++;
	soma +=v;
}

/* Calcula media com base nos valores existentes nas variaveis
 * 'soma' e 'contador'
 * Guard claus em divisão por 0
 */
float calcular_media()
{
	/* Guard clause de divisão por 0 */
	if(contador == 0)
		return 0;

	return soma/contador;
}

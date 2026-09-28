#include <stdio.h>
#include "stack.h"

#define CAPACIDADE 5

int main(void)
{
	int valor = 0;
	StackPtr stack = NULL;

	/* Criar stack */
	printf("1 - Criar Stack\n");
	if((stack = stack_criar(CAPACIDADE)))
		printf("Stack com capacidade %d criada\n", CAPACIDADE);

	/* Verificar se stack vazia */
	printf("2 - Testar stack se vazia (resposta deve ser sim)\n");
	if(stack_vazia(stack))
		printf("Stack vazia\n");
	else printf("Stack não vazia\n");

	/* Adicionar valor */
	printf("3 - Adicionar valor (20)\n");
	stack_push(stack, 20);

	/* Verificar se stack vazia */
	printf("4 - Testar stack se vazia (resposta deve ser não)\n");
	if(stack_vazia(stack))
		printf("Stack vazia\n");
	else printf("Stack não vazia\n");

	/* Remover e printar valor */
	printf("5 - Remover do topo e printar valor removido (20)\n");
	valor = stack_pop(stack);
	printf("Valor removido: %d\n", valor);

	/* Verificar se stack vazia */
	printf("6 - Testar stack se vazia (resposta deve ser sim)\n");
	if(stack_vazia(stack))
		printf("Stack vazia\n");
	else printf("Stack não vazia\n");

	/* Liberar memória */
	printf("7 - Libertar memória\n");
	stack_destruir(stack);
	stack = NULL;

	return 0;
}

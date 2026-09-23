/* Implementação modulo STACK */

#include <stdio.h>
#include <malloc.h>
#include "stack.h"

static int stt_stack_nula(StackPtr s);

struct Stack
{
	int *dados;
	int topo;
	int capacidade;
};

/* Cria stack com capacidade N */
StackPtr stack_criar(int capacidade)
{
	struct Stack *stack = NULL;
	int *ptr_dados = NULL;

	/* Alocação memoria struct */
	stack = malloc(sizeof(struct Stack));
	/* Guard clause falha alocação de memoria */
	if(!stack)
	{
		printf("[ERRO] Alocação de memória falhou\n");
		return NULL;
	}

	/* Alocação memoria N dados */
	ptr_dados = malloc(capacidade*sizeof(int));
	/* Guard clause falha alocação de memoria*/
	if(!ptr_dados)
	{
		printf("[ERRO] Alocação de memória falhou\n");
		return NULL;
	}
	stack->dados = ptr_dados;	/* Atribui espaço alocado à dados */
	stack->topo = -1;
	stack->capacidade = capacidade;

	return stack;
}

/* Adiciona valor ao topo */
void stack_push(StackPtr s, int valor)
{
	/* Guard clause ptr nulo */
	if(stt_stack_nula(s))
		return;
	/* Guard clause stack cheia */
	if(s->topo >= s->capacidade)
	{
		printf("[ERRO] Stack cheia\n");
		return;
	}
	/* Adicionar dados */
	s->topo++;
	s->dados[s->topo] = valor;
}

/* Retorna 1 com stack vazia, 0 caso contrario */
int stack_vazia(StackPtr s)
{
	/* Guard clause ponteiro nulo */
	if(stt_stack_nula(s))
		return 1;

	if(s->topo < 0)
		return 1;	/* Stack vazio */
	else return 0;	/* Stack com elementos */
}

/* Remove e retona valor do topo */
int stack_pop(StackPtr s)
{
	/* Guard clause ptr nulo */
	if(stt_stack_nula(s))
		return 0;
	/* Guard clause existe dado */
	if(stack_vazia(s))
	{
		printf("Stack vazia\n");
		return 0;
	}
	/* Remover topo */
	s->topo--;
	/* Retorna valor */
	return s->dados[s->topo+1];
}

/* Liberta memoria alocada */
void stack_destruir(StackPtr s)
{
	/* Guard clause stack nula */
	if(stt_stack_nula(s))
		return;
	/* Guard clause dados nulo + free */
	if(s->dados)
	{
		free(s->dados);
		s->dados = NULL;
	}
	free(s);
	s = NULL;
	printf("Memória liberada com sucesso\n");
}

/* Se nulo retorna 1, else retorna 0 */
static int stt_stack_nula(StackPtr s)
{
	if(s == NULL)
	{
		printf("[ERRO] Elemento nulo\n");
		return 1;
	}
	return 0;
}

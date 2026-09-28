#include <stdio.h>
#include <stdlib.h>

unsigned int randaux()
{
  static long seed=1;
  return(((seed = seed * 214013L + 2531011L) >> 16) & 0x7fff);
}

typedef struct node
{
	int n;
	struct node *next;
} Lista;

Lista *Adiciona(Lista *lista, int n)
{
	//create node
	Lista *pt = lista;
	if(pt != NULL)
	{	//enquanto o node para qual pt nao é o ultimo, iterar
		while(pt->next != NULL)
		{
			pt = pt->next;
		}
	}
	Lista *aux = malloc(sizeof(Lista));
	if(aux != NULL)
	{	//adicionar ao final da lista
		(*aux).n = n;
		(*aux).next = NULL; //aux passa a ser o ultimo
		if(pt == NULL)
			return aux; //se for o primeiro elemento da lista
		else
			(*pt).next = aux;	//último passa a apontar para aux
	}

	return lista;
}

int Elementos(Lista *lista)
{
	Lista *pt = lista;
	int counter = 0;
	while(pt != NULL)
	{
		counter++;
		pt = pt->next;
	}
	return counter;
}

void PrintListaInts(Lista *pt, int n, char *texto)
{
	int i = 0;
	printf("%s", texto);
	while(pt != NULL && i < n)
	{
		printf("%d ", pt->n);
		pt = pt->next;
		i++;
	}
	printf("\n");
}

Lista *Remove(Lista *pt)
{
	Lista *aux = NULL;
	if(pt != NULL)
	{
		while(pt != NULL)
		{
			aux = pt;
			pt = pt->next;
			free(aux);
		}	
	}
	free(pt);
	return NULL;
}

int main()
{
    int i, n;
    Lista *lista = NULL;
    scanf("%d",&n);
    /* adicionar 1000 elementos à lista */
    for(i = 0; i < n; i++)
        lista = Adiciona(lista, randaux() % 1000);
    /* retornar os valores pedidos */
    printf("Numero de elementos: %d\n",
        Elementos(lista));
    PrintListaInts(lista, 10, "Elementos: ");
    /* libertar toda a lista antes de sair */
    while(lista != NULL)
        lista = Remove(lista);
}

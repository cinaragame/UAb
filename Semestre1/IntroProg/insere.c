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

Lista *Insere(Lista *lista, int n)
{
	Lista *pt = lista;
	Lista *elemento = malloc(sizeof(Lista));
	if(elemento != NULL)
	{//cria elemento ainda sem ligação à lista		
		(*elemento).n = n;
		(*elemento).next = NULL;
		if(lista == NULL)
			lista = elemento; //se for o primeiro elemento da lista
		else if(lista->n > elemento->n)
		{//se primeiro elemento da lista for maior
			elemento->next = lista;
			lista = elemento;
		}
		else
		{
			while(pt->next != NULL && pt->next->n < elemento->n)
				pt = pt->next;
			elemento->next = pt->next;
			pt->next = elemento;
		}
	}
	return lista;
}

Lista *Apaga(Lista *lista)
{
	Lista *pt = lista;
	Lista *aux;
	while(pt->next != NULL)
	{	//primeiro elemento
		if(lista->n%2 == 0)
		{
			lista = lista->next;
			pt->next = NULL;
			free(pt);
			pt = lista;
		}
		else if(pt->next->n%2 == 0)
		{
			aux = pt->next->next;
			pt->next->next = NULL;
			free(pt->next);
			pt->next = aux;
		}
		else//nao itera antes, para nao pular numeros
			pt = pt->next;
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
        lista = Insere(lista, randaux() % 1000);
    /* retornar os valores pedidos */
    PrintListaInts(lista, 10, "Elementos apos inserir: ");
	//for(i = 0; i < n; i++)
		lista = Apaga(lista);
    printf("Numero de elementos na lista apos apagar: %d\n",
        Elementos(lista));
    PrintListaInts(lista, 10, "Elementos apos apagar: ");
    /* libertar toda a lista antes de sair */
    while(lista != NULL)
        lista = Remove(lista);
}

#include <stdio.h>
#include <stdlib.h>

unsigned int randaux()
{
  static long seed=1;
  return(((seed = seed * 214013L + 2531011L) >> 16) & 0x7fff);
}

typedef struct Lista
{
	int num;
	struct Lista *next;
} Lista;

Lista *Remove(Lista *lista)
{
	Lista *aux = NULL;
	aux = lista;
	lista = lista->next;
	free(aux);
	return lista;
}

Lista *Adiciona(Lista *lista, unsigned int n)
{
	Lista *pt = lista;
	Lista *new_node = NULL;
	new_node = malloc(sizeof(Lista));
	if(new_node == NULL)
		return lista;
	new_node->num = n;
	new_node->next = NULL;
	if(lista == NULL)
	{
		lista = new_node;
		return lista;
	}
	new_node->next = lista;
	lista = new_node;
	return lista;
}

void PrintListaInts(Lista *lista, int n, char *str)
{
	int i;
	printf("%s", str);
	for(i = 0; i < n; i++)
	{
		printf(" %d", lista->num);
		lista = lista->next;
	}
	printf("\n");
}

void PrintWhileSorting(Lista *lista)
{
	printf("Lista:");
	while(lista != NULL)
	{
		printf(" %d", lista->num);
		lista = lista->next;
	}
	printf("\n");
}

Lista *InsertSort(Lista *lista)
{
	int counter = 0;
	Lista *ordered_list = NULL;
	Lista *new_node = NULL;
	Lista *pt = NULL;
	Lista *aux = NULL;
	Lista *free_aux = NULL;

	if(lista == NULL)
		return lista;

	pt = lista;
	while(pt != NULL)
	{
		new_node = malloc(sizeof(Lista));
		if(new_node == NULL)
			return lista;
		//Assign value of present element
		new_node->num = pt->num;
		new_node->next = NULL;
		//If it is the first element to be added in the ordered list
		if(ordered_list == NULL)
		{
			ordered_list = new_node;
			counter++;
		}
		//Else, if it is smaller or equal to the first element on the ordered list
		else if(new_node->num <= ordered_list->num)
		{
			new_node->next = ordered_list;
			ordered_list = new_node;
			counter++;
		}
		//Else, iterate the ordered list while node is bigger than list elements
		else
		{
			aux = ordered_list;
			while(new_node->num >= aux->num)
			{
				if(aux->next == NULL)		//if grater than last element of the list
				{
					aux->next = new_node;
					counter++;
					break;
				}
				else if(aux->next->num >= new_node->num)
				{
					new_node->next = aux->next;
					aux->next = new_node;
					counter++;
					break;
				}
				else
					aux = aux->next;
			}
		}
		if(counter <= 10)
			PrintWhileSorting(ordered_list);
		pt = pt->next;
	}
	while(lista != NULL)
		lista = Remove(lista);
	return ordered_list;
}

int main()
{
    int i, n;
    Lista *lista = NULL;
    scanf("%d",&n);
    for(i = 0; i < n; i++)
        lista = Adiciona(lista, randaux() % 1000);
    PrintListaInts(lista, 10, "Lista nao ordenada:");
    lista = InsertSort(lista);
    PrintListaInts(lista, 10, "Lista ordenada:");
    while(lista != NULL)
        lista = Remove(lista);
}


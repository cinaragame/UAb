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
		pt = pt->next;
	}
	while(lista != NULL)
		lista = Remove(lista);
	return ordered_list;
}

int Valor(Lista *lista, int n)
{
	int i = 1;
	while(i < n && lista != NULL)
	{
		i++;
		lista = lista->next;
	}
	if(lista == NULL)
		return 0;
	else return lista->num;
}

int main()
{
    int i, n;
    Lista *lista = NULL;
    scanf("%d",&n);
    for(i = 0; i < n; i++)
        lista = Adiciona(lista, randaux() % 1000);
    lista = InsertSort(lista);
	printf("elementos 250, 500 e 750: %d %d %d\n",
		Valor(lista, 250),
		Valor(lista, 500),
		Valor(lista, 750));
    while(lista != NULL)
        lista = Remove(lista);
}


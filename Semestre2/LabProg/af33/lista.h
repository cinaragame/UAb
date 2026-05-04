#ifndef LISTA_H
#define LISTA_H

#include "contacto.h"

#define LISTA_MAX 100

/*
* Adiciona um contacto à lista
*
* Retorna:
*	1 se adicionado com sucesso, 0 se a lista está cheia ou contacto inválido
*/
int lista_adicionar(const Contacto *contacto);

/*
* Imprime todos os contactos da lista no ecrã
*/
void lista_mostrarTodos(void);

/*
* Procura contactos cujo nome contenha a string fornecida (pesquisa parcial)
* Imprime os contactos correspondentes
*
* Retorna:
*	Número de contactos encontrados
*/
int lista_procurarPorNome(const char *nome);

/*
* Retorna o número de contactos actualmente na lista
*/
int lista_total(void);

/*
* Copia os contactos da lista para um array externo
*
* Parâmentros:
*	destino	- array de destino
*	max		- capacidade méxima do array de destino
*
* Retorna:
*	Número de contactos copiados
*/
int lista_obterTodos(Contacto destino[], int max);

#endif

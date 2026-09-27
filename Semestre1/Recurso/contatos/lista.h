/* INTERFACE LMODULO LISTA */

#ifndef LISTA_H
#define LISTA_H

typedef struct lista
{
    int index;
    Contato contato;
    struct lista *next;
}Lista;

/* Adiciona novo contacto a lista
 * param: nome lsit, telefone e email
 * retorno: 0 se insucesso
 *          1 se sucesso
 */
int lista_adicionar(char *nome, char *telefone, char *email);

/* Printa lista completa na tela */
void lista_listar(FILE *file);

/* Procura contato com base no nome
 * param: nome
 * return:  0 se insucesso
 *          1 se sucesso
 */
int lista_procurar(char *nome);

#endif /*LISTA_H*/
-------------------------------------------
-------------------------------------------
DEPENDENCIAS:
CONTATO_H

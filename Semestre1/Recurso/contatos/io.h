#ifndef IO_H
#define IO_H

#define IO_FICHEIRO "contato.csv"

/* insere dados de ficheiro em lista
 * param: ficheiro .csv de persistencia definido em macro IO_FICHEIRO
 * return:  1 se sucesso
 *          0 se insucesso
 */
int io_inicializar(FILE IO_FICHEIRO, Lista *lista);

/* grava dados de lista em ficheiro .csv
 * param:   ficheiro onde gravar
 *          lista com os contatos
 * return   1 se sucesso
 *          0 se insucesso
 */
int io_gravar(FILE IO_FICHEIRO, Lista *lista);

#endif /* IO_H */
-------------------------------------------------------------
/* IMPLEMENTAÇÃO */

static char *io_lerFicheiro(FILE IO_FICHEIRO);

static char **split(char *linha);

---------------------------------------------------------------
DEPENDENCIAS
LISTA_H

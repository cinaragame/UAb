/* INTERFACE MODULO CONTATO */

#ifndef CONTATO_H
#define CONTATO_H

/* Struct contato */
typedef struct contato
{
    char nome[50];
    char telefone[10];
    char email[30];
}Contato;

/* Cria contato
 * parametros: nome, telefone e email do contato
 * retorno: NULL se contato inválido,
 *          pointer para contacto se valido
 */
Contato *contato_criar(char *nome, char *telefone, char *email);

#endif /* CONTATO_H */
-------------------------------------------
NENHUMA
-------------------------------------------
DEPENDENCIAS:
NENHUMA

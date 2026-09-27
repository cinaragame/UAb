#ifndef VALIDA_H
#define VALIDA_H

/* valida string com nome
 * param: nome a validar
 * return:  0 se invalido
 *          1 se valido
 *  pre-condicao: max 49 digitos + \0
 */
int valida_nome(char *nome);

/* valida string com telefone
 * param: telefone a validar
 * return:  0 se invalido
 *          1 se valido
 *  pre-condicao: max 9 digitos + \0
 */
int valida_telefone(char *telefone);

/* valida string com email
 * param: email a validar
 * return:  0 se invalido
 *          1 se valido
 *  pre-condicao: max 29 digitos + \0
 */
int valida_email(char *email);

#endif /*VALIDA_H*/

---------------------------------------
/* IMPLEMENTAÇÃO */

/* retorna 1 se todos os char sao digitos, e o c.c. */
static int is_digit(char *string);

/* retorna 1 se encontra arroba, 0 se nao encontra */
static int is_arroba(char *string);

/* retorna 1 se encontra ".com", 0 c.c. */
static int is_dotCom(char *string);
----------------------------------------
DEPENDENCIA: NENHUMA

/* Implementação modulo log */

#include <stdio.h>
#include "log.h"

static int ativo = 1; //inicialmente ativo
static FILE *log_file = NULL; // pointer para um eventual file

/* Escreve mensagem de log na tela, caso estado esteja ativo
 * @param mensagem - mensagem a ser escrita
 */
void Log_msg(const char *mensagem)
{
	if(ativo == 1)
		printf("%s\n", mensagem);
}

/* Escreve mensagem de erro na tela, caso estado seja ativo
 * @param erro - mensagem a ser escrita
 */
void Log_erro(const char *erro)
{
	if(ativo == 1)
		printf("[ERRO] %s\n", erro);
}

/* Altera estado para ativo (1) ou inativo (0)
 * @param estado - aceita apenas 1 ou 0
 */
void Log_ativar(int estado)
{
	if(estado == 0 || estado == 1)
		ativo = estado;
}

/* Regista logs num ficheiro
 * @param filename - nome/localização do ficheiro
 */
void Log_arquivo(const char *filename)
{
	if(log_file)
		fclose(log_file);
	log_file = fopen(filename, "a");
}

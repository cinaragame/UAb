#include <stdio.h>
#include "log.h"

int main(void)
{
	/* Teste log inicial ativo */
	Log_msg("(1)Log inicial ativo: esta mensagem de log deve aparecer\n");
	Log_erro("(2)Log inicial ativo: esta mensagem de erro deve aparecer\n");
	/* Teste log inativo */
	Log_ativar(0);
	Log_msg("Log inativo: esta mensagem de log NAO deve aparecer\n");
	Log_erro("Log inativo: esta mensagem de erro NAO deve aparecer\n");
	/* Teste reativar */
	Log_ativar(1);
	Log_msg("(3)Log reativado: esta mensagem de log deve aparecer\n");
	Log_erro("(4)Log inicial ativo: esta mensagem de erro deve aparecer\n");
	/* Teste numero aleatorio */
	Log_ativar(-32);
	Log_msg("(5)Tentativa de alterar log para -32: deve falhar e esta mensagem de log aparecer\n");
	Log_ativar('d');
	Log_erro("(6)Tentativa de alterar log para 'd': deve falhar e esta mensagem de erro deve aparecer\n");

	return 0;
}

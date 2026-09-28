#include <stdio.h>
#include "pontuacao.h"
#include "tests.h"

int main(void)
{
	printf("---- Início testes de unidade ----\n");
	test_aplicar_bonus();
	test_aplicar_penalizacao();
	printf("---- Fim testes de unidade ----\n");

}

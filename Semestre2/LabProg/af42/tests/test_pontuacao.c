#include <assert.h>
#include "pontuacao.h"
#include "tests.h"

void test_aplicar_bonus()
{
	//entradas validas: inteiros positivos, zero
	//entradas invalidas: inteiros negativos, tipos não inteiros
	//casos limite: zero pontos e 0 bonus
	//possiveis falhas: lidar com numeros não inteiros, aceitar negativos
	
/*	TESTES DESENVOLVIDOS A IGNORAR (explicação no relatorio)
	//testes validos:
	assert(aplicar_bonus(100, 10) == 110);
	//entradas inválidas:
	assert(aplicar_bonus(100, -10) == 100);
	assert(aplicar_bonus(-100, 10) == 90);
	//casos limite:
	assert(aplicar_bonus(100, 0) == 100);
	assert(aplicar_bonus(0, 10) == 0);
	//possiveis falhas
	assert(aplicar_bonus(1, 10) == 1.1);
*/
}

void test_aplicar_penalizacao()
{
	//entradas validas: inteiros positivos, zero
	//entradas invalidas: inteiros negativos, tipos não inteiros
	//casos limite: 0 pontos e 0 penalização
	//possíveis falhas: fazer contas erradas recebendo numeros negativos

/*	TESTES DESENVOLVIDOS A IGNORAR (explicação no relatorio)
	//testes validos
	assert(aplicar_penalizacao(100, 10) == 90);
	//entradas invalidas
	assert(aplicar_penalizacao(-100, 10) == -100);
	assert(aplicar_penalizacao(100, -10) == 90);
	//casos limite
	assert(aplicar_penalizacao(0, 10) == 0);
	assert(aplicar_penalizacao(100, 0) == 100);
	//possiveis falhas
	assert(aplicar_penalizacao(100, 1.5) == 98.5);
*/
}


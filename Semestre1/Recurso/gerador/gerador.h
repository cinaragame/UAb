/* INTERFACE MODULO GERADOR */

#ifndef GERADOR_H
#define GERADOR_H

/* Gera numero inteiro aleatorio com base em semente
 * param: semente
 * return: numeor aleatorio
 */
int gerador_gerarNumero(unsigned int semente);

#endif /* GERADOR_H */


/* IMPLEMENTAÇÃO MODULO GERADOR */

#include "gerador.h"

int gerador_gerarNumero(unsigned int semente)
{
    return random()/semente;
}


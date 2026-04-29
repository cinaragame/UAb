#ifndef GERADOR_H
#define GERADOR_H

/*
// DEFINIR E ALTERAR SEMENTE
// QUANTOS NUMEROS GERADOS
// ÚLTIMO NÚMERO GERADO
?? PRODUZIR NUMEROS ALEATORIOS EM VARIOS FORMATOS
?? VALORES MÁXIMO E MÍNIMO
// REINICIALIZAR ESTADO INTERNO
// CONSULTAR ESTADO ATUAL
// REPRODUTIVEL QUANDO MESMA SEMENTE É UTILIZADA
*/

#include <stdio.h>

extern void generator_set_program_to_state_zero();
extern void generator_set_new_random_number();
extern void generator_print_seed();
extern void generator_print_random_number();
extern void generator_print_counter();

#endif //GERADOR_H

/* modulo_suspeito.h */

#ifndef MODULO_SUSPEITO_H
#define MODULO_SUSPEITO_H

#define MAX_SUSPEITO 100

extern int buffer[];
extern int publica;

/* Comentario explicativo sobre a função*/
void processar(void);

#endif /* MODULO_SUSPEITO */

--------------------------------------------------

/* modulo_suspeito.c */
#include <stdio.h>
#include "modulo_suspeito.h"

int buffer[MAX_SUSPEITO];

static int privada;
int publica;

static void helper(void)
{
	printf("Ajudante\n");
}

void processar(void)
{
	helper();
}


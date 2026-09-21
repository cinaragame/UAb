/* HEADER MÓDULO GEOMETRIA */

#ifndef GEOMETRIA_H
#define GEOMETRIA_H

/* Calcula área de um circulo com base no raio
 * @param:	raio (type double)
 * @return:	0 se raio menor ou igual a 0
 *			area (pi*raio²), caso contrario
 */
double areaCirculo(double raio);

/* Calcular área de um retangulo a partir de base e altura
 * @param:	base (type double)
 *			altura (type double)
 * @return: 0 se base ou altura menor ou igual a 0
 *			area retangulo (type double), cc
 */
double areaRetangulo(double base, double altura);

#endif /* GEOMETRIA_H */

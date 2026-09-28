/* IMPLEMENTAÇÃO GEOMETRIA_H */

#include "geometria.h"

#define PI 3.14159 /* Constante PI */

/* Implementação cálculo área circulo 
 * Verifica raio válido (> 0)
 */
double areaCirculo(double raio)
{
	/* Guard clause para raio negativo ou zero */
	if(raio <= 0)
		return 0;
	/* Retrono área cículo */
	return PI*raio*raio;
}

/* Implementação cálculo área retangulo
 * Verifica base e altura válidos (> 0)
 */
double areaRetangulo(double base, double altura)
{
	/* Guard clause para base ou altura negativos ou zero */
	if(base <= 0 || altura <= 0)
		return 0;
	/* Retorno área retangulo */
	return base*altura;
}

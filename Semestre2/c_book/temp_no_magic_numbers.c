#include <stdio.h>

#define LOWER 		0	//starting point in Fahrenheit
#define HIGHER		300	//ending temp in Fahrenheit
#define INCREASE	20	//temp increase each iteration

/*
	Function prints Fahrenheit(F)-Celsius(C) table
	for fahr = 0, 20, ..., 300
*/
int main()
{
	//Temperature variables
	float fahr, cels;

	//Heading of the table
	printf("Fahrenheit\tCelsius\n");

	//Table
	fahr = LOWER;

	while (fahr <= HIGHER)
	{
		cels = 5.0*(fahr-32.0)/9.0;
		printf("%7.0f\t\t%6.1f\n", fahr, cels);
		fahr += INCREASE;
	}
}

#include <stdio.h>

/*
	Prints temperature conversion table from Fahrenheit to Celsius
	Range: 300, 280, ..., 20, 0 Fahrenheit
*/

int main()
{
	//Fahrenheit variable
	int fahr;

	//Table's head
	printf("Fahrenheit\tCelsius\n");

	//Table
	for (fahr = 300; fahr >= 0; fahr -=20)
	{
		//Third parameter is conversion formula from Fahr to Celsius
		printf("%7d\t\t%6.1f\n", fahr, (5.0/9.0)*(fahr-32.0));
	}
}

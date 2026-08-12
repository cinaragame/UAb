#include <stdio.h>

/*
	Function prints Fahrenheit(F)-Celsius(C) table
	for fahr = 0, 20, ..., 300
*/
int main()
{
	//Temperature variables
	int fahr, cels;
	//Fahr limit variables
	int lower, higher, increase;
	
	lower = 0;		//start temperature
	higher = 300;	//ending temperature
	increase = 20;	//increase size

	fahr = lower;

	while (fahr <= higher)
	{
		cels = 5*(fahr-32)/9;
		printf("%3d\t%3d\n", fahr, cels);
		fahr += increase;
	}
}


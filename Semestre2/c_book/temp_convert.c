#include <stdio.h>

/*
	Converts temperature from Fahrenheit to Celsius
	Input: Fahrenheit (use dot "." for decimal case)
	Output: Celsius with 1 decimal case
*/
int main()
{
	//Temperature variables
	float fahr, cels;

	//Request input from user
	printf("Insert temperature in Fahreheint: ");
	scanf("%f", &fahr);

	//Convert temperature from Fahrenheit to Celsius
	cels = (5.0/9.0)*(fahr-32.0);

	//Output converted number
	printf("%.1f Fahrenheit equals %.1f Celsius\n", fahr, cels);
}

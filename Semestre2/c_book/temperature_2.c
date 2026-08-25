#include <stdio.h>

#define MIN_TEMP    0
#define MAX_TEMP    300
#define STEP_TEMP   20

float fahr_to_cels(float fahr);

/*
 * Prints temperature conversion table fahrenheit-celsius
 * Range in Fahrenheit defined in MACROS:
 *      MIN_TEMP: first Fahrrenheit temperature in table
 *      MAX_TEMP: last Fahrenheit temperature in table
 *      STEP_TEMP: increase in temperature in each line of the table
 */
int main()
{
    float fahr;

    printf("Temperature Conversion Table\n");
    printf("\tFahrenheit\tCelsius\n");
    
    for(fahr = MIN_TEMP; fahr <= MAX_TEMP; fahr += STEP_TEMP)
    {
        printf("\t%5.0f\t\t%5.1f\n", fahr, fahr_to_cels(fahr)); 
    }
}

/*
 *  Converts fahrenheit temperature to celsius
 *  Parameter:  float (fahrenheit)
 *  Return:     float (celsius)
 */
float fahr_to_cels(float fahr)
{
    return (5.0/9.0) * (fahr - 32.0);
}

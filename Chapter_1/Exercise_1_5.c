#include <stdio.h>

/* Modify the temperature conversion program to print
the table in reverse order, that is, from 300 degrees to 0. */

int main()
{
    /*print a Fahrenheit-Celsius table
        for fahr = 0, 20,..,300 */
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Conversion Table\n");
    fahr = upper;
    while( fahr >= lower){
        celsius = (5.0/9.0) * (fahr-32.0);
        /* printf("Conversion: "); */
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr -= step;
    }
    return 0;
}
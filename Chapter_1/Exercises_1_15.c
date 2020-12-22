#include <stdio.h>

float convert_to_celsius(float fahr);

/*test conversion function */
int main(){
    float fahr;
    int lower = 0, upper = 300, step = 20;

    fahr = lower;
    printf("\nFAHR | CELSIUS\n");
    printf("-------------\n");
    while(fahr <= upper){
        printf("%3.0f %6.1f\n", fahr, convert_to_celsius(fahr));
        fahr = fahr + step;
    }
}

/*celsius: convert fahr into celsius */
float convert_to_celsius(float fahr){
    return (5.0/9.0) * (fahr-32.0);
}

/* Intro Problem 1 - Temperature Converter
Jeremy Achong
9-10-21
*/ 

#include <stdio.h>
#include <math.h>

int main(void)
{
    float tempF, tempC;
    
    printf("Enter the temperature in Fahrenheit: ");
    scanf("%f", &tempF);
    /*C = 5/19(F-32) */ 
    tempF = tempF-32.0;
    tempC = 5.0/9.0*tempF;
    printf("The temperature in Celsius is: %f", tempC);

    return 0;

}
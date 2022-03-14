/*
    Jeremy Achong
    10-6-21

        Power Factorial Series

        This program contains a function "factorial()" that takes a positive
        integer as parameter and returns the factorial of that integer. 
        Another functiom, "power()" takes two integers, x and y, then returns
        x^y. multiply x, y number of times. 

*/ 

#include <stdio.h>

#define LIMIT 15 

long long factorial(int x)
{
    //n! = n*[n-1]*n[n-2]
    // n*[n] n*[n-(n-1)] . . .

    long long factorial = 1;
    long long i;
    for (i = 1; i <= x; i++) 
    {
        factorial *= i;
    }
    return factorial;
    //printf("fact: %lld\n", result); 


}

long long power(int x, int y)
{
    long long pow = 1; 


    while(y>0) 
    {
        pow = pow*x;  
        y--;
    }
   

    return pow; 
}

int main(void)
{
    int counter,input; 
    double division; 

    printf("Enter your n:\n");
    scanf("%d", &input); 
    
    int value = input;


    for(counter = 1; counter <= value; counter++)
    {
        division += power(counter, counter)*1.0 / (factorial(counter));
       
    }

    printf("\nSummation of the series from 1 to %d is: %.2lf",input, division);

    return 0; 
}
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
    /* factorial multiples by i, i is decreasing by 1 each time. 
    results in factorial(i) * (i-1) * (i-2)... */
    long long factorial = 1;
    long long i;
    for (i = 1; i <= x; i++) 
    {
        factorial *= i;
    }
    return factorial;
}

long long power(int x, int y)
{
    long long pow = 1; 
    
    /* While the counter is greater than 0, multiple x by 
    itself until y is less than 0, results in x multiped by itself y times */
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
    
    //Ask for user input (integer)
    printf("Enter your n:\n");
    scanf("%d", &input); 

    //The loop starts at one and finishes at the user's n value
    for(counter = 1; counter <= input; counter++)
    {
        //the double division is modified by n amount of times.
        division += power(counter, counter)*1.0 / (factorial(counter));       
    }

    //Prints the n provided by the user and the end result of the modifying loop. 
    printf("\nSummation of the series from 1 to %d is: %.2lf",input, division);

    return 0; 
}
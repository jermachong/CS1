/*
    Jeremy Achong
    10.18.21

        Our Armstrong Number

        This program prints out all Armstrong numbers between 1
        and n where n is user input. 

        Armstrong number: if the sum of cubes of each digit of the number
        is equal to the number itself, then the number is called an Armstrong number. 

        For example, 153 = (1 * 1 * 1 ) + ( 5 * 5* 5 ) + ( 3 * 3 * 3 )

*/

//pre-processor directives 
#include <stdio.h>

//takes a positive integer as a parameter and returns the sum of cube of each digit of the number
int sumDigitCube(int n) 
{
    //digit and sum start at 0
    int digit = 0, sum = 0; 
    //seperate the digits using while loop
    while(n > 0)
    {
        //the last digit of the 'n' is singled, this digit is cubed 
        //n is divided by 10 to move to the next digit.
        digit = n%10; 
        sum += digit * digit * digit; 
        n=n/10; 
    }

    //return the sum result of the loop. 
    return sum; 
    
}

//DRIVER-FUNCTION: take an integer n a iput and gener each number from 1 to n and call the sumDigitCube() function
//based on the returend result, compare it with the value of the generated number and take a decision 
//and print the number if it is armstrong number. 
int main(void)
{
    //n is given by user, i is counter, sum to store the returned sum by sumDigitCube()
    int n, i, sum; 
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("\nThe Armstrong numbers are:\n");

    //loop through every number between 1 and the user given 'n' and call sumDigitCube
    for(i = 1; i <=n ; i++)
    {
        //check every number from i to n. 
        //this reassigns sum to the result of sumDigitCube(i) every time the loop starts. 
        sum = sumDigitCube(i);

        //if the sum equals the value of i, it is printed as an Armstrong number
        if(sum == i)
        {
            printf("%d\n", sum); 
        }
    }

    //end of function
    return 0; 
}
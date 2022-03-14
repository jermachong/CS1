/*
    Jeremy Achong
    9-20-21

        Leap Year **

    this program takes a year and determines if it is a leap year
    or not. 
*/ 

#include <stdio.h>

int main(void){

    int year; 

    //Ask for user input 
    printf("Enter a year: ");
    scanf("%d",&year); 

    //Checks if year is divisble by 400
    if(year%400 == 0) 
    {
        printf("%d is a leap year.");
    }
    //Checks if year is divisble by 4 but NOT divisble by 100
    else if(year%4==0 && year%100!=0) 
    {
        printf("%d is a leap year.",year);
    }
    //If the year doesn't meet the previous two criteria, then it is not a leap year
    else
        printf("%d is not a leap year.",year); 

    return 0; 
}
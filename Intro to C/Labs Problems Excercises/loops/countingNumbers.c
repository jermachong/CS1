/*
    Jeremy Achong
    10-6-21

            Counting Numbers

        This program keeps taking integers until the user enters
        -100. In the end the program displays the count of positve,
        negative, and zeros entered. 

*/ 

#include <stdio.h>

//hardset -100 as the exit number
#define END -100 

int main(void) 
{
    //declare input number, positive number sum, negtive number sum, and zero sun.
    int num,posSum=0,negSum =0,zSum =0; 

    //ask user for num
    printf("Input the number: \n"); 
    scanf("%d\n", &num);

    //if the number is not -100 proceed. 
    while( num != END )
    {
        /* if the number is less than 0, add to negative sum, 
        if the number is more than 0, add to positive sum, otherwise
        add to zero sum */ 
        if(num < 0)
            negSum++; 
        else if(num > 0)
            posSum++;
        else
            zSum++; 

        //assume user will enter another number
        scanf("%d",&num); 
        
    }

    //print out the resulting sums 
    printf("Number of positive numbers: %d\n", posSum);
    printf("Number of Negative numbers: %d\n", negSum);
    printf("Number of Zero: %d", zSum);

    return 0; 
}
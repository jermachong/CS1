/*
    Jeremy Achong
    10-7-21

            Example of Switch Case

        * switch-case statement is a multi-way decision statemnet. 
        * switch statement evaluates the condition expression and tessts it against numerous constant values
        * float and double are not valid values of a switch-case expression
        
        this example prints case 2, 3, and default
*/ 

#include <stdio.h>

int main(void)
{
    int i = 2; 

    switch(i)
    {
        case 1: 
            printf("I am in case 1\n"); 
        case 2:
            printf("I am in case 2\n"); 
        case 3: 
            printf("I am in case 3"); 
        default:
            printf("I am in default \n");
            
    }

    return 0; 
}
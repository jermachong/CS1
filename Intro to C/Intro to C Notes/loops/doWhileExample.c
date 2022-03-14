/*
    Jeremy Achong
    10-5-21

            Do While Loop example 
*/

#include <stdio.h>

/*
    do
    {
        statement 1;
        statement 2;
    } while ( text expression )

*/ 
int main(void) {

    int number = 1; 

    do
    {
        printf(" %d ", number);
        number++; 
    } while( number <= 100 ); 

} 


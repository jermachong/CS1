/*
    Jeremy Achong
    10-5-21

            This program demonstrates multiple initialization for loop
*/

#include <stdio.h>

int main(void) {

    int i,j;

    //for(<init stmt> ; <boolean expression> ; <increment/decrement statement>) 
    for(i = 0, j=0; j<25 ; j++,i--) 
        printf("%d %d",i,j);

    return 0; 
}
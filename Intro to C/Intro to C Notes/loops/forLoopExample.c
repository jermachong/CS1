/*
    Jeremy Achong
    10-5-21

            This program demonstrates the For loop by adding every odd number between 1-99 together
*/

#include <stdio.h>

int main(void) {

    int val;
    int sum = 0; 
    //for(<init stmt> ; <boolean expression> ; <increment/decrement statement>) 
    for(val = 1; val < 100; val +=2)
        sum += val;

    printf("1+3+5+...99=%d\n",sum);
    return 0; 
}
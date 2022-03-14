/*
    jeremy achong
    11.2.21

    pointer exmplp

*/

#include <stdio.h> 

int *a, b,c; 

b = 10; 

a = &b; //a is equal to the address of b 

c = *a; // c = 10 because *a is pointing to b

//if c = *a, then c would print address of b
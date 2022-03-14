/* Intro Problem 2 - Swap
Jeremy Achong
9-10-21
*/ 

#include <stdio.h>
int main(void){

    int a, b, c;
    scanf("%d %d", &a, &b);
    printf("Before swapping, a is %d and b is %d\n", a, b); 
    c = b;
    b = a;
    a = c; 
    printf("After Swapping, a is %d and b is %d", a, b);

    return 0; 
}
/*
    Jeremy Achong
    9-28-21

        Is Even

    Demonstrates building a function within a program
*/

#include <stdio.h>

int is_even(int x);

int main(void)
{
    int a;
    scanf("%d", &a);

    if(is_even(a))
        printf("%d is even\n", a);
    else    
        printf("%d is odd\n", a);
    return 0;
}

int is_even(int x)
{
    int res;
    if(x%2)
        res = 1;
    else    
        res = 0; 
    return res; 
}
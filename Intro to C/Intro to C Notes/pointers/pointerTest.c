/*
    Jeremy Achong
    10.28.21

        Pointers
*/


#include <stdio.h>

int main(void)
{
    int i = 5;
    int j = 6; 

    //declare pointer
    //dereferencing
    int *p = &i; 
    char ch = 'a';

    //%p %u %x

    printf("%p\n", p);
    printf("Addy of i is %p\n", i);
    printf("size of i is %lu\n", sizeof(i));
    printf("value of i is %d", i);

    printf("Addy of ch");
 
    return 0 ; 
}
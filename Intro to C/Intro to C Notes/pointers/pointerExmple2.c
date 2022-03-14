/*
    Jeremy Achong
    11.2.21

        pointer example 2.


*/


#include <stdio.h>

int main(void){

    int *a, b, c; 

    b = 10; 

    a = &b;

    printf("%p\n",a);
    printf("%p\n",&a);
    printf("%p\n",&b);
    
    printf("%d\n",*a);
    printf("%d\n",b);

    c = *a;

    printf("%d\n",c);

    *a = 50; 

    printf("%d\n",b);
    printf("%d\n",*a);




    return 0;  
} 
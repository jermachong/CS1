#include <stdio.h>

int check ( int i ); 
int x = 50; 
int main(void) {

    int i = 45,c;
    c = check(i); 
    printf("%d%d",c,x); 
    return 0;
}

int check (int i )
{
    x = 100;
    int c = 500;
    return c; 
}
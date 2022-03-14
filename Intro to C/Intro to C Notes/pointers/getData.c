/*
    Jeremy Achong
    11.3.21

        Get Data Exmple

*/

#include <stdio.h>

void getData(int *x, int *y)
{
    printf("Enter two numbers: "); 
    scanf("%d %d", x, y);

}

int main(void)
{
    int a,b;
    getData(&a,&b);

    printf("a = %d, b = %d", a,b);

    return 0;
}
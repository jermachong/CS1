/*
    Jeremy Achong
    11.4.21

        Passing Array to Function using pointers

        showcase the different ways you can passthrough 

*/

#include <stdio.h>

void incBy2V1(int a[], int size)
{
    for(int i = 0;  i < size; i++)
        a[i] += 2; 
}

//very common method 
void incBy2V2(int *a, int size)
{
    for(int i = 0;  i < size; i++)
        a[i] += 2;
}

void incBy2V3(int *a, int size)
{
    for(int i = 0; i < size; i++)
        *(a+1) += 2; 
}

void incBy2V4(int *a, int size)
{
    for(int i = 0; i < size; i++)
    {
        *a = *a +2;
        a++; 
    } 
}

void display(int a[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%d",a[i]); 
}

int main(void)
{
    int A[5] = {10,20,30,40,50}; 

    display(A,5); 
    incBy2(A,5); //passing an address thus dereferencing making this possible
    display(A,5); 

    printf("\n"); 

    
}


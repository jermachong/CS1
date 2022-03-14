/*
    Jeremy Achong
    11.4.21

        Thurs Lecture pointers
*/

#include <stdio.h> 

int main(void)
{
    float A[] = {10,20,30,40,50}; 

    //array

    printf("%p\n",A+1); //A is address of A[0]
    printf("%p\n", &A[1]); 

    printf("%f\n",*(A+1)); ///data reference to 20

    for(int i = 0; i < 5; i++)
    {
        printf("i=%d, %x, %f, %f, %f\n",i, A+i, *A+i, *(A+i), A[i] );
    }


    return 0; 
}
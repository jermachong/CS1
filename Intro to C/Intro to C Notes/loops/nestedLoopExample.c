/*
    Jeremy Achong
    10-5-21

        Nested Loop Example

*/ 

#include <stdio.h>


int main(void) {

    int i,j;
    for (i=1; i<3; i++) //outer loop
     { 
        for (j=1; j<=2; j++) // inner loop
        { 
            printf("i = %d, j = %d \n", i,j);           
        }
        printf("==================\n"); 
    } 
}
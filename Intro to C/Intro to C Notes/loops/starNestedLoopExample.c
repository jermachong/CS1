/*
    Jeremy Achong
    10-5-21

        Nested Loop Example

        This program prints * in pyramid formation
*/ 

#include <stdio.h>

int main(void) {

    //int row, col; 
    int n; 
    scanf("%d", &n);
    for (int row=1; row<=n; row++) 
     { 
        for (int col=1; col<=row; col++) 
        { 
            printf("* ");           
        }
        printf("\n"); 
    } 

    for (int row=1; row<=n-1; row++) 
     { 
        for (int col=1; col<=n - row; col++) 
        { 
            printf("* ");           
        }
        printf("\n"); 
    } 
}
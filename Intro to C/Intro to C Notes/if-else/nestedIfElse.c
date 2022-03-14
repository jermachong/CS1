// Nested if-Else
// 9-10-21

#include <stdio.h>
/* A quick example of nested if-else */ 
int main(void)
{
        int i;
        printf("Enter either 5 or 6");
        scanf("%d", &i);
        if(i==5)
            printf("You are good!");
        else 
        {
            if(i==6) 
                printf("you chose the second option!");
            else    
                printf("Why don't you listen?");
        }
}
/*
    Jeremy Achong
    11.3.21

        ctype.h macros

getChar() 
putChar() & others

*/
#include <stdio.h> 
#include <ctype.h>

#define MAX 100

//opposite case function
int main(void)
{
    char name[MAX]; 

    printf("What is your name? "); 
    scanf("%[^\n]s", name); // <---- %s takes in single string no spaces will think input is for
                        // next string

                        // %[^\n]s means string that is not space. 

    printf("Your name is: %s \n", name); 

    printf("\n %c", name[3]); 


    return 0; 
}
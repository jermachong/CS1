/*
    Jeremy Achong
    11.3.21

        ctype.h macros

getChar() 
putChar() & others

*/
#include <stdio.h> 
#include <ctype.h>

//opposite case function
int main(void)
{
    char ch;

    while(ch = getchar() != '0')
    {
        if(isdigit(ch))
            printf("It is a digit"); 
        if(isLower(ch))
        {
            ch = toupper(ch); //convert
            putchar(ch); //print
        }
        else 
        {
            ch = tolower(ch); //convert
            putchar(ch); //print
        }
    }
}
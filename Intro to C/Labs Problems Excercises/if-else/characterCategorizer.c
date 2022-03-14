/* Jeremy Achong 
9-16-21
Character Categorizer
        
        This program tkes any character as input and determines whether the character is a capital letter, a small case, a digital or 
        a symbol. 
*/

#include <stdio.h>
#include <math.h> 

int main(void){
    int position;
    char c; 

    printf("Enter a Character: \n"); //Ask for user input
    scanf("%c", &c);

    if( c >= 'A' && c <= 'Z') //Check if uppercase digit
    {
        position = c - 'A' + 1; //find position of Capital letter
        printf("%c is a capital letter. The letter number is %d in the alphabet.",c, position);

    }
    else if(c >= 'a' && c <= 'z') //Check if undercase digit
    {
        position = c - 'a' + 1; //find position of undercase letter
        printf("%c is a small case letter. The letter number is %d in the alphabet.",c, position); 
    }
    else if(c>= '0' && c <= '9') //check if digit
    { 
        int digit = c - '0'; //char to digit 
        printf("%c is a digit.\n", c); 
                                             //calculation for sqrRoot
        printf("The square root of %c is %.2f", c, sqrt(digit) ); 

    }
    else //anything that isnt a digit and a char is printed
    {
        printf("%c is a special symbol.", c);
    
    }

        


    return 0;
} 
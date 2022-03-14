/*
    Jeremy Achong
    11.17.21

        Easy Problem
        processes input text and gives an output.txt
*/

//pre-processor directives
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>

/*
pre-condition: takes a single character
post-condition: returns true or false based on if the char is a vowel.
*/
int isVowel(char ch)
{
    ch = tolower(ch);
    int status = 0; 

    //switch statement to check for all the vowels
    switch(ch)
    {
    case 'a':
        status = 1; 
        break;
    case 'e':
        status = 1;
        break;
    case 'i':
        status = 1;
        break;
    case 'o':
        status = 1;
        break;
    case 'u':
        status = 1;
        break;
    default:
        status = 0; 
        break;
    }

    //return the status depending on the checks
    return status; 
}

//driver function
int main(void)
{
    //variable declaration
    //file pointers to transverse
    //character, vowel, and digit counters
    FILE *ifp, *ofp; 
    
    int chcount=0, vcount=0, digitcount=0; 
    char x; 

    //open data from input and start writting to output
    ifp = fopen("input.txt", "r"); //reader
    ofp = fopen("output.txt", "w"); //writer
    
    if(ifp == NULL || ofp == NULL)
    {
        printf("unable to open file\n"); 
        exit(1); 
    }

    //iterate through input file
    while(!feof(ifp))
    {
        //get the scanned value
        x = fgetc(ifp); 

        //check for any casualty at the end of the file
        if(x == EOF)
            break;

        //character, vowel, digit counter
        if(x != '\n') //if the character isn't a newline, then it is counted as character
            chcount++; 

        if(isVowel(x)) //call isVowel to check if the char is a vowel
            vcount++;
        
        if(isdigit(x)) //call isdigit to see if the character is a digit
            digitcount++;

        
        //character to uppercase and print to output.txt
        fprintf(ofp, "%c", toupper(x)); 

        //print to console
        printf("%c",x);

        
    }

    //Summary to console
    printf("\nNumber of characters: %d\n", chcount);
    printf("Number of vowels: %d\n",vcount);
    printf("Number of digits: %d", digitcount);

    //close file pointers
    fclose(ofp); 
    fclose(ifp); 
    
    //EOF
    return 0;
}
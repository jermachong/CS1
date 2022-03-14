/*
    Jeremy Achong
    11.16.21

        File Input / Output Intro
*/ 

// fprintf(file_ptr, ctr_str, other_arguments)
// fscanf(file_ptr, ctr_str, other_arguments)

/*
    FILE *fp; delcaration of a file pointer

             name of file - mode of operation
    fp = fopen("input.txt", "r"); function that opens file

*/

/*  
    Modes of Operation

    r - reading 
    w - writing (will replace file if has same name)
    a - appending
    r+ - open a file for read/write. The file must exist
    w+ - create a file for read/write
    a+ - append or create a file for read/write. file is created if does not exist

    many others. 

*/

/*
    Example of checking if file exists. 
    FILE *fp;

    if((fp = fopen("myfile.c","r" ) == NULL)
    {
        printf("Error opening file\n");
        exit(1); 
    }
*/ 

/*
    How to read from an Input File

    fgetc() reads the character from the current pointer position, advances the pointer position
    to the next character and returns the character that is read which is vollected to variable ch. 

    ch = fgetc(fp); 

    ^ requires a loop to read whole file that runs till it hits EOF

*/ 

/*
    Closing a file

    int fclose(FILE *fp);

        a return value of zero signifies a successful operation

*/ 

#include <stdio.h> 
#include <stdlib.h>


int main(void)
{
    FILE *ifp, *ofp; 

    char str[100] = "input.txt"; //this could be used in place. 
                                    //for the first parameter

    ifp = fopen(str, "r");
    ofp = fopen("copy.txt", "w"); 

    if(ifp == NULL || ofp == NULL)
    {
        printf("unable to open file\n"); 
        exit(1); 
    }

    while(1) //alternative condition: !feof(ifp)
    {
        char ch = fgetc(ifp); 
        if(ch == EOF)
            break; 

        fputc(ch, ofp); //write character to output file pointer
                        //the ofp advances automatically 

        printf("%c", ch);
    }

    fclose(ifp); 
    fclose(ofp); 
 
    return 0; 
}
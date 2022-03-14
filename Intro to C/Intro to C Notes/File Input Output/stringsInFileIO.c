/*
    Jeremy Achong
    11.16.21

        fgets() example
        PARAMETERS:
        read a string, n length, file stream
*/ 

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

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

    char line[100]; 

    while(fgets(line, 99, ifp) != NULL) //alternative condition: !feof(ifp)
    {
        line[strcspn(line,"\n")] = '\0'; //if there is a \n replace with \0

        if(strcmp(line, "ahemd") == 0) //search
            printf("\nFound ahmed\n"); 
            
        printf("%s", line);

    }

    fclose(ifp); 
    fclose(ofp); 
 
    return 0; 
}
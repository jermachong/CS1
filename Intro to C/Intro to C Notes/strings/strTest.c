/*
    Jeremy Achong
    11.15.21

        Showcase the use of strstr() function 
        and other string functions. 

        Recorded lecture Substring search and Array of Strings
*/

#include <stdio.h>
#include <string.h>

#define MAXSTR 4
#define MAXLENGTH 41

int main(void)
{
    /*
    char *result; 
    char test[50] = "this is a test string"; 

    result = strstr(test, "test"); 

    printf("%s\n", result); 
    */

   char str[MAXSTR][MAXLENGTH] =
   {
       "white cat", //str[0]
       "black cat", //str[1]
       "red cat", //str[2]
       "cat"//str[3]
   };

   printf("Displaying your strings: \n");

   for(int i = 0; i < MAXSTR; i++)
   {
       printf("String: %s, Length: %lu\n", str[i], strlen(str[i])); 
   }


}
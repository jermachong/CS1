/*
    Jeremy Achong
    11.14.21

        String Sorting and Searching 
        Take a list of names and sort them alphabetically using selection sort
        then search for a string

*/ 

//pre-processor directives
#include <stdio.h>
#include <string.h>
#include <ctype.h> 

//constants
#define MAXSTRINGS 100
#define MAXLENGTH 51 //50+1

/* pre-condition: give array and access size
   post-condition: sorted alphabetically
*/
void selection_sort(char s[MAXSTRINGS][MAXLENGTH], int n)
{
    //variable declaration
    int min_index;
    
    char minStr[MAXLENGTH]; 

    //sorting algorithem
    for(int i = 0; i < n - 1; i++)
    {
        //set minimum index
        min_index = i; 
        //copy element in s[i] to minStr
        strcpy(minStr, s[i]); 
        for(int j = i+1; j < n; j++)
        {
            //compare minStr to s[j]. if the result is positive, minStr is alphabetically greater
            //thus it needs to be changed so that minStr is the lesser letter
            //index is updated as well.
            if(strcmp(minStr,s[j]) > 0)
            {
                //copy s[j] to minStr so that minStr is now the lesser letter (closer to a)
                strcpy(minStr, s[j]);
                min_index = j; 
            }

        }

        //if the min_index has changed otherwise no change
        if(min_index != i)
        {
            //swap the reference at j with the reference at min 
            char temp[MAXLENGTH]; 
            strcpy(temp, s[i]); 
            strcpy(s[i] , s[min_index]); 
            strcpy(s[min_index] , temp); 
        }
    }

}

/* pre-condition: string
   post-condition: entirety of strings transformed to lower case
*/
void str_to_lower(char *s)
{
    for(int i = 0; s[i] != '\0'; i++)
        //strcpy(s[i],tolower(s[i])); 
        s[i] = tolower(s[i]); 
}

//driver function
int main(void)
{
    //declare variables
    int n, i ; 
    char x;
    char names[MAXSTRINGS][MAXLENGTH]; //100 names, 50 characters per name
    
    //ask user for how many names to set loop
    printf("Enter how many names: "); 
    scanf("%d",&n);

    //user inputs names one by one
    for(i = 0; i < n; i++)
    {
        while((x=getchar() != '\n') && x != EOF);

        printf("Name %d: ", i+1); 
        scanf("%[^\n]s", names[i]); //each row is a string
    }

    //convert the strings to lower case so that the search is case in-sensitive
    for(i = 0; i < n; i++)
    {
        str_to_lower(names[i]); 
    }

    //print alphabetically sorted names by calling selection_sort() 
    printf("Sorted Names:\n"); 
    selection_sort(names, n);
    for(i = 0;i < n; i++)
        printf("%s\n", names[i]); 


    //search string declaration
    char key[MAXLENGTH]; 
    printf("\n");
    //search loop & function
    while(1)
    {
        //found status variable declaration
        int flag = 0; 
        while((x=getchar() != '\n') && x != EOF);

        //ask user for a search key
        printf("Enter a search string: "); 
        scanf("%[^\n]s", key);
        str_to_lower(key); //case in-sensitive
 
        if(strcmp(key, "exit") == 0) //exit case
            break; 

        //search function that iterates through name array
        for(i = 0; i<n; i++)
        {
            //using the needle in haystack function, if there is any match the result won't be NULL
            if(strstr(names[i], key) != NULL)
            {
                //print name that the function found a match for
                printf("%s\n", names[i]);

                //signal that match was found
                flag = 1; 
            }
            else if(i == n) //iteration ends without a flag raised
            {
                //reset flag 
                flag = 0; 
            } 
        }
        //case where flag was never raised
        if(flag == 0)
            printf("not found\n"); 

    }
    
    //exit loop
    printf("bye!"); 

    //EOF
    return 0; 
}

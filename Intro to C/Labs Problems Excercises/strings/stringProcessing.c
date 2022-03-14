/*
    Jeremy Achong
    11.10.21

        String Processing

        some utility functions that can be used to process strings.

*/

#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 101 //maximum string length will be 100 + 1 for '\0'

/* Pre-condition: takes a string
   Post-condition: returns the length of the string
*/
int getLength(char s[])
{
    //2 vars to use one fo the counter and one for the size
    int i = 0, size = 0; 

    while (s[i] != '\0')
    {
        size++; 
        i++;
    }

    return size; //size is equal to length + 1 as the exit will happen until the bound is surpassed
    //because you increment and check and not check then increment
}

/* Pre-condition: takes two strings 
   Post-condition: return 1 if both string contains same characters, else return 0
*/
int is_equal(char a[], char b[])
{
    //variables:
    //counter initialized to 0
    int i = 0; 

    //while loop with condition: a[i] == b[i]
        //if conditional (check if a reaches its end || check if b reaches its end)
            //break

        //increment i 
        //end of the while loop

    //conditional to check if a[i] == '\0' && b[i] == '\0'
    while(a[i] == b[i])
    {
        if(a[i] == '\0' || b[i] == '\0')
        break;

        i++; 
    }

    if(a[i] == '\0' && b[i] == '\0')
        return 1;
    else
        return 0; 
    

}

/* Pre-condition: takes two strings 
   Post-condition: copy source stirng to destination string
*/
void str_copy(char dest[], char source[])
{
    /*Very often the students forget to assign 
    '\0' <-- terminating character
    to the end of the dest string. So, make sure you do not forget to do that.
    */

   //variable declaration
   int i = 0; 

    //while loop ot fill the dest array
    while(source[i] != '\0' )
    {
        dest[i] = source[i]; 
        i++;
    }

    //add a terminating character
    //also called null character
    dest[i] = '\0'; 

}

/* Pre-condition: takes reference of two characters
   Post-condition: swaps the two characters
*/
void swap(char *a, char *b)
{
    //variable declaration
    //temporary variable for swap
    char temp; 

    //dereference to get the value at its address and store it in temp
    temp = *a; 
    *a = *b;
    *b = temp; 

}

/* Pre-condition: takes a string
   Post-condition: reverses string
*/
void str_reverse(char str[])
{
    //utlize swap function
    // variables: 
    //set i and len to 0
    int i, len = 0; 

    //call get length and set to len
    len = getLength(str); 

    for(i = 0; i < len / 2; i++)
        swap(&str[i], &str[len -i -1]); //-1 used to exclude the terminating character \0

}
    
/* Pre-condition: takes string
   Post-condition: returns true or false whether the reverse matches the original
*/
int is_palindrome(char s[])
{
   //delcare array of type char
   //call the str_copy 
   //you can add if needed a print to print the copy array to see if it was seeded well
   //call the reverse function: str_reverse

   //conditionals that use is_equal(copy, s) and either retrn1  when is equal returns 1

    char copy[MAX_LENGTH]; 
    str_copy(copy,s); 
    str_reverse(copy); 

    if(is_equal(copy,s))
        return 1; 
    else 
        return 0; 
}

/* Pre-condition: takes string
   Post-condition: updates the first character of each word to uppercase
*/
void capitalize_word(char *str)
{
    //for loop to iterate through the given string
   for(int i = 0 ; str[i] != '\0'; i++)
   {
    if(i==0)
    {
        //check if its lowercase
        if(islower(str[i]))
            str[i] = toupper(str[i]); 
        continue; 
    }
    else if(str[i] == ' ')
    {
        //increment i to access the first letter after the space
        i++;  

        //check if the ltter after the space is lower case then change it to upper case
        if(islower(str[i]))
            str[i] = toupper(str[i]); 
        continue; 
    }
    else //handles any other exception
    {
        // all other uppercase characters should be in ilowercase
        // if(isupper(str[i]))
        // convert str[i] to lowercase 
        
        if(isupper(str[i]))
            str[i] = tolower(str[i]); 
        continue; 
    }

   }
}

//driver function [unchangeable]
int main(void) {

  char s1[MAX_LENGTH];
  char s2[MAX_LENGTH];
  char x;


  printf("Enter a string: ");
  scanf("%[^\n]s", s1);

  while((x=getchar() != '\n') && x != EOF); //loop to discard \n from last input and not to skip the next input

  printf("Enter another string: ");
  scanf("%[^\n]s", s2);


  printf("\nThe length of your first string is %d\n", getLength(s1));
  printf("The length of your second string is %d\n", getLength(s2));

  //conditionals used to compare the stirngs s1 and s2 if they are different or equal 
  //and print the appropriate message
  if(is_equal(s1, s2)==1)
  {
    printf("You entered two equal strings.\n");
  }
  else
  {
    printf("Your strings are different.\n");
  }

  //conditionals used to check if the string s1 is a palindrome and then print the appropriate message
  if(is_palindrome(s1)) //make sure you do not change the string
  {
      printf("%s is a palindrome string\n", s1);
  }
  else
  {
      printf("%s is not a palindrome string\n", s1);

  }
  //fix the capitlization of s1
  //then print the result after calling the capitlize_word function
  capitalize_word(s1);
  printf("Capitalized s1 is %s ", s1);

  //end of main function
  return 0;
}
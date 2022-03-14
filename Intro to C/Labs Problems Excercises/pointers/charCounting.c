/*
    Jeremy Achong
    11.3.21

            Char Counting LAB 11

        Take a set of character input into an array and then 
        display the statistics on how many times the user has entered in a letter in 
        the alphabet and its percentage. 
*/

//pre-processor directives
#include <stdio.h>
#include <ctype.h>

#define MAXCHAR 50

/* Pre-condition: takes empty array, reference to an integer, and a counters array
   Post-conditon: program takes user input for number of characters and updates the counter 
*/
void getData(char arr[], int *n, int counters[26])
{
   /* 
   Note that the array arr will keep all the characters including the characters 
   that are not letters. But, the counter will only track letter counts.
    During this process, upper case letters need to be converted to lower case letter 
    as discussed in the character counting example during the array lecture. 
   */

   //variable declaration 
   int i;
   char ch, x;  

   //prompt user for the number of characters
   printf("How many characters? : ");
   scanf("%d",n); 
    
   
   for(i = 0; i < *n; i++)
   {
      //expression used to flash any new line or enter type character
      while((x = getchar()!='\n') && x!= EOF);

      //ask the user for the character
      printf("Enter character %d: ", i+1); 

      //get valid character and store it in the array at the appropriate index
      arr[i] = getchar(); 

      //conditional used to check for valid letters and switch them to their lowercase format
      //this conditional also checks that the characters scanned are not special characters
      if(arr[i] >= 'A' && arr[i] <= 'Z' || arr[i] >= 'a' && arr[i] <= 'z' )
      {
         arr[i] = tolower(arr[i]); //get character first and set it to lower case then store it back at the right index. 
         counters[arr[i] - 'a']++; //increment the coutnvalue at the appropriate index as intiallly it was set to 0
      }
      
   }
}

/* Pre-condition: takes the counters array 
   Post-conditon: displays the count and percetnage of each letter in the alphabet 
*/
void displayStat(int *c, int total_char)
{
   //for loop used to print the output as expected by the assignment 
   //following the format: Letter countoftheLetter percentageromthetotal

   for(int i = 0; i < 26;  i++)
      printf("%c\t%d\t%.2f\n",'a'+i, c[i], (100.0 * c[i]/total_char)) ; 
   

}

/* Pre-condition: takes reference to two-character variables
   Post-conditon: swaps the two characters
*/
void char_swap(char *x, char *y)
{
   //variable declaration - temporary val
   char temp;
   //to dereference you need to put an asterix before the pointer to get the value it points to 
   temp = *x;
   *x = *y;
   *y = temp; 

}

/* Pre-condition: takes character array and the total number of elements 
   Post-conditon: function reverses, does not print anything. 
*/
void reverse(char a[], int size)
{
   //variable declaration 
   //declare and set last index
   int last_index = size - 1; 

   //nested loop traverses forward and backwards through a given array. 
   for(int i = 0; i < size/2; i ++)
   {
      //do char_swap: char_swap(&a[i], &a[last_index - i])
      char_swap(&a[i], &a[last_index-i]); 
   }
}

/* Pre-condition: takes a character array and its size 
   Post-conditon: displays the array 
*/ 
void displayArr(char *a, int size)
{

   printf("The char array: "); 

   //note: *varname - varname[] 
   int i; 
   for(i = 0; i < size; i++)
      printf("%c ", a[i]);
}

//Driver Function [unchangeable] 
int main(void) {

   //intitalize 
   int counters[26];
   char myArr[MAXCHAR]; //MAXCHAR was hash defined to 50
   int i, total_char;

   //For loop used to set all the elements within the counter array to = 0
   for(i=0; i<26; i++)
       counters[i] = 0;

   //call the getData functoin to gather the data accordingly from the user
   //pass the total_char by reference
   getData(myArr, &total_char, counters);

   //call the display array function to display the array gathered with input from ther user
   displayArr(myArr, total_char);
   printf("\n");

   //display the counter array content 
   displayStat(counters, total_char);

   //reverse myArr by calling the reverse function and the total number of characters
   reverse(myArr, total_char);

   //display the reversed array
   printf("Array reversed.\n");
   displayArr(myArr, total_char);

   return 0;
}
/*
    Jeremy Achong
    10-9-21

            Number Pyramid

        prints a specific pattern of a traingle based on a given input
        At first the program asks the max_value and then it prints the required triangle.
        Then the program will show a menu "Enter 0 to exit or any other digit to continue"
*/ 

#include <stdio.h>

/*
    pre-condition: this function takes in a max_value int
    post-condition: the function prints out a number pyramid with the increasing number order
    then decreasing. 
*/
void print_triangle(int max_value)
{   
    //this loop runs until there are "max_value" number of rows printed. 
    for(int i=1; i<=max_value; i++)
    {   
        //this loop is responsible for creating the spaces to centralize the numbers
         for(int j=1; j<=max_value-i; ++j)
         {
            printf(" ");
         }
         //this loop prints out the number increasing in value
         for(int k = 1; k <= i; k++)
        {
            printf("%d",k);
        }
        //this loop prints out the number in decreasing value
        for(int l = i-1 ; l >= 1 ; l--)
        {
            printf("%d", l); 
        }

        //after the row is finished, go to next line.
        printf("\n");
   }
}

int main(void)
{
    int max_value;
    int choice = 1; 
    int count = 0; 

    //until the user changes choice to 0, this loop runs. 
    while(choice)
    {
        //everytime the user enters this loop, it is counted as a valid pyramid.
        count++; 

        //ask user for a max_value for the pyramid.
        printf("Enter max value: ");
        scanf("%d", &max_value); 

        //call the function to print the pyramid giving it the user input
        print_triangle(max_value); 

        //give the user a chance to exit the loop 
        printf("Enter 0 for exit or any other digit to continue: "); 
        scanf("%d", &choice); 
    }

    //once the loop ends, give the user the amount of pyramids made.
    printf("Total triangle printed: %d", count);

    //end of main function
    return 0; 
}
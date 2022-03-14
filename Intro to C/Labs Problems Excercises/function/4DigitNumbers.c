/*
    Jeremy Achong
    9-29-21

        4 Digit Numbers

    This program demonstrates the use of self-written functions with a program. 

    Functions: 
    isFourDigit(), reverse4Digit(), 
    addSides4Digit(), isPalindrome4Digit(),
*/ 

#include <stdio.h> 

//global variables to use. 
int num, reverse, sum = 0; 

//Function 1: check if user's number is 4 digits long
int isFourDigit(int num)
{
    /*
     if the number is equal to or over 1000 and under
     10,000 then it is four digits.
    */ 
    if(num >= 1000 && num < 10000) {
        return 1;
    }
    else    
        return 0;  
}

//Function 2: attempt to reverse the user's number
int reverse4Digit(int num)
{
    int dig1, dig2, dig3, dig4, dig5, reverseNum = 0; //declare variable
    int numR = num; 

    dig1 = numR%10; //Get remainder and assign it to digit 1
    numR = numR/10; //Shrink num by dividing by 10 

    dig2 = numR%10; //Get remainder and assign to digit 2
    numR = numR/10; 

    dig3 = numR%10; //Get remainder and assign to digit 3
    numR = numR/10;

    dig4 = numR%10; //Get remainder and assign to digit 4
 
    //Sort digits in numerical order, thousands, hundreds, tens and ones place. 
    reverseNum = dig1 * 1000 + dig2 * 100 + dig3 *10 + dig4 * 1;

    //If the digit is a four digit then return the generated reverse number, if not return -1 
    if(isFourDigit(num))
        return reverseNum; 
    else
        return -1; 
}

//Function 3: add the first and last of the user's number's digits together. 
void addSides4Digit(int num)
{
    //Create a digit place for the first and last digit
    //Retrieve these digit placements by finding remainder 
    int num1,num4; 
    num1 = num/1000; 
    num4 = num%10;

    //add first and last number to create sum
    sum = num1 + num4; 
    
    //If it was four digit number, it will print the first and last number sum
    //if not, it prints it was invalid. 
    if(isFourDigit(num))
    printf("\nSum of sides is: %d\n",sum); 
    else 
    printf("Invalid input to calculate sides\n"); 
    
}

//Function 4: if the reversed number is the same as the original input, then palindrome
int isPalindrome4Digit(int num)
{
    //if the reverse digit returned -1, then return -1 as well.
    //if the original num equals the reverse num, then return 1 (true)
    //not not either, return 0 (false)
    if(reverse4Digit(num)== -1)
        return -1;
    else if(num == reverse4Digit(num)) 
        return 1; 
    else
        return 0; 
}

//Main function
int main(void)
{
    //Ask for user input of 4 digit number
    printf("Enter a four digit number:"); 
    scanf("%d",&num); 

    //reverse the user's 4 digit number, if it can be done
    reverse = reverse4Digit(num);
    if(reverse != -1)
    printf("Reverse is: %d", reverse);
    else 
    printf("Invalid to reverse\n"); 

    //call the add side digit function
    addSides4Digit(num); 

    //if the palindrome comes back with true, false, or -1, from reverse4digit 
    //there will be a response. 
    if(isPalindrome4Digit(num) == 1)
    printf("Palindrome");
    else if(isPalindrome4Digit(num) == 0)
    printf("Not palindrome");
    else if(isPalindrome4Digit(num) == -1)
    printf("Invalid input for palindrome checker"); 

}



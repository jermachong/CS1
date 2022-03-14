/* Lab 3 Reverse Number
    Take the input of 5 digits and reverse the number
Jeremy Achong
9-10-21
*/

//pre-processor directives 
#include <stdio.h>

//main function
int main(void){

    int sum, digS, dig1, dig2, dig3, dig4, dig5, reverseNum; //declare variables 
    printf("Enter a five digit number :");
    scanf("%d", &digS); //Wait for input

    dig1 = digS%10; //Get remainder and assign it to digit 1
    digS = digS/10;

    dig2 = digS%10; 
    digS = digS/10; 

    dig3 = digS%10; 
    digS = digS/10;

    dig4 = digS%10; 
    digS = digS/10; 

    dig5 = digS%10; 

 
    reverseNum = dig1 * 10000 + dig2 * 1000 + dig3 *100 + dig4 * 10 + dig5*1;  //multiplies each digit to its "place" in the reversed number, dig1 to the 10,000 place
    sum = dig1 + dig2 + dig3 + dig4 + dig5; //gather sum of digits

    printf(" Reverse Number: %d\n", reverseNum); //print out reversed nymber
    printf("Sum of digits: %d + %d + %d + %d + %d = %d", dig5, dig4, //print sum
                         dig3, dig2, dig1, sum); 

    return 0; 
}
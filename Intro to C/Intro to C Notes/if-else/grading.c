//Grading - Boolean example
// 9-10-21

#include <stdio.h>
int main(void)
{
    int number;
    printf("Enter your total points: ");
    scanf("%d", number);

    //The sequence is NOT important in this logic
    if(number>=90)
        printf("You earned an A");
    if((number<90) && (number>=80))
        printf("You got a B");
    if((number<80 )&& (number>=70))
        printf("You got a C"); 
    if(number<60)
        printf("You failed"); 
    return 0; 
}
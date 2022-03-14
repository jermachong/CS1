
/*
    Jeremy Achong 
    9-21-21

        Multiplication Practice Simulator
        generates two random numbers (max of 12)
        and compares the user's answer to the real answer. 

        rand () % X will give you a random number between 0 and x-1

        time(0) will give you total number of seconds between now and 
        jan 1st 1970


*/ 

#include <stdio.h>
#include <stdlib.h> //where rand function is 
#include <math.h>
#include <time.h>

#define MAX 12

int main(void){

    //Uses time because time is always changing. 
    srand(time(0)); //Send the random number generator (just one time)

    int x, y, actual_answer, user_answer, diff; 
    //Generate our two operands and ask the user for the answer

    //Sets limits from 1 - 12
    x = 1 + rand()%MAX; 
    y = 1 + rand()%MAX; 

    printf("What is %d x %d\n", x, y); 
    scanf("%d,", &user_answer);

    actual_answer = x*y; 
    diff = abs(user_answer-actual_answer);

    if(user_answer>actual_answer)
    {
        printf("Your answer is %d more than the correct answer.\n",diff);
    }
    else if(user_answer<actual_answer)
    {
        printf("Your answer is %d less than the correct answer.\n",diff);
    }
    else
        printf("Your answer is correct!"); 

    return 0; 


}
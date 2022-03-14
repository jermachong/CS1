/*
    Jeremy Achong
    9-23-21

        Game Risk
    
    Simulates a single battle in the game of risk between 2 attacking armies and 2 defending armies.
    *Each team rolls two dice
    *Compare the highest rolls of the two teams.
    *If the attacker's value is higher, then they defeat the corresponding defending army.
    *Now compare the lowest rolls of the two teams.
    *Once again, if the attacker's value is higher, then they defeat the corresponding defending army.
*/


#include <stdio.h>
#include <math.h>
#include <time.h>

//6 sided dice 
#define MAX 6

int main(void){

    int aRoll1, aRoll2, dRoll1, dRoll2, temp, sumA, sumD = 0;


    //Random num generator 
    srand(time(0));

    //Set bounds for rolls
    aRoll1 = 1 + rand()%MAX;
    aRoll2 = 1 + rand()%MAX;
    dRoll1 = 1 + rand()%MAX;
    dRoll2 = 1 + rand()%MAX;

    //Make sure the rolls are not the same as opponent 
    if(aRoll1 == dRoll1)
    {
        aRoll1 = 1 + rand()%MAX;
        dRoll1 = 1 + rand()%MAX;
    }

     if(aRoll2 == dRoll2)
    {
        aRoll2 = 1 + rand()%MAX;
        dRoll2 = 1 + rand()%MAX;
    }


    //Tell user what the results of random num are for rolls 
    printf("The attackers rolls are %d and %d\n", aRoll1, aRoll2);
    printf("The defenders rolls are %d and %d\n", dRoll1, dRoll2);

    //Sort first and second rolls
    if(aRoll1 < aRoll2)
    {
        temp = aRoll1;
        aRoll1 = aRoll2;
        aRoll2 = temp; 
        
    }

    if(dRoll1 < dRoll2)
    {
        temp = dRoll1;
        dRoll1 = dRoll2;
        dRoll2 = temp; 

    }

    //Calculate points if A has higher first roll
    if(aRoll1>dRoll1)
        sumA++;
    else 
        sumD++; 

    //Calculate points if A has higher second roll
    if(aRoll2>dRoll2)
        sumA++;
    else 
        sumD++; 

        //Display winnings
        if(sumA > 0)
        printf("The attackers killed %d armies\n", sumA);
        if(sumD > 0)
        printf("The defenders killed %d armies", sumD); 

    

    return 0; 
}

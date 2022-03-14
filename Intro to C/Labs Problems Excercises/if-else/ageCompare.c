/*
    Jeremy Achong 
    9-20-21

        Age Comparison

        this program takes the ages of 3 people and determines the youngest
            *assuming none have the same age. 
*/

#include <stdio.h> 

int main(void){

    int p1,p2,p3; 

    //Asks users for the ages of three people
    printf("Enter ages of three people (person 1, person 2, and person 3): "); 
    scanf("%d %d %d", &p1,&p2,&p3); 

    //Checks if Person 1 is younger than person1 and person3
    if(p1 < p2 && p1 < p3) 
    {
        printf("Person 1 is youngest");

    }
    //Checks if Person 2 is younger than person1 and person 3
    else if(p2 < p1 && p2 < p3)
    {
        printf("Person 2 is youngest"); 

    }
    //If neither person 1 or 2 are younger than 3, thus person 3 is youngest.
    else
    {
        printf("Person 3 is youngest"); 

    }

    return 0; 

} 
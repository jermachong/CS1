/*
    Jeremy Achong
    9-24-21

        Random Range Checker

    This program takes coordinates [a,b] of the center of a circle
    and its radius as input

    Then the program determines whether the random point lies
    Inside, Outside, or on the circle
    
    the program utlizes functions: rand(). srand(). 
        sqrt(). and pow(). 
*/


//Including time to generate a random number
//stdlib holds rand() function
//math holds power and square root functions
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void) {

    //Random number generator based off time
    srand(time(0));

    /*a = x1 coordinate 
      b = y1 coordinate 
      xr = random x coordinate
      yr = random y coordinate 
      d = distance
    */

    int a, b, r, xr, yr, d;

    //Ask user for coordinate and radius to develop circle 
    printf("Enter Center x,y coordinate and radius \n"); 
    scanf("%d %d %d", &a, &b, &r); 

    //Generate random coordinates 
    xr = 1 + rand()%(a+r+3); 
    yr = 1 + rand()%(b+r+3);

    printf("The generated coordinate is: (%d, %d)\n",xr,yr);

    //distance formula  d = sqrt(pow((x1-x2),2)+pow((y1-y2),2)); 
    //calculate distance
    d = sqrt(pow(xr-a,2)+pow(yr-b,2)); 

    //find where the coordinate is in relation to the circle. 
    if(d < r)
    {
    printf("Point is inside circle"); 
    }
    else if(d > r)
    {
    printf("Point is outside circle");
    }
    else
    {
    printf("Point is on the circle"); 
    }

    return 0; 
}
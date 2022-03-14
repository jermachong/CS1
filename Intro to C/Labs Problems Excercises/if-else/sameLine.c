/*
    Jeremy Achong
    9-20-21

            Same Line?

        This program takes three coordinate points as input and checks 
        to see if they fall on one straight line. 

        

*/ 

#include <stdio.h>
#include <math.h> 

int main(void){

    float x1,x2,x3,y1,y2,y3,line1,line2;  

    //Ask user for three coordinates
    printf("Enter coordinates (x1, y1): ");
    scanf("%f %f",&x1,&y1);

    printf("\nEnter coordinates (x2, y2): ");
    scanf("%f %f",&x2,&y2);

    printf("\nEnter coordinates (x3, y3): ");
    scanf("%f %f",&x3,&y3);

    //Calculate First and Second lines using formula
        line1 = (y2-y1)/(x2-x1); 
        line2 = (y3-y1)/(x3-x1);

        //calcualte difference and function turns it to abosulute value 
        float diff = fabsf(line1-line2); 


    //if the difference is under 0.000001, it is acceptable as being on the same line. 
    if(diff <= 0.000001 )  
    {
        printf("\nThey fall on one straight line");

    }
    //if the difference is greater than 0.000001, then it is not the same line. 
    else 
    {
        printf("\nThey do not fall on one straight line"); 
    }
    
    return 0; 


}
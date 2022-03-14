/*
    Jeremy Achong
    10.25.21

        Lab Exam

*/ 
/*
    Jeremy Achong
    10.25.21
        Lab Exam
*/

#include <stdio.h>
#include <math.h> 

float slope_calculator(float x1, float x2, float y1, float y2)
{
    // y2-y1 / x2-x1 to the power of 3 
    return pow( (y2-y1) / (x2-x2) , 3);
}

int main()
{
    float x1,x2,y1,y2; 
    float sum=0.0; 
    float counter=0.0; 

    while(1)
    {
        printf("Point 1 (x1 y1): ");
        scanf("%d %d", &x1, &y1);
        printf("Point 1 (x2 y2): ");
        scanf("%d %d", &x2, &y2);
        if(x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0 )
            break; 
        float result = slope_calculator(x1, x2, y1, y2); 
        printf("%.03f ", result); 
        
        counter++; 
    
    }
    
    printf("Avereage strange slope: %.3f", sum/counter);
    
    return 0;
}
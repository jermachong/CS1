/* 
    Jeremy Achong
    9-21-21
            Distance Calculator

        takes coordinates and finds their distance.
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
double x1,y1, x2,y2;
printf("Enter point 1");
scanf("%lf %lf", &x1, &y2);

printf("Enter point 2");
scanf("%lf %lf", &x2, &y2);

double diffx = x1 - x2; 
double diffy = y1 - y2; 
double diffx_sqr = pow(diffx, 2);
double diffy_sqr = pow(diffy, 2);
double distance = sqrt(diffx_sqr + diffy_sqr);

printf("The distance is %.3lf \n ", distance); 

return 0; 
}
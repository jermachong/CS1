/*
    Jeremy Achong
    11.4.21

        Driving My Car

        This function updates the odometer and fuel guage of a car,
        by taking in a reference. 

*/ 

#include <stdio.h>

/* Pre-condition: user inputs odometer and fuel amt. then the miles per gallon and distance
   Post-condition: the odometer and fuel gauges are updated. 
*/
void drive(double *odomPtr, double *fuelPtr, double mpg, double distance)
{
    //ADjust distToDrive, if necessary 
    double maxDrive = (*fuelPtr)*mpg; 
    if(distance > maxDrive)
        distance = maxDrive; 
        
    //calculates to update the gauges 
    *odomPtr += distance; //adding the dsitance to the existing amount of miles

    *fuelPtr -= distance / mpg;  //distnace / mpg = amount of fuel used, this is subtracted from the fuel gauge
}

//Driver function
int main(void)
{
    //variable declaration
    double distance, odom, fuel, mpg;

    //initial guauge readings at startup
    printf("Enter odometer reading, fuel gauge reading and mpg: ");
    scanf("%lf%lf%lf", &odom, &fuel, &mpg); 

    //if the fuel input is invalid or the gas runs out, the loop breaks. 
    while(fuel > 0.0) 
    {
    //ask user for distance to be driven
    printf("Enter the distance you want to drive: ");
    scanf("%lf", &distance);

    //call drive function to update gauges.
    drive(&odom,&fuel,mpg,distance);  

        //if the fuel is negative, set to zero and end program. 
        if(fuel < 0.0)
        {
            fuel = 0.0; 
            printf("Current reading odometer = %.2lf, fuel = %.2lf\n", odom, fuel); 
            printf("\nNo more fuel!"); 
            break; 
        }
        else
            printf("Current reading odometer = %.2lf, fuel = %.2lf\n", odom, fuel); 
    } 

    return 0; 
}
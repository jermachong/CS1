/*
    Jeremy Achong
    10-9-21

            Tip Chart
        This program keeps taking the minimum price adn the maximum price values of meal
        and prints a tip chart with teh range of min and max price. If the user input a negative
        number the pgoram sotps. 
*/ 

#include <stdio.h>

//make TIP_Rate constant 
#define TIP_RATE 0.10

/* 
pre-condition: user inputs a minimum and maximum price
post-condition: the function prints a tip amount based off the price 
                and add toward a valid tip chart counter. 
*/
void printTipChart(int min_price, int max_price)
{
    double tipAmount; 

    //Start with minimum price and repeat till max price.
    for(min_price; min_price <= max_price; min_price++ )
    {
            //calculate tip by rate times minimum price
        tipAmount = TIP_RATE*min_price; 

        //give suggested tip
        printf("On a meal of $%d, the suggested tip amount $%0.2lf\n",min_price, tipAmount ); 
     }
        
}

int main(void)
{
    int chartCount = 0; 
    int min_price, max_price; 
    //Ask for user input
    printf("Enter the minimum and maximum meal values: ");
    scanf("%d %d",&min_price,&max_price); 
   
    while(min_price > 0 && max_price > 0)
    {
        //if the min and max price are valid, increase chart count
        if(min_price <= max_price)
            chartCount++; 

        //call function until a negative number is given by the user.
        printTipChart(min_price,max_price); 

        //keep asking for new input 
        printf("Enter the minimum and maximum meal values: ");
        scanf("%d %d",&min_price,&max_price); 
    } 

    //Give user total valid charts
    printf("You have printed total %d valid charts", chartCount);

    //End of main function
    return 0; 
}
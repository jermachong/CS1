/* Jeremy Achong
9/20/21

    Profit or Loss?

    this program takes the cost of price and selling price of an item
    the program will determine if the seller has made a profit or loss
    the pgoram does nothing if there is no profit or no loss
*/

#include <stdio.h>

int main(void){

    float cPrice, price, diff; //cost price, selling price, difference

    printf("Enter the cost price and selling price: \n"); 
    scanf("%f %f", &cPrice, &price); 
    //calculates difference between selling and cost price
    diff = price - cPrice; 
    
    //Checks if the differnece is positive 
    if(diff > 0) 
    {
        
        printf("You made a profit.\n");
        printf("The amount of profit is $%.2f", diff); 


    }
    //Checks if the differnece is negative 
    else if(diff < 0) 
    {
        float loss = diff * -1; //take out negative symbol for print line. 
        printf("You incurred loss.\n");
        printf("The amount of loss is $%.2f", loss);        
    }
     //end program if there is no net gain/loss
    else if(price == cPrice)
    {
        return 0; 
    }
    
    
    return 0; 
}

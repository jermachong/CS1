//Sales Tax
//9-10-21

#include <stdio.h>
#define TAXRATE .07 
int main(void){
    double price;
    int isTaxed;

    //Get item's price
    printf("What is the price of the item you are buying?\n");
    scanf("%lf", &price);
    //And whether it's taxed or not. 
    printf("Is it a taxed item? (1=yes, 0=no)\n");
    scanf("%d", &isTaxed);
    //We could also do isTaxed == 1, but 1 itself counts as true.
    if(isTaxed)
        price = price + price*TAXRATE;
    //Print out total
    printf("Your final total is $%.2lf\n", price);
    return 0;
}
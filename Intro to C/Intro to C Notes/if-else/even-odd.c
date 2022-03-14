//Even Odd 
// 9-10-21

#include <stdio.h>
int main(void){
    int number;
    printf("Enter an integer:");
    scanf("%d", &number);
    /*True if the number is perfectly divisble by 2
    */
   if(number % 2 == 0)
        printf("%d is even,", number);
    else
        printf("%d is odd", number);
    return 0;
}
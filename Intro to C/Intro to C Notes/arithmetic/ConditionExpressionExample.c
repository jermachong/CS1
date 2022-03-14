//Condition Expression Example
//9/9/21

#include <stdio.h>

int main(void){

    char ch;
    int x,y;
    ch = 'j';
    x = 6*2; //x is now 12
    y = 3*x - 10%x; //y is now 36 - 10 = 26


    printf("x= %d y=%d \n", x, y );  
    printf("x+y > 40 is %d\n",x+y>40); //38 > 40? 
    printf("ch=='k' is %d\n", ch=='k'); //ch is acutally 'j'
    printf("(x-y) != ((7*(3-x%7)) is %d",(x-y) != (7*(3-x%7))); //-14 != -14? 
    
    return 0; 
}
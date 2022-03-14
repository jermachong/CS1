/*
    Jeremy Achong
    9-28-21

                Swap
                Need points to solve this 
*/ 

//void swap(int x, int y);
#include <stdio.h>


void swap(int x, int y){
    int temp = x; 
    x = y; 
    y = temp; 
}

int main(void){

    int x, y = 0; 
    printf("Enter x and y\n");
    scanf("%d %d", &x, &y); 
    printf("X is %d, Y is %d\n", x, y); 

    swap(x,y); 
    
    printf("X is %d, Y is %d",x,y); 

    return 0; 
}



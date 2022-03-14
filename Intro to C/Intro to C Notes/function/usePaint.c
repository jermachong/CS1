#include <stdio.h>

void paint(int c); 

int main(void){
    int c;

    printf("Enter choice of color 1 = white or 2 = green.");
    scanf("%d",&c);
    printf("Calling the painter\n");
    paint(c); 
    //reutnred from the function
    printf("Enter home!\n");

    return 0; 
} 
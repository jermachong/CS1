#include <stdio.h>

//this function returns nothing, takes an int

void paint(int color)
{
    if(color == 1)
        printf("Painting with White color\n");
    else if(color == 2)
        printf("Painting with green color\n");
    else    
        printf("Please choose a valid color wihite or green\n");

    printf("painter is returning\n"); 
}
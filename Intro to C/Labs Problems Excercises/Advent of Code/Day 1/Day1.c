/*
    Jeremy Achong
    12.1.21 
            Advent of Code Day 1
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>


int main(void)
{
    FILE *ifp;
    int numbers[2000]; 
    //int numbers3[2000][3]; 
    int sums[1000] = {0}; 
    int x, y, count = 0; 

    ifp = fopen("input.txt", "r"); //File reader

   //iterate through list 
    for(int i = 0; i < 2000; i++)
    {   
        //scan # and store into number array
        fscanf(ifp, "%d", &numbers[i]);

        if(feof(ifp))
         break ;

    }

    for(int h = 0; h < 1998; h++)
    {
        //if even number, add the numbers i-1, i, i+1 together
        sums[h] += numbers[h] + numbers[h+1] + numbers[h+2]; 
        printf("%d %d %d = %d\n",numbers[h], numbers[h+1], numbers[h+2], sums[h]);
    }

    /*
    for(int j = 0; j < 2000; j++)
    {
        if( numbers[j] - numbers[j+1] < 0 )//
        {
            printf("\n%d is less than %d", numbers[j], numbers[j+1]); 
            count++;
        }

    }
    */ 

   size_t size = sizeof(sums) / sizeof(sums[0]); 
   printf("\nSIZE OF SUMS: %d\n", size); 

    //counter for sums
    for(int j = 0; j < 667; j++)
    {
        if( sums[j] - sums[j+1] < 0)
        {
            printf("\n%d is less than %d", sums[j], sums[j+1]);
            count++; 
        }

        if(sums[j] == NULL)
            break; 
    }

 
    //return counter
    printf("\n%d\n", count);

    //close file
    fclose(ifp); 
    return 0; 
}
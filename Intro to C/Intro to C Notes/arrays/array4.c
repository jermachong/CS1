/*
    Jeremy Achong
    10/14/21

        Search for a value in array
*/

#include <stdio.h>
#define SIZE 10

int main(void)
{
    int a[SIZE] = {10,8,15,25,16,20,21,28,90,88}; 

    //flag variable, if found flag is raised (assigned to 1) 

    int key, flag = 0, found_index = -1; 
    printf("Enter a number to search: ");
    scanf("%d", &key); 
    int i; 
    for(i = 0; i < SIZE ; i++)
    {
        if(a[i] == key)
        {
            flag = 1; 
            found_index = i; 
            break; 
        }
    
    }
    if(flag == 1)
        printf("Found at %d", found_index);
    else
        printf("404 not found!\n");

}

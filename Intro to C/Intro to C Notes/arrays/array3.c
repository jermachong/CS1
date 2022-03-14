/*
    Jeremy Achong
    10/14/21

        Manipulating data in the array 
*/ 

#include <stdio.h>
#define SIZE 5

//Reversing the contents of the array 

void display(int arr[], int size) 
{
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]); 
}


int main(void) {

int a[SIZE] = {10,8,15,25,16};
int helper[SIZE]; 

    //Way 1 INEFFECIENT 
        //using a second array and building it from the first array, just in reverse. 

       /*
        int i, j; 
        for(i = 0, j=SIZE-1; i<SIZE ;i++, j--)
            helper[i] = a[j]; //helper array is filled with the contents of "a" array but in reverse

        printf("a array is: ");
        display(a, SIZE); 
        printf("\nhelper array is: "); 
        display(helper, SIZE); 

        for(int h =0; h<SIZE; h++)
            a[h] = helper[h]; //a is now changed to the contents of helper array 

        printf("\na array is: ");
        display(a, SIZE); 
        printf("\nhelper array is: "); 
        display(helper, SIZE); 

        */

        
    //Way 2
        // swapping the halfs using a temp variable
        //swapping i with  size - i -1
        //needs to be size / 2 because if it is size, then it will swap twice. 
        for(int i = 0; i < SIZE/2; i++)
        {
            int temp = a[i];
            a[i] = a[SIZE - 1 -i];
            a[SIZE - 1 -i] = temp; 
        } 
         
        printf("\na array is: ");
        display(a, SIZE);  
        printf("\nhelper array is: "); 
        display(helper, SIZE);

}
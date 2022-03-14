/*
    Jeremy Achong
    10.21.21

            Basic Sorting

        This program showcases two sorting methods: Bubble and Selection sort.

*/ 

#include <stdio.h>

//constant declaration 
#define MAX_SIZE 50000

//pre conditions: given array and array size
//post conditions: print out every element of the give array 
void display_array(int array[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d ", array[i]);
}

//pre conditions: given two arrays and the size to access the source array
//post conditions: copy elements from source to destination
void copy_array(int destination[], int source[], int size)
{
    //goes through source array and places it in destination.
    for(int i = 0; i < size; i++)
    {
        destination[i] = source[i]; 
    }
}

//pre conditions: given an array and its size
//post condtions: sorted least to greatest 
int bubble_sort(int arr[], int n)
{
    printf("\nUsing Bubble sort\n");
    int temp,  i , j ;  
    //sorting algorithem
    for(i = 0; i < n-i-1; i++)
    {
        printf("\nIteration # %d\n", i + 1);
        //
        for( j = 0; j < n-1; j++)
        {
            //swap  
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            } 

            //call the display function
            display_array(arr, n); 
            printf("\n");
        }

    }

    printf("\nSorted array using Bubble Sort:\n"); 
    
}

//pre conditions: given array and its size
//post conditions: sorted least to greatest
int selection_sort(int arr2[], int n)
{
    //
    int temp, min_index, i = 0;  

    printf("\nUsing Selection sort\n\n"); 

    //sorting algorithem 
    for(i = 0; i < n-1; i++)
    {
        printf("\nIteration# %d\n", i+1);
        //set minimum index 
        min_index = i; 

        for(int j = i+1; j < n-1 ; j++)
        {
            //if min is greater than arr[k], min is updated and moved to the front (arr[i]) . 
            if(arr2[j] > arr2[min_index])
            {
                min_index = j;
            }
            
        }
            //outside of nested loop because 
            temp = arr2[i];
            arr2[i] = arr2[min_index]; 
            arr2[min_index] = temp; 

        //call display function
        display_array(arr2,n); 
    } 

        printf("\n\nSorted array using Selection Sort:\n"); 

}

//Driver Function
int main(void)
{
    //varaible declaration
    int arr[MAX_SIZE], arrCopy[MAX_SIZE], size, i = 0, j, n; 
    
    //ask user for size amount of numbers to input to arr[]
    printf("How many numbers to sort?\n");
    scanf("%d", &n);

    //user menu
    for(i = 0; i < n; i++)
    {
        printf("Enter number %d: ",i+1);
        scanf("%d", &arr[i]);
    }

    //create a copy array in order to properly display selection sort
    copy_array(arrCopy, arr, n); 

    //display user's original input
    printf("\nArray before sorting: \n");
    display_array(arr, n); 
    printf("\n");

    //display the user's array sorted by calling bubble_sort
    bubble_sort(arr, n); 
    display_array(arr, n);
    printf("\n");
    
    //display user's array sorted by calling selection_sort
    selection_sort(arrCopy, n); 
    display_array(arrCopy, n); 
    printf("\n");


    return 0; 
}
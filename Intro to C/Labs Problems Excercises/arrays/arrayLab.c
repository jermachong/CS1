/*
    Jeremy Achong
    10.18.21

        Array Utlility
    This program holds utlity functions to process arrays.
*/
#include <stdio.h>
#define SIZE 5

void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int sumArray(int array[], int size)
{
    // i is counter
    int sum = 0, i = 0;

    for (i = 0; i < size; i++)
        sum += array[i];

    return sum;
}

int findMax(int array[], int size)
{
    //start max at first element in array, i is counter
    int max = array[0], i;

    for (i = 0; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}

int getDouble(int number)
{
    //return the given number times 2
    return number * 2;
}

int main(void)
{
    int i, j, myArray[SIZE], revArray[SIZE];

    //Loop through to ask user for SIZE amount of inputs 
    for (i = 0; i < SIZE; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &myArray[i]);
    }

    //display the user made array
    display(myArray, SIZE); 

    //print the summation of the array caling the sumArray function
    printf("The sum of myArray is: %d\n", sumArray(myArray, SIZE));

    //print the maximum value of the array calling the findMax funcion
    printf("The max value of myArray is: %d\n", findMax(myArray, SIZE));

    //loop through the array and use the getDouble function to double each element 
    for (i = 0; i < SIZE; i++)
    {
        printf("Double of %d is %d\n", myArray[i], getDouble(myArray[i]));
    }

    //assign the elements from myArray to revArray with a 2 counter loop
    //the i loop goes from the end of myArray while the j loop starts with the first space of revArray
    for (i = 4, j = 0; i >= 0; i--, j++)
        revArray[j] = myArray[i];


    //print the reversed array
    printf("Now the following data are from RevArray\n");
    display(revArray, SIZE); 

    //print the summation of the reveresed array caling the sumArray function
    printf("\nThe sum of revArray is: %d\n", sumArray(revArray, SIZE));

    //print the maximum value of the reversed array calling the findMax funcion
    printf("The max value of revArray is: %d\n", findMax(revArray, SIZE));

   //loop through the reversed array and use the getDouble function to double each element 
    for (i = 0; i < SIZE; i++)
    {
        printf("Double of %d is %d\n", revArray[i], getDouble(revArray[i]));
    }

    //end of function
    return 0;
}

/*
    Jeremy Achong
    10/14/21

        Prime Matching

    int isPrime() - take posiitve integer and return 1 if the number is prime
    void primeMatching(array 1, size 1, array 2, size 2) - takes two arrays and their sizes then prints
        the common prime numbers in the two arrays. It also shows the count of how many prime numbers are common in them.
*/ 

#include <stdio.h>
#define SIZE 200

//take posiitve integer and return 1 if the number is prime
int isPrime(int n)
{
    //Prime numbers must be greater than 1
    //Check for divisiblity between 2 and n. 
    if(n==1)
        return 0;
    for(int i = 2; i < n ; i++)
    {
        //If the number has no remainder when divisible by a number, then it is not prime.
        if(n%i == 0)
            return 0;
    }
    return 1; 
}

//takes two arrays, along with their sizes, then finds the MATCHING prime numbers in both.
//finally, it prints out the matching prime numbers. 
void PrimeMatching(int arr1[], int size1,int arr2[], int size2)
{
    //count variable keeps track of the amount of prime matches found
    //arrMatch[] is an array of the found matches
    int count = 0; 
    int arrMatch[SIZE]; 
    
    /* this loop begins by going through the arr1[], if it finds a prime number it proceeds to 
    look through arr2[]. if the arr1[] value matches the arr2[] value, it is considered a match,
    thus it is added to arrMatch[] and counter increases by 1. 
    */
    for(int i = 0; i < size1; i++)
    {
        if(isPrime(arr1[i]))
        {
            for(int j = 0; j<size2; j++)
            {
                if(arr1[i] == arr2[j])
                {
                    arrMatch[count] = arr1[i]; 
                    count++; 
                    break; 
                }
            }
             
        }
    }

    //after looking through the entirety of the first array, the matches are printed 
    printf("Common prime numbers are: "); 
    for(int h = 0; h < count; h++)
        printf("%d ", arrMatch[h]); 
    
    //the amount of matches found are printed
    printf("\nCommon count: %d", count); 

}
/* 
    In the main function the user provides a limit for each array and inputs their own data.
    then the primeMatching() function is used to print the common prime numbers
    after that the smallest and largest values in array 2 are given.
*/
int main(void)
{
    // n = array 1 accessed size, m = array 2 accessed size
    int n,m; 
    int small, large; 
    int arr1[SIZE], arr2[SIZE]; 

    //ask user for limits <= 200
    printf("Enter n and m: ");
    scanf("%d %d", &n,&m); 

    //ask user for data for the first list.
    printf("Enter data for first list: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]); 
    }

    //ask user for data for the second list
    printf("Enter data for second list: ");
    for(int j = 0; j < m; j++)
    {
        scanf("%d", &arr2[j]);
    }

    //parameters (array 1, size 1, array 2, size 2)
    PrimeMatching(arr1, n, arr2, m); 

    //search for smallest number 
    small = arr2[0];
    for(int h = 0; h < m; h++)
    {
        if(small > arr2[h]) //if  small is greater than array 2 value "h" then 
            small = arr2[h]; //small becomes that smaller value.
    }
    printf("\nSmallest number in the second list: %d\n", small);

    //search for largest number 
    large = arr2[0];
    for(int k = 0; k < m; k++)
    {
        if(large < arr2[k]) //if large is smaller than the array 2 value "k" then
            large = arr2[k]; //large becomes that larger value

    }
    printf("Largest number in the second list: %d", large); 

    //end of main function
    return 0; 
}
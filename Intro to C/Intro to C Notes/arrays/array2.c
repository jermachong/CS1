/*
    Jeremy Achong
    10/12/21
            Array p2
*/ 
#include <stdio.h>

/* VLA variable length array
the size of the array is no known until you getn
the system uses a memory pool called stock to store this kind of array 
the size of stack is limited nad if the value of n is large, your code will crash
programer has no control to know whether it will crash or not. so questionable progrmaming practice. 
*/ 

#define SIZE 100

int main(void) {


  int j; 
  int n[SIZE]; 
  printf("How many people:");
  scanf("%d", &j); 

  //in this method we are making the array a size of 100, then saying we are going to use a portion of the total size. ("j")


printf("Enter the ages of %d people:\n", j);
for(int i = 0; i < j; i++)
{
    scanf("%d", &n[i]);
}  

printf("The data in reverse\n");

  for(int i = 4; i >= 0; i--)
    printf("%d ", n[i]); 

printf("The data sum: ");

    int sum = 0; 
    for(int i = 0; i < j; i++)
        sum += n[i]; 

    printf("%d\n", sum);

printf("The average is %.2f\n", sum*1.0/j); 


    return 0; 
}
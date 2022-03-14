/*
    Jeremy Achong
    10/12/21
            Array
*/ 
#include <stdio.h>

/*
    *Arrays are a collection of items(ints, floats, chars) 
    *if a variable is a box, an array is a shipping container of boxes. 
    *Arrays have user specified sizes
    *A single array can only contain 1 data type 

*/

int main(void) {

   /* 
   Array declaration: type array[size]
   Exp: int A[10]; , float a[5] = {0.0, 1.0 , 2.0 , 3.0 , 4.0} if you set first to 0, the rest will become 0
   char s[] = "abc"; equivalent to 
   char s[] = {'a','b','c'}
   Array modification: A[0] = 3; , A[5] = A[3] * 2; 
   */ 

  int j; 
  printf("How many numbers:");
  scanf("%d", &j); 
  int n[j]; 

  /* VLA variable length array
  the size of the array is no known until you getn
  the system uses a memory pool called stock to store this kind of array 
  the size of stack is limited nad if the value of n is large, your code will crash
  programer has no control to know whether it will crash or not. so questionable progrmaming practice. 
  */ 

  //Ineffecient way
  //scanf("%d", &n[0]); 

for(int i = 0; i < 5; i++)
{
    printf("Enter value for array position %d\n", i);
    scanf("%d", &n[i]);
}

printf("The data in reverse\n");

  for(int i = 4; i >= 0; i--)
    printf("%d", n[i]); 

printf("The data sum");

    int sum = 0; 
    for(int i = 0; i < 5 ; i++)
    sum += n[i]; 

    printf("%d\n", sum); 





    return 0; 
}
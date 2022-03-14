#include <stdio.h>

int main(void)
{
    int array[26], i ;
for( i = 0; i <=3 ; i++ )
{
      array[i] = 'A' + i ;
       printf ( "%d-%c#", array[i], array[i] ) ;
}
 
}

#include <stdio.h>

long long factorial(int num)
{
    //n! = n*[n-1]*n[n-2]
    // n*[n] n*[n-(n-1)] . . . 

    for(int numCount = num -1; numCount > 0; numCount--)
    { 
        num = num*(numCount); 
        printf("%d\n", num);
    }

    long long result = num; 

    printf("fact: %lld\n", result); 

    return result; 

}
int main(void)
{
    int x, y; 
    scanf("%d",&x); 

    factorial(x); 

    return 0; 
} 

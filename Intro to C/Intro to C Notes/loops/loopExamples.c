/*
    Loop Examples
*/


#include <stdio.h>

int main(void){

    int c = 1; 

    while(c <= 10){

    printf("%d",c);

    printf("I will not cheat in the exam\n"); 

    ++c; 

    }

    return 0;

}

int main(void) {

    int n;
    int counter = 0;
    scanf("%d",&n);

    while(counter <= n)
    {
        counter+=2; 

    }

    return 0; 

}

int main(void) {

    int n; 
    scanf("%d",&n);
    int counter = 0; 
    int sum = 0; //WARNING!

    while(counter <= n)
    {
        sum += counter;
        counter++; 

    }

    printf("1+2+...%d is %d\n",n,sum); 
}

int main(void) {

    int n; 
    scanf("%d",&n);
    int counter = 0; 
    int sum = 0; //WARNING!

    if(counter%2==0)
    {
        sum += counter;
        counter++; 

    }

    printf("1+2+...%d is %d\n",n,sum); 
}


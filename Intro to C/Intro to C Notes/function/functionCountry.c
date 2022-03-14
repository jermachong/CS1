/*
    Jeremy Achong
    9-28-21

        Country
        Exemplify the logic and flow of multiple functions in one program. 
*/ 

void usa(void); 
void denmark(void);
void sweden(void); 
void capital(char c); 

#include <stdio.h>

void capital(char country_code) {

    if(country_code == 'u')
        printf("\nCapital of USA is Washington DC\n"); 
    else if(country_code == 'd')
        printf("\nCapital of Denmark is Coppenhagen\n"); 
    else if(country_code == 's')
        printf("\nCapital of Sweden is Stockholm\n");
    else   
        printf("Invalid country code\n"); 

}

void usa() { 

    printf("I am in USA\n"); 
    capital('u'); 
    printf("Leaving USA\n"); 

}

void denmark() {

    printf("I am in Denmark\n");
    capital('u'); 
    printf("Leaving Denmark\n"); 

}

void sweden() {

    printf("I am in Sweden\n"); 
    capital('s'); 
    printf("Leaving Sweden\n"); 
}

int main(void) {

    printf("Going to USA\n"); 
    usa(); 
    printf("Came back from USA\n"); 

    printf("Going to Denmark"); 
    denmark(); 
    printf("Came back from Denmark");

    printf("Going to Sweden");
    sweden();
    printf("Came back from Sweden"); 

    capital('w'); 

    return 0; 
}

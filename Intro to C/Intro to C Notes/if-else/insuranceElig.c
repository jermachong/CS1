//Insurance Eligibility
// 9-10-21

#include <stdio.h>

int main(void){
    char sex, ms; 
    int age;
    printf("Enter age, sex (m,f), and marial status (m, u): ");
    scanf("%d %c %c", &age, &sex, &ms);

    if((ms=='m') || (sex =='m' && age > 30) ||
    (sex == 'f' && age > 25))
        printf("You are eligible");

    else    
        printf("You are not eligible");

    return 0; 
}
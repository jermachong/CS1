// working with ASCII values to learn how values are stored
// Author : Yohan Hmaiti
// For COP 3223c - Dr. Ahmed

#include <stdio.h>

int main(void) {

    char ch1 = 'A';

    printf("\nour stored character is: %c \n\n", ch1);

    printf("our character 'A' is stored with ASCII value: %d \n\n", ch1);

    printf("Position of C uppercase in the uppercase letter range starting from 0: %d \n\n", 'C'-ch1);

    printf("Position of C uppercase in the uppercase letter range starting from 1: %d \n\n", (('C' - ch1)+1));

    printf("Using ASCII with digit numbers we can get the value of the number itself by substracting it from '0': %d \n\n", '5'-'0');

    printf("'5' is printed as a character: %c\n\n", '5');

    printf("'5' is stored as an ASCII value equal to :%d \n\n", '5');

    return 0;
}
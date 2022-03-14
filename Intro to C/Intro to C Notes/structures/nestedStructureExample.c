/*
    Jeremy Achong
    11.23.21

        Nested Structure

*/ 

#include <stdio.h>
#include <string.h>

typedef struct date
{
    int day;
    int month;
    int year; 

}date ;

typedef struct author 
{
    char authorName[50]; 
    char country[50];
    date dob; 
;

}author ;

typedef struct book
{
    char title[100];
    author author; 
    int pages; 
 
}book ;

int main(void)
{

    book b; 

    date d; 
    d.day = 5; 
    d.month = 6;
    d.year = 1970; 

    b.author.dob = d; 




    return 0; 
}
/*
    Jeremy Achong
    11.23.21

        Book

*/

#include <stdio.h>
#include <string.h>

//defining a structure
struct book
{
    //declare the members/fields/attributes
    char title[100]; 
    char author[100]; 
    float price;
    int pages; 

}b1,b2; //could declare by putting b1, b2 before the ';' here

typedef struct bookA //this way you don't have to write struct everytime. 
{
    char title[100]; 
    char author[100]; 
    float price;
    int pages; 

}bookA;



int main(void)
{
    struct book b3 = {"C book", 
                "c author", 50.5, 300}; //declare and initialize book variable
    
    printf("B3 details: %s %s %.2f %d\n", b3.title, b3.author, b3.price, b3.pages); 

    struct book b4; 

    printf("Enter b4 title: ");
    scanf("%[^\n]s", b4.title);  

    printf("Enter b4 pages: ");
    scanf("%d", &b4.pages); 

    strcpy(b1.title, "python book"); //needs to call strcpy to copy over string

    b1.price = 39.50; //with int and other simple data types, it can be simply set

    b2 = b1; //this copies b1 to b2. still seperate types. 

    b2.price += 20; 

    bookA book; 
}
/*
    Jeremy Achong
    9-30-21

        Menu Driven Program
*/ 

#include <stdio.h>

int main()
{
    char choice, ch; //Print out menu
    printf("+ add, - sub, * multiply. x exit"); 
    scanf("%c",&choice); 
    while(choice != 'x' && choice != 'X')
    {
        int n1, n2, result;  
        printf("enter two numbers"); 
        scanf("%d %d", n1,n2); 
        if(choice == '+')
        {
            result = n1 + n2; 
            return result; 
        }

        else if(choice == '-')
        {
            result = n1 - n2; 
            return result; 
        }

        else if(choice == '*')
        {
            result = n1 * n2; 
            return result; 
        }
        
        else if(choice == 'x' || choice == 'X')
        {
            printf("Bye!");
            return 0; 
        }

    while((ch = getchar() != '\n'))
    scanf("%c", &choice);
    }

    printf("Thank you!"); 
}
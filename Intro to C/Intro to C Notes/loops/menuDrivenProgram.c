/*
    Jeremy Achong
    9-30-21

        Menu Driven Program
*/ 

#include <stdio.h>

int main()
{
    int choice; //Print out menu
    printf("1. add, 2. sub, 3. multiply. 4. exit"); 
    scanf("%d",&choice); 
    while(choice != 4)
    {
        int n1, n2, result;  
        printf("enter two numbers"); 
        scanf("%d %d", n1,n2); 
        if(choice ==1)
        {
            result = n1 + n2; 
            return result; 
        }

        else if(choice ==2)
        {
            result = n1 - n2; 
            return result; 
        }

        else if(choice ==3)
        {
            result = n1 * n2; 
            return result; 
        }
        
        else if(choice == 4)
        {
            printf("Bye!");
            return 0; 
        }
    }

    printf("Thank you!"); 
}
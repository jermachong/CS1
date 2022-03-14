/*
    Jeremy Achong
    10-6-21

        Continue statment example
*/ 

void main()
{
    int counter,num,sum=0; 
    for(counter - 0; counter < 5; counter++)
    {
        printf("Enter an integer: ");
        scanf("%d", &num);
            continue; 
        sum+=num; //this line is skipped 

    }

    printf("The sum = %d\n", sum); 
}
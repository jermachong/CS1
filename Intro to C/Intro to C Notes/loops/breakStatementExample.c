/*
    Jeremy Achong
    10-5-21

        Break statment example
*/ 

void main()
{
    int counter = 0, num; 
    float sum = 0, average;

    printf("Input the numbers one after another to exit enter -1\n");
    
    /*This condition is specified as 1 which is non-zer. Hence this condition 
    specifies an infinite loop, but the break terminates its "execution" */ 

    while(1) {
        scanf("%d", &num);
        if (num == -1)
        break;
        sum = sum + num; 
        counter = counter + 1; 
    }
        average = sum/counter;
        printf("The average of the input numbers = %f", average); 

}
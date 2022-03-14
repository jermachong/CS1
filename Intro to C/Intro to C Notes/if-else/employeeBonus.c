//Employee Bonus
//9-10-21

#include <stdio.h>
int main()
{
    int bonus, cur_year, join_year, year_of_serv ;
    printf("Enter current year and joinng year \n");
    scanf("%d %d", &cur_year, &join_year);

    year_of_serv = cur_year - join_year;
    
    if(year_of_serv >=5)
    {   
        bonus = 5000;
        printf("Bonus = $%d", bonus);

    }
    return 0;
}
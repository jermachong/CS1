//Employee Bonus
//9-10-21

#include <stdio.h>
int main()
{
    int bonus, cur_year, join_year, year_of_serv ;
    printf("Enter current year and joinng year \n");
    scanf("%d %d", &cur_year, &join_year);

    year_of_serv = cur_year - join_year;
    
    if(year_of_serv >=5){
        bonus = 5000;
    }
    else{  //For those who have worked less than 5 years 
        bonus = 3000;
    }
    
        printf("Bonus = $%d\n", bonus);
        printf("calculation completed!");
    return 0;
}
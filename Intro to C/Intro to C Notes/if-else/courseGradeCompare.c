// Course Grade Compare
// 9-10-21

#include <stdio.h>
int main(void){
    char grade_adam, grade_jones;
    printf("Enter two letter grades( first for Adam and second for Jones)");
    scanf("%c%c", &grade_adam,&grade_jones);

    if(grade_adam < grade_jones){
        printf("Congrats Adam! \n");
        printf("Good luck Jones! \n");
    }
    else if(grade_jones == grade_adam)
    {
         printf("Both of you got same!\n ");
    }
    else{ //came here only because grade adam > grade_jones only other possible combo
        printf("Congratuatlions Jones! \n");
        printf("Good luck Adam\n");

    }
    return 0; 
}

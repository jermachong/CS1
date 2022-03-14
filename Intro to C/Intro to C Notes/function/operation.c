#include <stdio.h>

int add(int a, int b){

    return a+b;
}

int sub(int a, int b) {

    return a-b;
}

int main(void) {

    int x, y; 
    char op;
    printf("Enter two numbers & what operations you would like to perform\n");
    scanf("%d %d %c", &x, &y, &op);

    if(op == '+'){

        int result = add(x,y);
        printf("%d%c%d = %d",x,op,y,result);
    }
    else if(op == '-'){

        int result = sub(x,y); 
        printf("%d%c%d = %d",x,op,y,result); 
    }
}
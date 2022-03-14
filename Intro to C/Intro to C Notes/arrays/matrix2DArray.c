/*
    Jeremy Achong
    10.26.21

        2D Array Matrix Example 
*/

#include <stdio.h>
#define MAXROWS 10
#define MAXCOLUMNS 10

void print(int arr[][MAXCOLUMNS], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}
int main()
{
    int r, c;
    int arr[MAXROWS][MAXCOLUMNS];

    scanf("%d %d", &r, &c);
    printf("Enter data for %dx%d matrix: \n", r, c);

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &arr[i][j]);
    printf("\nCalling the print function: \n");
    print(arr, r, c); //see how are we calling

    
    return 0;
}
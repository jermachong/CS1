/*
    Jeremy Achonng
    10.28.21

        Matrix is fun!

        This program plays with various operations on a matrix.
        display, max, LowerLeft, UpperRight, add, sumSurrounding
*/

//pre-prec directives
#include <stdio.h>

#define MAXROWS 100
#define MAXCOLUMNS 100

/* Pre-conditions: takes 2D array number of rows & columns.
   Post-conditions: prints the matrix in well-formatted display. *use %4d to print numbers
*/ 
void displayMatrix(int arr[MAXROWS][MAXCOLUMNS], int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            printf("%4d", arr[i][j]);
        printf("\n");
    }
}

/* Pre-conditions: takes 2D array, number of rows & columns
   Post-conditions: prints the highest number in each ROW
*/ 
void findMaxPerRow(int arr[MAXROWS][MAXCOLUMNS], int r, int c)
{
    //variable declaration 
    //set max to the first number in matrix as start off point 
    int i, j, max = arr[0][0];

    for(i = 0; i < r; i++)
    {
        //loop through columns, if the max is less than the element, max becomes that element 
        for(j = 0; j < c; j++)
            if(max < arr[i][j])
                max = arr[i][j];

        //print max for every row
        printf("max of row %d is %d\n",i, max); 
        max = arr[i][0]; 
    }

    
}
/* Pre-conditions: takes 2D array, number of rows & columns
   Post-conditions: prints the lower left triangle numbers and display remaining as 0
*/ 
void printLLTriangle(int arr[MAXROWS][MAXCOLUMNS], int r, int c)
{
    int i, j;
    int zero = 0;
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(i == j || i > j)
            printf("%4d", arr[i][j]);

            if(i < j)
            printf("%4d", zero); 
        }
        printf("\n");
    }
}
/* Pre-conditions: takes 2D array, number of rows & columns
   Post-conditions: prints the upper right triangle numbers and display remaining as 0
*/ 
void printURTriangle(int arr[MAXROWS][MAXCOLUMNS], int r, int c)
{
    int i, j;
    int zero = 0;
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(i == j || i < j)
            printf("%4d", arr[i][j]);

            if(i > j)
            printf("%4d", zero); 
        }
        printf("\n");
    }
}
/* Pre-conditions: takes 3 2D arrays [2 of them are filled one is empty], rows, columns,
                    assuming all matrix has the same number of rows & columns
   Post-conditions: ad the first two matrix stores the result in third matrix
*/ 
void addMatrix(int M1[][MAXCOLUMNS], int M2[][MAXCOLUMNS], int R[][MAXCOLUMNS], int r, int c)
{
    int i, j;
    
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            R[i][j] = M1[i][j] + M2[i][j];
            //printf("%4d", R[i][j]);
        }
    }
}
/* Pre-conditions: takes a matrix, # of rows, # of columns, int i, int j, 
   Post-conditions: indicates the position of a number in the matrix, fumction sum-up all the 
                    adjacent numbers in [i][j] and returns the result
*/ 
int sumSurrounding(int arr[MAXROWS][MAXCOLUMNS],int r,int c,int i,int j)
{
    int h, k, sum = 0; 
    //loop through array and search for i, j 
    for(h = 0; h < r; h++)
        for(k = 0; k < r; k++)
        {
            //if i,j is found then add the numbers around it.
            if(h == i && k == j)
                {
                    //include top left, above, top right, right, bottom right, below, bottom left, left
                    /*
                       i-1j-1   i-1j    i-1j+1

                       ij-1     ij      ij+1 

                       i+1j     i+1j     i+1j+1
                    */
                
                    sum += arr[i-1][j-1] + arr[i-1][j] + arr[i-1][j+1] +
                           arr[i][j-1] +                 arr[i][j+1] 
                         + arr[i+1][j-1] + arr[i+1][j] + arr[i+1][j+1]; 
                }
            else if(i < 0 || j < 0)
            {
                printf("Exit");
                break; 
            }
        }
    
    return sum; 
}

//Driver Function
int main(void)
{
    //variable declaration
    int r, c;
    int arr[MAXROWS][MAXCOLUMNS],arr2[MAXROWS][MAXCOLUMNS], arr3[MAXROWS][MAXCOLUMNS];

    //ask for user input to build 2D array
    printf("enter number of rows and columns:");
    scanf("%d %d", &r, &c);

    //build 2D arrays
    int l, p = 0; 
    printf("input for matrix 1:\n");
    for (int l = 0; l < r; l++)
    {
        //print out start and end position 
        //00 to 03 01 to 10
        printf("data for matrix1[%d][%d] to matrix1[%d][%d]", l,0,l,c-1);

        for (p = 0; p < c; p++)
        {
            scanf("%d", &arr[l][p]);
        }

    }
    printf("intput for matrix 2:\n");
    int h, k = 0; 
    for (h = 0; h < r; h++)
    {
        printf("data for matrix2[%d][%d] to matrix2[%d][%d]", h,0,h,c-1);
        for (k = 0; k < c; k++)
        {
            scanf("%d", &arr2[h][k]);
        }
    }

    //call display function
    printf("\nprinting matrix 1:\n");
    displayMatrix(arr, r, c);

    printf("printing matrix 2:\n"); 
    displayMatrix(arr2,r,c); 

    //call findMaxPerRow
    printf("\nprinting max per row for matrix 1:\n");
    findMaxPerRow(arr,r,c);
    
    //call lower left triangle
    printf("\nprinting lower left triangle of matrix 1:\n");
    printLLTriangle(arr,r,c); 

    //call upp right triangle
    printf("\nprinting upper right triangle for matrix 1:\n");
    printURTriangle(arr,r,c); 

    //summation of matrix 1 & matrix 2
    printf("\nmatrix 1 + matrix 2 is:");
    addMatrix(arr,arr2,arr3,r,c);
    displayMatrix(arr3,r,c);

    int i= 1, j = 1; 
    while(i >= 0 && j >= 0)
    {
        printf("enter i and j for calculating sum of surrounding:");
        scanf("%d %d", &i, &j);
        if(i >= 0 && j >= 0)
        printf("sum of surrounding is %d\n",sumSurrounding(arr,r,c,i,j)); 
    }

    return 0; 
}
  
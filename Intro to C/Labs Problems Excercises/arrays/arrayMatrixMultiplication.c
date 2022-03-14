/*
    Jeremy Achong
    11.1.21

        Matrix Multiplication

*/

#include <stdio.h>

#define ROWS 10
#define COLUMNS 10
/* Pre-condition: take an empty 2d array
   Post-condition: fill array with user input
*/
void Filldata(int A[][COLUMNS], int r, int c)
{
    //variable declaration
    int i, j; 

    //prompt user for input
    printf("Enter data for %dx%d matrix: \n", r,c);

    //i for rows, and j for columns 
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
         scanf("%d", &A[i][j]); 
}

/* Pre-condition: takes filled 2d array
   Post-condition: prints the matrix in a well-formatted way. 
*/
void Display(int A[][COLUMNS], int r, int c)
{
    //variable declaration
    //counters
    int i, j;
    printf("\n"); 

    //i for rowws, and j for columns
    //loop used to iterate through rows and columsn to print the content of the array
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
            printf("%d\t", A[i][j]); 

        //print a new line to have a square shaped matrix
        printf("\n");
    }

}

/* Pre-condition: Takes 2, 2D arrays and four integers that indicate row and column size.
   Post-condition: Prints out the multiplication of the two matrices
*/
void Multiply(int M1[][COLUMNS], int r1, int c1, int M2[][COLUMNS], int r2, int c2)
{
    //variable declaration for counters
    //and 2d array that stores the result
    int i,j,k; 
    int result[ROWS][COLUMNS]; 

    //conditional to catch the edge case where the columns of the first 
    //2D array != rows of the second 2d array
    if(c1 != r2 ){

        printf("Not valid dimensions for multiplication"); 
        return; 
    }

    //multiplication and storing the result to the 2d array using 3 nested for loops
    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            //initalize result array at the current i and j position to 0
            result[i][j] = 0; 

            for(k = 0; k < c1; k++)
                //multiplication
                result[i][j] += M1[i][k] * M2[k][j];
        }
    }
 
    printf("\nDisplaying Result Matrix:"); 
    Display(result,r1,c2); 

} 

//Driver function
int main(void)
{
    //declare 2d arrays that will
    int matrix1[ROWS][COLUMNS], matrix2[ROWS][COLUMNS];

    int rows1, columns1, rows2, columns2; 

    //ask the user for # of rows and columns for Matrix 1
    printf("Working for Matrix 1 ");
    printf("\nEnter number of rows and columns: ");
    scanf("%d %d",&rows1,&columns1);

    //call Filldata() to fill in Matrix 1
    Filldata(matrix1,rows1,columns1);

    //ask the user for # of rows and columns for Matrix 2
    printf("Working for Matrix 2 ");
    printf("\nEnter number of rows and columns: ");
    scanf("%d %d", &rows2, &columns2); 

    //call Filldata to fill in Matrix 2
    Filldata(matrix2,rows2,columns2);

    //display function prints out Matrix 1 
    printf("\nDisplaying Matrix 1: ");
    Display(matrix1,rows1,columns1);

    //display function prints out Matrix 2
    printf("\nDisplaying Matrix 2: ");
    Display(matrix2, rows2, columns2);

    //call multiply function to multiply the matrices
    Multiply(matrix1,rows1,columns1,matrix2,rows2,columns2); 


    return 0; 
}
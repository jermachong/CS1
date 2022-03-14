/*
    Jeremy Achong
    10.26.21

        2D Array Example - Student Grade

        use nested loop in order to go through a 2D array
*/

int main()
{

    int students[3][4];
    int i, j;
    for (i = 0; i < 3; i++)
    {
        printf("\n Working for student %d. Enter ID number and 4 grades.\n", i + 1);
        for (j = 0; j < 4; j++)
        {
            scanf("%d", &students[i][j]);
        }
    }
    for (i = 0; i < 3; i++)
    {
        printf("\n Displaying for student %d. ID number and 4 grades.\n", i + 1);
        for (j = 0; j < 4; j++)
        {
            printf("%d\t", students[i][j]);
        }
        printf("\n");
    }

    return 0;
}
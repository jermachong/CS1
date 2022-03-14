/*
    Jeremy Achong
    11.4.21

        Showcasing how to use pointers to access arrays
*/
int main(void)
{
    int grid[4][2] = {
        {5, 6},
        {8, 23},
        {22, 9},
        {90, 4}};
    int i;
    for (i = 0; i <= 3; i++)
        //here grid[i] is acting as an address of an array within an array. 
        printf("\nAddress of %d th 1-D array = %u", i, grid[i]);
}

/*
    s[2][1] //second row first col
    *(s[2]+1)
    *(*(s+2)+1) //here 2 indicates the array number

    all of these are ways to access the same data

*/ 
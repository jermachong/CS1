/*
    Jeremy Achong
    11.16.21

        using fscanf and fprintf

*/

#include <stdio.h>
int main()
{
    FILE *infile;
    FILE *outfile;

    int student_ID, j, g1, g2, g3, n;
    char student_name[30];
    float avg;

    infile = fopen("students.txt", "r");      //read mode
    outfile = fopen("students_avg.txt", "w"); //write mode
    fscanf(infile, "%d", &n);                 //read the first integer

    for (j = 1; j <= n; j++)
    {                                                //loop n number of times to read n students
        fscanf(infile, "%d", &student_ID);           //read student id
        fscanf(infile, "%s", student_name);          //read last name
        fscanf(infile, " %d %d %d ", &g1, &g2, &g3); //read 3 grades
        avg = (g1 + g2 + g3) / 3.0;
        printf("%d %s %d %d %d %.2f\n", student_ID, student_name, g1, g2, g3,
               avg);
        fprintf(outfile, "%d %s %.2f\n", student_ID, student_name, avg);
    }
 
    fclose(infile);  //close infile
    fclose(outfile); //close outfile. Data will not be written if you do not close

    return 0;
}
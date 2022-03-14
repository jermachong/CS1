/*
    Jeremy Achong
    11.17.21

        Grade Summary

        This program read and writes based off
        grades.txt and summary.txt 
*/

//pre-processor directives
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
 
//constants
#define MAXSTD 100 //max # of students
#define MAXITEMS 10 //max # of quizzes
#define STLEN 51 //max char array size. Max string length is 50

/*
pre-condition: takes a float
post-coindition: returns the letter grade according to the scale
*/
char getLetterGrade(float score)
{
   //test cases for letter grade
   if(score >= 90)
   {
       return 'A'; 
   }
   else if(score > 80 && score <= 89.99)
   {
       return 'B'; 
   }
   else if(score > 70 && score <= 79.99)
   {
       return 'C'; 
   }
   else if( score <= 69.99)
   {
       return 'F'; 
   }

}

/*
pre-condition: takes total scores of all the students
post-coindition: returns the index containing the highest total score. 
*/
int getMaxTotalldx(float totals[], int n)
{
    int i, max = 0; 

    //if a new highest score is found then it is updated
    for(i = 0; i < n; i++)
    {
       if(totals[max] < totals[i])
       {
           max = i;  
       }
    }

    //when loop ends return the result of the sorting loop
    return max; 

}

/*
pre-condition: takes the output file pointer, ids, names and totals of all the students 
post-coindition: prints the summary to console and the output file
*/
void writeData(FILE *out, char ids[][STLEN], char names[][STLEN], float totals[], int n)
{
    //variable declaration
    int i; 

    //loop to iterate through arrays and access students
    for(i = 0; i < n; i++) {
        fprintf(out,"\n"); 
        printf("\n"); 
        fprintf(out, "ID: %s Lname: %s Total: %.2f Grade: %c",
                 ids[i], names[i], totals[i],getLetterGrade(totals[i])); 

        printf("ID: %s Lname: %s Total: %.2f Grade: %c",
                 ids[i], names[i], totals[i],getLetterGrade(totals[i])); 
    } 

    printf("\n");
}

/*
pre-condition: takes the name and a search key 
post-coindition: returns the index of the names array containing the name
*/
int lookup(char names[][STLEN], char key[STLEN], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        //calls strcmp to search for set key 
        //must be case in-sensitive
        if(strcmp(names[i], key) == 0)
        {
            return i; 
        }
        
    }
    if(i == n) //i hits n when lookup has failed to find the student in given array. 
        return 0; 
}

/* 
pre-condition: string
post-condition: entirety of strings transformed to lower case
*/
void str_to_lower(char *s)
{
    for(int i = 0; s[i] != '\0'; i++)
        //strcpy(s[i],tolower(s[i])); 
        s[i] = tolower(s[i]); 
}


//driver function
int main(void)
{
    char ids[MAXSTD][STLEN]; //for string ids
    char names[MAXSTD][STLEN];// for storing last names
    float grades[MAXSTD][MAXITEMS]; // for storing grades
    float totals[MAXSTD]; //for storing calculated totals
    float avg[MAXSTD]; //averages for each student 

    int n, g; //n represents the N lines that contain data about students
              //g represents the G number of quizzes for each student


    //input and output file pointers 
    FILE *ifp, *ofp; 

    //open data from files
    ifp = fopen("grades.txt", "r"); //reader
    ofp = fopen("summary.txt", "w"); //writer

    fscanf(ifp, "%d %d", &n, &g); //read first integer and set N
                                  //read second integer and set G


    fprintf(ofp, "Summary of students:\n========"); //write first line of output file

    //total score = 35% of midterm + 40% of final term + 25% of average G quizzes
    //1st # is midterm, 2nd # is finalterm, remaining G numbers are the scores for G number of quizzes

    //load data into arrays from files 
    int i, j; 
    for(i = 0; i < n; i++)
    {   

        //varaibles that need to be reset for each student
        float midterm, finalterm, sum = 0.0; 

        //access student id and name
        fscanf(ifp, "%s %s", ids[i], names[i]); 

        //nested for loop to access each student's grades
        for(j = 0; j < 2 + g; j++)
        {
            //retrieve 6 grades at once from student
            fscanf(ifp, "%f", &grades[i][j]); 
            if(j > 1)
            sum += grades[i][j]; 
            
        }

        avg[i] = sum / g; 

        //midterm is first and final term is second in grades array
        midterm = grades[i][0]; 
        finalterm = grades[i][1];

        //total is calculated and stored in array
        totals[i] = midterm*.35 + finalterm*.40 + avg[i]*.25;  

    }

    printf("Summary of students: \n========");

    //write to summary.txt
    writeData(ofp, ids, names, totals, n); 

    //get best student by calling getMaxTotalldx
    int maxID = getMaxTotalldx(totals,n); 

    //print out top student
    fprintf(ofp,"\n========\nFirst student with the highest total is ");
    fprintf(ofp, "%s %s %.2f", ids[maxID], names[maxID], totals[maxID]);
    printf("\n========\nFirst student with the highest total is ");
    printf("%s %s %.2f", ids[maxID], names[maxID],totals[maxID]);

    printf("\n");

    //announce that data has been written to text file. 
    fprintf(ofp, "Data written in summary.txt file\n");
    printf("Data written in summary.txt file\n"); 

    //SEARCH
    //variable declaration
    char key[STLEN]; 
    int foundID; //id value of the found student

    //ask for user inut
    printf("Enter a last name to search: ");
    fprintf(ofp, "Enter a last name to search: %s ",key); 
    scanf("%[^\n]s", key);

    //make key case in-sensitive
    str_to_lower(key); 

    //call lookup function
    foundID = lookup(names,key,n);


    if(foundID == 0) //if the name was not found
    {
        fprintf(ofp,"%s not found in the list.", key);
        printf("%s not found in the list.", key);
    }
    else
    {
        //print out found student's name
        fprintf(ofp,"%s was found in the list. Here is the details: \n",names[foundID]);
        printf("%s was found in the list. Here is the details: \n",names[foundID]);

        //display ID, lastname, total grade
        fprintf(ofp,"ID: %s Lname: %s Total: %.2f\n", ids[foundID],names[foundID],totals[foundID]);
        printf("ID: %s Lname: %s Total: %.2f\n", ids[foundID],names[foundID],totals[foundID]);
        
        fprintf(ofp, "Grades: \n" );
        printf("Grades: \n" );
  
        //grade iteration loop
        fprintf(ofp, "Midterm: %.2f, Final term: %.2f, quizzes: \n",grades[foundID][0],
                        grades[foundID][1]);
        printf("Midterm: %.2f, Final term: %.2f, quizzes: \n",grades[foundID][0],
                        grades[foundID][1]);

        //print out grades of found studnet, skipping the mid and final term
        for(j = 2; j < 2+g; j++)
        {
            fprintf(ofp,"%.2f ",grades[foundID][j]);
            printf("%.2f ",grades[foundID][j]);
        }
        
    }

    fclose(ifp); //close infile
    fclose(ofp); //close outfile
    return 0; 
}

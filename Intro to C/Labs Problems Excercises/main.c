/*
    Jeremy Achong
    12.1.21
    
        Final Project

        database system for storing and earching students' information about XYZ academy.

*/ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "leak_detector_c.h"

#define MAXSTRLN 51

//Structures

typedef struct date
{
    int day;
    int month;
    int year; 

}date ;

typedef struct Student
{
    int id; 
    char *fName; 
    char *lName; 
    date dob; //Nested structure
    

}Student; 

typedef struct Enrollment
{
    int id; //student id
    char *cid; //course id
    char *semester; 
    float totalCredit; //grade 

}Enrollment; 

typedef struct Course
{
    char *cid; 
    char *courseName; 
    float credit; 

}Course; 

Student *loadStudents(int *numStudents); 
Enrollment *loadEnrollment(int *numEnrollments);
Course *loadCourses(int *numCourses);
void display_course(Course c); //EXTRA FUNC
void display_student(Student s); //EXTRA FUNC
void menu(Student *ArrayOfStudents, int amountStudents, Course *ArrayOfCourses,
            int amountCourses, Enrollment *ArrayOfEnrollments, int amountEnrolls);
Student *search_students(Student *ArrOfStu, int numStudents, char *option, Enrollment *ArrOfEnr,
                             int numEnroll,Course *CourseList, int numCourse); 
    void search_enrollment(Enrollment *EnrollList, int numEnroll,Course *CourseList, int numCourse,
                                 Student s);
Course *search_courses(Student *ArrOfStu, int numStudents, //EXTRA FUNC
                        char *option, Enrollment *ArrOfEnr, int numEnroll, Course *ArrOfCourse, int numCourses); 
void add_course(Course *CourseList, int numOfCourse); 
char getGrade(float score); //EXTRA FUNC
void count(Student *arrOfStu, int numOfStu, Course *arrOfCo, int numOfCo,
                 Enrollment *arrOfEnr, int numOfEnr);
void sort(Student *StudentList, int numOfStu); 
void free_memory(Student *ArrayOfStudents, int numOfStu, Course *ArrayOfCourses, 
                    int numOfCourses, Enrollment *ArrayOfEnrolls, int numOfEnrolls);
void exitp(Student *ArrayOfStudents, int amountStudents, Course *ArrayOfCourses,
            int amountCourses, Enrollment *ArrayOfEnrollments, int amountEnrolls);

int main(void)
{
    atexit(report_mem_leak); 

    Student *StudentList; 
    Course *CourseList; 
    Enrollment *EnrollList; 

    int total_stu; 
    int total_course;
    int total_enrolls; 

    StudentList = loadStudents(&total_stu); 
    CourseList = loadCourses(&total_course);
    EnrollList = loadEnrollment(&total_enrolls); 

    menu(StudentList, total_stu, CourseList, total_course, EnrollList, total_enrolls); 

    //exit(); 

    return 0; 
}

// LOAD ELEMENTS FROM TXT FILES TO ARRAYS

//loads student data using dynamic memory allocation
Student *loadStudents(int *numStudents)
{
    FILE *f_stu = fopen("students.txt", "r");
    int id; 
    char fName[MAXSTRLN];
    char lName[MAXSTRLN]; 
    date dob; 

    fscanf(f_stu, "%d", numStudents); 

    Student *ArrayOfStudents = (Student*) malloc(*numStudents * sizeof(Student));

    for(int i = 0; i < *numStudents ; i++)
    {
        fscanf(f_stu, "%d %s %s %d %d %d", &id, fName, lName, &dob.day, &dob.month, &dob.year);

        int fNameLength = strlen(fName) + 1; 
        ArrayOfStudents[i].fName = (char *) malloc(strlen(fName)*sizeof(char)); 
        strcpy(ArrayOfStudents[i].fName, fName); 

        int lNameLength = strlen(lName) + 1; 
        ArrayOfStudents[i].lName = (char *) malloc(strlen(lName)*sizeof(char)); 
        strcpy(ArrayOfStudents[i].lName, lName); 

        ArrayOfStudents[i].id = id; 
        ArrayOfStudents[i].dob.day = dob.day;
        ArrayOfStudents[i].dob.month = dob.month; 
        ArrayOfStudents[i].dob.year = dob.year;  

    }

    fclose(f_stu); 

    return ArrayOfStudents; 

}

//loads enrollment data using dynamic memory allocation
Enrollment *loadEnrollment(int *numEnrollments)
{
    FILE *f_en = fopen("enrollment.txt", "r");
    int id; 
    char cid[MAXSTRLN]; 
    char sem[MAXSTRLN]; 
    float credit; 

    fscanf(f_en, "%d", numEnrollments); 

    Enrollment *ArrayOfEnrollment = (Enrollment*) malloc(*numEnrollments * sizeof(Enrollment)); 

    for(int i = 0; i < *numEnrollments; i++)
    {
        fscanf(f_en, "%d %s %s %f", &id, cid, sem, &credit); 

        int cidLength = strlen(cid) + 1; 
        ArrayOfEnrollment[i].cid = (char *) malloc(strlen(cid)*sizeof(char)); 
        strcpy(ArrayOfEnrollment[i].cid, cid); 

        int semLength = strlen(sem) + 1; 
        ArrayOfEnrollment[i].semester = (char *) malloc(strlen(sem)*sizeof(char));
        strcpy(ArrayOfEnrollment[i].semester, sem); 

        ArrayOfEnrollment[i].id = id;
        ArrayOfEnrollment[i].totalCredit = credit;

        
    }

    fclose(f_en); 

    return ArrayOfEnrollment; 

}

//loads course data using dynamic memory allocation
Course *loadCourses(int *numCourses)
{
    FILE *f_crs = fopen("courses.txt", "r+");
    char cid[MAXSTRLN];
    char cName[MAXSTRLN];
    float credit;

    fscanf(f_crs, "%d", numCourses); 

    Course *ArrayOfCourses = (Course*) malloc(*numCourses * sizeof(Course)); 

    for(int i = 0; i < *numCourses ; i++)
    {
        fscanf(f_crs, "%s %s %f", cid, cName, &credit); 

        int cidLength = strlen(cid) + 1; 
        ArrayOfCourses[i].cid = (char *) malloc(strlen(cid)*sizeof(char)); 
        strcpy(ArrayOfCourses[i].cid, cid); 

        int cNameLength = strlen(cName) + 1; 
        ArrayOfCourses[i].courseName = (char *) malloc(strlen(cName)*sizeof(char)); 
        strcpy(ArrayOfCourses[i].courseName, cName); 

        ArrayOfCourses[i].credit = credit; 
    }

    fclose(f_crs);

    return ArrayOfCourses; 

}

/*
    pre-condition: takes in student variable
    post-condition: print student's id, fname, lname, dob and courses, semester, score, and letter grade
*/
void display_student(Student s)
{
    printf("%d %s %s %d/%d/%d\n",s.id, s.fName, s.lName, s.dob.month, s.dob.day, s.dob.year); 
}

/*
    pre-condition: takes in course variable
    post-condition: print course name, credit, students in course
*/
void display_course(Course c)
{

}

/*
    pre-condition:
    post-condition:
*/
void menu(Student *ArrayOfStudents, int amountStudents, Course *ArrayOfCourses,
            int amountCourses, Enrollment *ArrayOfEnrollments, int amountEnrolls)
{
    while(1)
    {
        printf("==================\n"); 
        char input1[MAXSTRLN]; 
        char input2[MAXSTRLN]; 
        char input3[MAXSTRLN]; 
        scanf("%s %s", input1, input2); 

        if( strcmp(input1, "search_students") == 0)
        { 
            search_students(ArrayOfStudents, amountStudents, input2, ArrayOfEnrollments, amountEnrolls, ArrayOfCourses, amountCourses); 
        }
        else if( strcmp(input1, "search_course") == 0)
        {
            search_courses(ArrayOfStudents, amountStudents, input2, ArrayOfEnrollments, amountEnrolls, ArrayOfCourses, amountCourses); 
        }
        else if( strcmp(input1, "add_course") == 0)
        {
            add_course(ArrayOfCourses, amountCourses);
            loadCourses(&amountCourses);
        }
        else if( strcmp(input1, "count") == 0)
        {
            count(ArrayOfStudents,amountStudents,ArrayOfCourses,
                    amountCourses,ArrayOfEnrollments,amountEnrolls); 
        }
        else if( strcmp(input1, "sort") == 0)
        {
            sort(ArrayOfStudents, amountStudents); 
        }
        else if( strcmp(input1, "exit") == 0)
        {
            exitp(ArrayOfStudents,amountStudents, ArrayOfCourses,
                        amountCourses, ArrayOfEnrollments, amountEnrolls); 
        }
    }
}

/*
    pre-condition: user input type of search to look for student 
    post-condition: based on search option, execute specific scanf and search
*/
Student *search_students(Student *ArrOfStu, int numStudents, char *option, Enrollment *ArrOfEnr, int numEnroll, Course *CourseList, int numCourse)
{
    if(strcmp(option, "lname") == 0)
    {
        char inq[MAXSTRLN];
        scanf("%s", inq); 
        for(int i = 0; i < numStudents; i++)
        {
            if(strcmp(ArrOfStu[i].lName, inq ) == 0)
            {
                printf("------------------\n");
                display_student(ArrOfStu[i]);
                search_enrollment(ArrOfEnr,numEnroll, CourseList, numCourse, ArrOfStu[i]); 
                printf("------------------\n");
            } 
            else if( i == numStudents)
            {
                printf("------------------\n");
                printf("not found\n");
                printf("------------------\n");
            }
        }
    }   
    else if(strcmp(option, "fname") == 0 )
    {
        char inq[MAXSTRLN];
        scanf("%s", inq); 
        for(int i = 0; i < numStudents; i++)
        {
            if(strcmp(ArrOfStu[i].fName, inq ) == 0)
            {
                printf("------------------\n");
                display_student(ArrOfStu[i]);
                search_enrollment(ArrOfEnr,numEnroll, CourseList, numCourse, ArrOfStu[i]); 
                printf("------------------\n");
            }
            else if(i == numStudents)
            {
                printf("------------------\n");
                printf("not found\n");
                printf("------------------\n");
            }
        }
    }
    else if(strcmp(option, "id") == 0) 
    {
        int inq;
        scanf("%d", &inq); 
        for(int i = 0; i < numStudents; i++)
        {
            //printf("%s %d", ArrOfStu[i].fName, ArrOfStu[i].id); 
            if(inq == ArrOfStu[i].id)
            {
                printf("------------------\n");
                display_student(ArrOfStu[i]);
                search_enrollment(ArrOfEnr,numEnroll, CourseList, numCourse, ArrOfStu[i]);
                printf("------------------\n"); 
            }
            else if(i == numStudents)
            {
                printf("------------------\n");
                printf("not found\n");
                printf("------------------\n");
            }
        }
    }
    else if(strcmp(option, "byear") == 0)
    {
        int inq;
        scanf("%d", &inq); 
        for(int i = 0; i < numStudents; i++)
        {
            if(ArrOfStu[i].dob.year == inq)
            {
                printf("------------------\n");
                display_student(ArrOfStu[i]);
                search_enrollment(ArrOfEnr,numEnroll, CourseList, numCourse, ArrOfStu[i]);
                printf("------------------\n");
            }
            else if(i == numStudents)
            {
                printf("------------------\n");
                printf("not found\n");
                printf("------------------\n");
            }
        }
    }
}


/*
    pre-condition: given enrollment and student
    post-condition: prints enrollment details based off student 
*/
void search_enrollment(Enrollment *EnrollList, int numEnroll, 
                        Course *CourseList, int numCourse, Student s)
{
    for(int j = 0; j < numEnroll; j++)
    {
        if(s.id == EnrollList[j].id)
        {
            for(int h = 0; h < numCourse; h++)
            {
                //if the course id matches with the correct enrollment course id
                if( strcmp(CourseList[h].cid,EnrollList[j].cid) == 0)
                {
                    //course id course name semester credit letter grade
                    printf("%s %s %.0f ",EnrollList[j].cid, EnrollList[j].semester, EnrollList[j].totalCredit);
                    printf("%c\n", getGrade(EnrollList[j].totalCredit));
                }
            }
        }
    }
}

/*
    pre-condition: prompt user for option
    post-condition:searches course based off course id or course id and semester
*/
Course *search_courses(Student *ArrOfStu, int numStudents, 
                        char *option, Enrollment *ArrOfEnr, int numEnroll, Course *ArrOfCourse, int numCourses) 
{ 
    //user's inquiry 
    char inq[MAXSTRLN];

    //CID SEARCH
    if(strcmp(option, "cid") == 0)
    {
        scanf("%s", inq); 
        //iterate through courses
        for(int a = 0; a < numCourses; a++)
        {
            //if course ids match
            if(strcmp(ArrOfCourse[a].cid, inq) == 0)
            {
                //print course name and credit
                printf("%s %.0f\n",ArrOfCourse[a].courseName, ArrOfCourse[a].credit);
                for(int h = 0; h < numEnroll; h++)
                {
                    //find students in the course
                    if(strcmp(ArrOfEnr[h].cid, inq) == 0)
                    {
                        for(int j = 0; j < numStudents; j++)
                        {
                            //check between student id and enrollment id
                            //print first name, last name, semester, grade and letter grade
                            if(ArrOfStu[j].id == ArrOfEnr[h].id )
                                printf("%s %s %s %.0f %c\n", 
                                            ArrOfStu[j].fName, ArrOfStu[j].lName,
                                                    ArrOfEnr[h].semester, ArrOfEnr[h].totalCredit, getGrade(ArrOfEnr[h].totalCredit));
                        }
                    }
                }
            }
            else if( a == numCourses)
            {
                printf("------------------\n");
                printf("not found\n");
                printf("------------------\n");
            }
        }
    } //CID SEM SEARCH
    else if(strcmp(option, "cid_semester") == 0)
    {
        char semester[MAXSTRLN];
        int flag =0;  
        scanf("%s %s",inq, semester); 
        for(int i = 0; i < numEnroll; i++)
        {
            //user given courseID and semester must match in same line
            if(strcmp(ArrOfEnr[i].cid, inq) == 0)
            {
                if(strcmp(ArrOfEnr[i].semester, semester) == 0)
                {
                    //print course, course credit and students in course and same semester. with their respective grades
                    for(int h = 0; h < numCourses; h++)
                    {
                        if(strcmp(ArrOfCourse[h].cid , inq) == 0)
                        {
                            flag++; 
                            if(flag==1)
                            printf("%s %.0f\n",ArrOfCourse[h].courseName, ArrOfCourse[h].credit); 
                            for(int j = 0; j < numStudents; j++)
                            {
                                //print first name, last name, semester, grade and letter grade
                                if(ArrOfStu[j].id == ArrOfEnr[i].id )
                                    printf("%s %s %s %.0f %c\n", 
                                            ArrOfStu[j].fName, ArrOfStu[j].lName,
                                                ArrOfEnr[i].semester, ArrOfEnr[i].totalCredit, getGrade(ArrOfEnr[i].totalCredit));
                            }
                        }
                    }
                }
            }
            else if( i == numEnroll)
            {
                printf("------------------\n");
                printf("not found\n");
                printf("------------------\n");
            }
        }
    }
}

/*
    pre-condition:
    post-condition:
*/

void add_course(Course *CourseList, int numOfCourse) 
{
    FILE *ifp = fopen("courses.txt", "r+");
    char newID[MAXSTRLN]; 
    char newName[MAXSTRLN];
    float newCredit; 
    int flag = 0; 
    scanf("%s %s %f", newID, newName, &newCredit); 

    //check for uniqueness
    for(int i = 0; i < numOfCourse; i++)
    {
        if( strcmp(CourseList[i].cid, newID) != 0 )
        {
            flag = 1; 
        }
        else
        {
            printf("------------------\n");
            printf("violation of course id uniqueness. Cannot add the record.\n");
            printf("------------------\n");
            break; 
        } 

    }

    if(flag == 1)
    {
        fseek(ifp, 0, SEEK_END); 
        CourseList = (Course*)realloc(CourseList, (numOfCourse+1)*sizeof(Course)); 
        strcpy(CourseList[numOfCourse].cid,newID);
        strcpy(CourseList[numOfCourse].courseName,newName); 
        CourseList[numOfCourse].credit = newCredit; 
        numOfCourse++; 

    }

}

/*
    pre-condition:
    post-condition:
*/
void count(Student *arrOfStu, int numOfStu, Course *arrOfCo, int numOfCo,
                 Enrollment *arrOfEnr, int numOfEnr)
{
    //user input
    char inq[MAXSTRLN];
    scanf("%s",inq); 

    //different cases
    if( strcmp(inq, "students"))
    {
        int count; 
        for(int i = 0; i < numOfStu; i++)
            count++; 
        printf("total students %d", count); 
    }
    else if( strcmp(inq, "students_course"))
    {
        for(int i = 0; i < numOfEnr; i++)
        {
            for(int j = 0; j < numOfStu; j++)
                if( strcmp(arrOfEnr[i].id, arrOfStu[j].id) == 0)
                {

                }
        }
    }
    else if( strcmp(inq, "students_semester"))
    {
        char completed_list[2][2];

        int student_count[20];

        int tracker = 0;

        for(int i = 0; i < numOfEnr; i++)
        {

            for(int j = 0; j < 20; j++)
            student_count[i]++; 
        }
    }
}

/*
    pre-condition:
    post-condition:
*/
void sort(Student *StudentList, int numOfStu)
{
  //selection sort

    int temp, min_index, i = 0;

    for(i = 0; i < numOfStu-1; i++)
    {
        //printf("\nIteration# %d\n", i+1);
        //set minimum index 
        min_index = StudentList[i].id; 

        for(int j = i+1; j < numOfStu-1 ; j++)
        {
            //if min is greater than arr[k], min is updated and moved to the front (arr[i]) . 
            if(StudentList[j].id > StudentList[min_index].id)
            {
                min_index = StudentList[j].id;
            }
            
        }
            //outside of nested loop because 
            temp = StudentList[i].id;
            StudentList[i].id = StudentList[min_index].id; 
            StudentList[min_index].id = temp; 

    } 

    for(int j = 0; j < numOfStu; j++)
        display_student(StudentList[j]);

}

/*
    pre-condition: takes enrollment 
    post-condition: returns letter grade based off credit
*/
char getGrade(float score)
{
   //test cases for letter grade
   if(score >= 90.00)
   {
       //printf("A"); 
       return 'A'; 
   }
   else if(score > 80.00 && score <= 89.99)
   {
       //printf("B");
       return 'B'; 
   }
   else if(score > 70.00 && score <= 79.99)
   {
       //printf("C");
       return 'C'; 
   }
   else if( score > 60.00 && score <= 69.99)
   {
       //printf("D");
       return 'D'; 
   }
   else if( score < 60.00)
   {
       //printf("F");
       return 'F'; 
   }

}

/*
    pre-condition:
    post-condition:
*/
void free_memory(Student *ArrayOfStudents, int numOfStu, Course *ArrayOfCourses, 
                    int numOfCourses, Enrollment *ArrayOfEnrolls, int numOfEnrolls)
{
    //free student memory
    for(int i = 0; i < numOfStu; i++)
    {
        free(ArrayOfStudents[i].lName); 
        free(ArrayOfStudents[i].fName); 
    }
    free(ArrayOfStudents);

    //free course memory
    for(int i = 0; i < numOfCourses; i++)
    {
        free(ArrayOfCourses[i].cid);
        free(ArrayOfCourses[i].courseName); 
    }
    free(ArrayOfCourses); 

    //free enrollment memory
    for(int i = 0; i < numOfCourses; i++)
    {
        free(ArrayOfEnrolls[i].cid);
        free(ArrayOfEnrolls[i].semester); 
    }
    free(ArrayOfEnrolls); 
}

/*
    pre-condition:
    post-condition:
*/
void exitp(Student *ArrayOfStudents, int amountStudents, Course *ArrayOfCourses,
            int amountCourses, Enrollment *ArrayOfEnrollments, int amountEnrolls)
{
    //free memory
    free_memory(ArrayOfStudents, amountStudents, 
                ArrayOfCourses, amountCourses,ArrayOfEnrollments,amountEnrolls);


    printf("\nBye!");

    exit(1);

}

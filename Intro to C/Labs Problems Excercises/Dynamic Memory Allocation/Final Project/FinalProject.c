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
    char *cid; //coourse id
    char *semester; 
    char *cName; 
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
Student *search_students(Student *ArrOfStu, int numStudents, char *option, Enrollment *ArrOfEnr, int numEnroll); 
    void search_enrollment(Enrollment *EnrollList, int numEnroll, Student s);
Course *search_courses(Student *ArrOfStu, int numStudents, //EXTRA FUNC
                        char *option, Enrollment *ArrOfEnr, int numEnroll, Course *ArrOfCourse, int numCourses); 
void add_course(); 
char getGrade(Enrollment s); //EXTRA FUNC
void count(); 
void sort(); 
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

        printf("\n%d",id); //DEBUG

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
    char cName[MAXSTRLN];
    char sem[MAXSTRLN]; 
    float credit; 

    fscanf(f_en, "%d", numEnrollments); 

    Enrollment *ArrayOfEnrollment = (Enrollment*) malloc(*numEnrollments * sizeof(Enrollment)); 

    for(int i = 0; i < *numEnrollments; i++)
    {
        fscanf(f_en, "%d %s %s %f", &id, cid, cName, &credit); 

        int cidLength = strlen(cid) + 1; 
        ArrayOfEnrollment[i].cid = (char *) malloc(strlen(cid)*sizeof(char)); 
        strcpy(ArrayOfEnrollment[i].cid, cid); 

        int cNameLength = strlen(cName) + 1; 
        ArrayOfEnrollment[i].cName = (char *) malloc(strlen(cName)*sizeof(char)); 
        strcpy(ArrayOfEnrollment[i].cName, cName); 

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
        printf("=================="); 
        char input1[MAXSTRLN]; 
        char input2[MAXSTRLN]; 
        char input3[MAXSTRLN]; 

        printf("Please enter command "); 
        scanf("%s %s", input1, input2); 

        if( strcmp(input1, "search_students") == 0)
        { 
            printf("entered search part 1\n"); //debug
            search_students(ArrayOfStudents, amountStudents, input2, ArrayOfEnrollments, amountEnrolls); 
        }
        else if( strcmp(input1, "search_courses") == 0)
        {
            search_courses(ArrayOfStudents, amountStudents, input2, ArrayOfEnrollments, amountEnrolls, ArrayOfCourses, amountCourses); 
        }
        else if( strcmp(input1, "add_course") == 0)
        {
            add_course();
        }
        else if( strcmp(input1, "count") == 0)
        {
            count(); 
        }
        else if( strcmp(input1, "sort") == 0)
        {
            sort(); 
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
Student *search_students(Student *ArrOfStu, int numStudents, char *option, Enrollment *ArrOfEnr, int numEnroll)
{
    if(strcmp(option, "lname") == 0)
    {
        char inq[MAXSTRLN];
        scanf("%s", inq); 
        for(int i = 0; i < numStudents; i++)
        {
            if(strcmp(ArrOfStu[i].lName, inq ) == 0)
            {
                printf("------------------");
                display_student(ArrOfStu[i]);
                search_enrollment(ArrOfEnr,numEnroll,ArrOfStu[i]); 
                printf("------------------");
            }
            else
            {
                printf("------------------");
                printf("not found");
                printf("------------------");
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
                printf("------------------");
                display_student(ArrOfStu[i]);
                search_enrollment(ArrOfEnr,numEnroll,ArrOfStu[i]); 
                printf("------------------");
            }
            else
            {
                printf("------------------");
                printf("not found");
                printf("------------------");
            }
        }
    }
    else if(strcmp(option, "id") == 0) 
    {
        printf("entered search part 2\n"); //DEBUG
        int inq;
        scanf("%d", &inq); 
        for(int i = 0; i < numStudents; i++)
        {
          printf("\nLOOKING FOR %d\n", inq); //DEBUG
          printf("%s %d", ArrOfStu[i].fName, ArrOfStu[i].id); 
            if(inq == ArrOfStu[i].id)
            {
                printf("------------------");
                display_student(ArrOfStu[i]);
                search_enrollment(ArrOfEnr,numEnroll,ArrOfStu[i]);
                printf("------------------"); 
            }
            else
            {
                printf("------------------");
                printf("not found");
                printf("------------------");
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
                printf("------------------");
                display_student(ArrOfStu[i]);
                search_enrollment(ArrOfEnr,numEnroll,ArrOfStu[i]); 
                printf("------------------");
            }
            else
            {
                printf("------------------");
                printf("not found");
                printf("------------------");
            }
        }
    }
}


/*
    pre-condition: given enrollment and student
    post-condition: prints enrollment details based off student 
*/
void search_enrollment(Enrollment *EnrollList, int numEnroll, Student s)
{
    for(int j = 0; j < numEnroll; j++)
    {
        if(s.id == EnrollList[j].id)
        {
            //course id course name semester credit letter grade
            printf("%s %s %s %d %c",EnrollList[j].cid, 
                    EnrollList[j].cName, EnrollList[j].semester, EnrollList[j].totalCredit, getGrade(EnrollList[j]));
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

    //search based on course id
    if(strcmp(option, "cid"))
    {
        //iterate through courses
        for(int i = 0; i < numCourses; i++)
        {
            //if course ids match
            if(strcmp(ArrOfCourse[i].cid, inq) == 0)
            {
                //print course name and credit
                printf("%s %d",ArrOfCourse[i].courseName, ArrOfCourse[i].credit);
                for(int h = 0; h < numEnroll; h++)
                {
                    //find students in the course
                    if(ArrOfEnr[h].cid == inq)
                    {
                        for(int j = 0; j < numStudents; j++)
                        {
                            //print first name, last name, semester, grade and letter grade
                            if(ArrOfStu[j].id == ArrOfEnr[h].id )
                                printf("%s %s %s %f %c", 
                                            ArrOfStu[j].fName, ArrOfStu[j].lName,
                                                    ArrOfEnr[h].semester, ArrOfEnr[h].totalCredit, getGrade(ArrOfEnr[h]));
                        }
                    }
                }
            }
        }
    }
    else if(strcmp(option, "cid_semester"))
    {
        char semester[MAXSTRLN]; 
        scanf("%s %s",inq, semester); 
        for(int i = 0; i < numEnroll; i++)
        {
            if(strcmp(ArrOfEnr[i].cid, inq) == 0 && strcmp(ArrOfEnr[i].semester, semester) == 0)
            {
                //print course, course credit and students in course and same semester. with their respective grades
                for(int h = 0; h < numCourses; h++)
                {
                    if(ArrOfCourse[h].cid == ArrOfEnr[i].cid)
                        printf("%s %d\n",ArrOfCourse[h].courseName, ArrOfCourse[h].credit); 
                    for(int j = 0; j < numStudents; j++)
                        {
                            //print first name, last name, semester, grade and letter grade
                            if(ArrOfStu[j].id == ArrOfEnr[i].id )
                                printf("%s %s %s %d %c", 
                                            ArrOfStu[j].fName, ArrOfStu[j].lName,
                                                    ArrOfEnr[i].semester, ArrOfEnr[i].totalCredit, getGrade(ArrOfEnr[i]));
                        }
                }
                
            }
        }
    }
}

/*
    pre-condition:
    post-condition:
*/
void add_course()
{
    //search if the course added is unique 
    //use realloc ? 
    //if unique, then add to course.txt
}

/*
    pre-condition:
    post-condition:
*/
void count()
{

}

/*
    pre-condition:
    post-condition:
*/
void sort()
{
  //selection sort? 
}

/*
    pre-condition: takes enrollment 
    post-condition: returns letter grade based off credit
*/
char getGrade(Enrollment e)
{
    float score = e.totalCredit;
   //test cases for letter grade
   if(score > 90)
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
   else if( score > 60 && score <= 69.99)
   {
       return 'D'; 
   }
   else if( score < 60)
   {
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
        free(ArrayOfEnrolls[i].cName); 
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

    printf("Bye");

    exit(1);

}

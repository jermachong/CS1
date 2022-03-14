/*
    Jeremy Achong
    12.1.21

        Employee Management - Dynamic Memory Allocation Vers.

        This program is practice for the lab exam
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "leak_detector_c.h"

#define MAXSTRLN 51

//structures 
typedef struct Employee{

    char *eid; 
    char *lname;
    int sal; 

}Employee; 

typedef struct Dept{

    char *eid;
    char *dname;

}Dept; 

//FUNCTIONS

/*
pre-condition
post-condition
*/
Employee *readEmp(int *empCount)
{
    FILE *f_emp = fopen("emp.txt", "r"); 
    char strName[MAXSTRLN]; //static array to read string from file
    char eId[MAXSTRLN]; //static array to read string from file
    int salary;

    fscanf(f_emp, "%d", empCount);


    //allocate memory for *empCount number of Employee [dereferencing as empCount is a pointer]
    Employee *ArrayOfEmployees = malloc(sizeof(Employee)* (*empCount));


    //important note: Although ArrayOfEmployees is a pointer of type Employee, we will be using it like an array of Emp
    //In that case, we have to use '.' to access the structure instead of '->' 

    for(int i = 0; i < *empCount; i++)
    {
        fscanf(f_emp, "%s %s %d", eId, strName, &salary);

        //length + 1 
        int eidLength = strlen(eId) + 1; 

        //allocating memory to store eid for this employee
        ArrayOfEmployees[i].eid = (char *)malloc(strlen(eId)* sizeof(char)); 

        //now copy the string
        strcpy(ArrayOfEmployees[i].eid, eId); 

        //we will allocate this amount of space to store this employee's lname
        int nameLength = strlen(strName) + 1; 

        //allocating memory to store lname for this employee 
        ArrayOfEmployees[i].eid = (char *)malloc(strlen(strName)* sizeof(char)); 

        //now copy the string
        strcpy(ArrayOfEmployees[i].lname, strName); 

        //store the salary
        ArrayOfEmployees[i].sal = salary;  //static variable
    }

    //avoid memory leak 
    fclose(f_emp); 

    //now return the new array which is filled with alll the emp data
    return ArrayOfEmployees; 
}

/*
pre-condition
post-condition
*/
Dept* readDept(FILE *f_dept, int deptCount)
{

    char eId[MAXSTRLN];
    char dname[MAXSTRLN];

    Dept *ArrayOfDepartments = (Dept *) malloc(sizeof(Dept) * deptCount); 

    //f_dept was already opened and the first int was already read by the main fnction,
    for(int i = 0; i < deptCount; i++)
    {
        fscanf(f_dept, "%s %s", eId, dname); 

        //length + 1 to be used to malloc for this eid
        int eidLength = strlen(eId) + 1; 

        //allocating memory to store eid for this employee
        ArrayOfDepartments[i].eid = (char *) malloc(strlen(eId)*sizeof(char)); 

        //now copy the string
        strcpy(ArrayOfDepartments[i].eid, eId);

        //we will allocate this amount of space to store this dname
        int dnameLength = strlen(dname) + 1; 

        //allocating memory to store dname for this entry
        ArrayOfDepartments[i].eid = (char *) malloc(strlen(dname)*sizeof(char)); 

        //now copy the string
        strcpy(ArrayOfDepartments[i].dname, dname); 
    }

    fclose(f_dept); 

    //return array with dept info
    return ArrayOfDepartments; 

}


/*
pre-condition takes in employee array, total # of employees, department array, and total # of departments
post-condition prints out all the details of the employees and their respective departments
*/
void printAll(Employee *arr, int totalEmp, 
                Dept *arr2, int totalDept  )
{

    printf("Printing the list of Employees:\n=================\n"); 
    for(int i = 0; i < totalEmp; i++) {
        printf("ID: %s\tLName: %s\t Salary: %d\t", 
                    arr[i].eid, arr[i].lname, arr[i].sal); 
        int j = 0;
        for(j = 0; j < totalDept; j++)
        {
            if(strcmp(arr2[j].eid , arr[i].eid) == 0) {
                printf("Department: %s\n", arr2[j].dname);
                break; 
            }
            
        }

        if(j == totalDept)
            printf("Department: None\n", arr2[j].dname);
    }

}

/*
pre-condition given employee array, # of employees, department array, total number of departments, employee last name to search
post-condition print whether or not the employee was found
*/
void search_employee(Employee arr[], int totalEmp, Dept arr2[], int totalDept, 
            char qStr[] )
{
    int i; 
    for(i = 0; i < totalEmp; i++){

            //print found employee
            if(strcmp(qStr, arr[i].lname) == 0) {
                printf("ID: %s\tLName: %s\t Salary: %d\t", 
                    arr[i].eid, arr[i].lname, arr[i].sal);

                int j; //nested loop to iterate through department
                for(j = 0; j < totalDept; j++)
                {
                    if(strcmp(arr2[j].eid , arr[i].eid) == 0) {
                        printf("Department: %s\n", arr2[j].dname);
                        break;  //found department
                    }
                }
                    //department not found
                    if(j == totalDept)
                        printf("Department: None\n", arr2[j].dname); 

                break;
            }

    
    } //if the loop hits the end, then the employee was never found
    if(i == totalEmp) 
        printf("Employee %s Not Found\n", qStr);
    
}

/*
pre-condition given employee array, # of employees, department array, total number of departments, department name to search
post-condition returns the total salary of searched department
*/
int totalSal_dept(Employee arr[], int totalEmp, Dept arr2[], int totalDept, char qStr[])
{
    int total = 0; 
    for(int i = 0; i < totalDept; i++)
    {   
        if(strcmp(qStr,arr2[i].dname) == 0) {
        int j; 
        for(j = 0 ; j < totalEmp; j++)
            if(strcmp(arr2[j].eid , arr[i].eid) == 0)
                total += arr[i].sal; 
        }
    }

    return total;  
}

/*
pre-condition recieves two dynamically allocated array and their sizes
post-condition free all the memory
*/
void free_memory(Employee *EmpList, int total_emp, Dept *DeptList, int total_dept)
{
    //we need to free
    for(int i = 0; i < total_emp; i++)
    {
        free(EmpList[i].eid);
        free(EmpList[i].lname); 
    }
    //we have free all the strings inside each emp. Now free the EmpList
    free(EmpList);

    //do the same for deptList
    for(int i = 0; i < total_dept; i++)
    {
        free(DeptList[i].eid);
        free(DeptList[i].dname); 
    }
    //we have free all the strings inside each dept. Now free the DeptList
    free(DeptList);

}


//driver function
int main(void) {

  atexit(report_mem_leak); //for memory leak detector. //Disable this line if you are having trouble

   Employee *EmpList;
   Dept *DeptList;
   int total_emp;
   
  EmpList = readEmp(&total_emp); //after coming back form the function total_emp will have to correct number of emp in the file
// this uses a different strategy compared to the readEmp as part of the practice
   FILE *f_dept = fopen("dept.txt","r");
   int total_dept;
   fscanf(f_dept, "%d", &total_dept);
  DeptList = readDept(f_dept, total_dept); //just to show another way by passing a file pointer which is already opened

 printAll(EmpList, total_emp, DeptList, total_dept);

    printf("Query Phase\n");

    //open query file
    FILE *qf = fopen("query.txt", "r"); 

    int numQueries; //set number of queries
    fscanf(qf, "%d", &numQueries); 

    //scan and execute queries based on number of queries
    for(int i = 0; i < numQueries ; i++)
    {
        int queryType; 
        char qString[100];

        //figure out query type
        fscanf(qf, "%d %s", &queryType, qString);

        if(queryType == 1) //call search_employee
            search_employee(EmpList, total_emp, 
                        DeptList, total_dept,qString); 
        else if(queryType == 2) //call totalSal_dept()
            printf("Total Salary of Department %s is %d\n", qString,
                         totalSal_dept(EmpList, total_emp, DeptList, total_dept, qString));
        
    }

    //close files and EOF
    fclose(qf); 
    return 0; 
}
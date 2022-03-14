/*
    Jeremy Achong
    11.24.21

        Employee Management 
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE_EMP 100
#define SIZE_DEPT 100

//structures 
typedef struct Employee{

    char eid[10];
    char lname[50];
    int sal; 

}Employee; 

typedef struct Dept{

    char eid[10];
    char dname[50];

}Dept; 

//functions

/*
pre-condition
post-condition
*/
int readEmp(Employee arr[SIZE_EMP])
{
    FILE *f_emp = fopen("emp.txt", "r"); 

    char eId[10];
    char lname[50];
    int salary = 0;  
    int empCount = 0; 

    while(fscanf(f_emp, "%s %s %d", eId, lname, &salary) != EOF){
        strcpy(arr[empCount].eid, eId); 
        strcpy(arr[empCount].lname, lname); 
        arr[empCount].sal = salary; 

        empCount++; 
    }

    fclose(f_emp);
    return empCount; 
}

/*
pre-condition
post-condition
*/
void readDept(Dept arr[], int *numOfDept)
{
    FILE *f_dept = fopen("dept.txt", "r"); 

    char eid[10]; 
    char dname[50]; 

    int deptCount = 0; 

    while(fscanf(f_dept, "%s %s", eid, dname) != EOF){
        strcpy(arr[deptCount].eid, eid); 
        strcpy(arr[deptCount].dname, dname); 

        deptCount++; 
    }   

    fclose(f_dept); 
    *numOfDept = deptCount;  


}

/*
pre-condition takes in employee array, total # of employees, department array, and total # of departments
post-condition prints out all the details of the employees and their respective departments
*/
void printAll(Employee arr[], int totalEmp, 
                Dept arr2[], int totalDept  )
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


//driver function
int main (void)
{
    //Employee List & Department List
    Employee EmpList[SIZE_EMP]; //EmpList[0].lname = Adam
    Dept DeptList[SIZE_DEPT]; 

    int total_emp = 0; 
    int total_dept = 0; 

    //read emp and dept lists
    total_emp = readEmp(EmpList); 
    readDept(DeptList, &total_dept); 

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
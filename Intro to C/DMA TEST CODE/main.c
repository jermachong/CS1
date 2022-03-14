//Remember, you need the input file to run this code
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include	"leak_detector_c.h" //make sure to have both leak detector c and h file in your project



#define MAXSTRLN 51

typedef struct Employee
{
  char *eid; //we must need malloc to do strcpy to store string to eid
  char *lname; //we must need malloc to do strcpy to store string to lname
  int sal;
} Employee;

typedef struct Dept
{
  char *eid; //need malloc for this as well
  char *dname; //need malloc for this as well
} Dept;


//Read all employees from file and returns the dynamically allcoated Employee array. Also, updates the passed reference with the empCount
Employee* readEmp(int *empCount){

	FILE *f_emp = fopen("emp.txt","r");
    char strName[MAXSTRLN]; //this is a static array to read the string form the file
    char eId[MAXSTRLN]; //this is a static array to read the string form the file
    int salary;

	fscanf(f_emp, "%d", empCount); //no need to use & as empCount is a pointer

	Employee *ArrayOfEmployees = (Employee*) malloc(*empCount * sizeof(Employee)); //allocate memory for *empCount number of Employee [dereferencing as empCount is a pointer

	//important note: Although ArrayOfEmployees is a pointer of type Employee, we will be using it like an array of Employee using index. In that case, we have to use dot (.), to access the structure members.

	for(int i=0; i<*empCount; i++)
    {
        fscanf(f_emp, "%s %s %d ", eId, strName, &salary);

        int eidLength = strlen(eId) + 1;//length  + 1 to be used to malloc for this eid (exact length. No waste of space
        ArrayOfEmployees[i].eid = (char *) malloc(strlen(eId)*sizeof(char)); // allocating memory to store eid for this employee
        strcpy(ArrayOfEmployees[i].eid, eId); //now copy the string

        int nameLength = strlen(strName) + 1; //we will allocate this amount of space to store this employee's lname
        ArrayOfEmployees[i].lname = (char *) malloc(strlen(strName)*sizeof(char)); // allocating memory to store lname for this employee
        strcpy(ArrayOfEmployees[i].lname, strName); //now copy the string

        ArrayOfEmployees[i].sal = salary;


    }

    fclose(f_emp); //close the file as we are done

    //empCount already updated the int passed to this function

    //now return the new array which is filled up with all the emp data
    return ArrayOfEmployees;
}


//Read all department (deptCount number of dept) from file and returns the dynamically allopcated Dept array. Note that the deptCount was already read by the caller and file is already opened
Dept* readDept(FILE *f_dept, int deptCount){

    char eId[MAXSTRLN];
	char dname[MAXSTRLN];

	Dept *ArrayOfDepartments = (Dept*) malloc(deptCount * sizeof(Dept));

	//f_dept was already opened and the first int was already read by the main function. Now, keep moving from there
	for(int i=0; i<deptCount; i++)
    {
        fscanf(f_dept, "%s %s", eId, dname);

        int eidLength = strlen(eId) + 1;//length  + 1 to be used to malloc for this eid (exact length. No waste of space
        ArrayOfDepartments[i].eid = (char *) malloc(strlen(eId)*sizeof(char)); // allocating memory to store eid for this employee
        strcpy(ArrayOfDepartments[i].eid, eId); //now copy the string

        int nameLength = strlen(dname) + 1; //we will allocate this amount of space to store this dname
        ArrayOfDepartments[i].dname = (char *) malloc(strlen(dname)*sizeof(char)); // allocating memory to store dname for this entry
        strcpy(ArrayOfDepartments[i].dname, dname); //now copy the string
    }

    fclose(f_dept); //completed reading the data. Now free the memory

    return ArrayOfDepartments;
}




void printAll(Employee Arr[], int totalEmp, Dept ArrayOfDepartments[], int totalDept){
  int i, j;
  printf("Printing the list of Employees:\n=================\n");
  for(i= 0; i< totalEmp; i++)
  {
    printf("ID: %s\tLName: %s\tSalary: %d", Arr[i].eid, Arr[i].lname, Arr[i].sal);

    for(j = 0; j<totalDept; j++)
    {
        if (strcmp(ArrayOfDepartments[j].eid, Arr[i].eid) == 0)
        {
            printf("\tDepartment: %s", ArrayOfDepartments[j].dname);
            break;

        }

    }
    if(j==totalDept)
        printf("\tDepartment: None");

    printf("\n");


  }

}
void search_employee(Employee *Arr, int totalEmp, Dept *ArrayOfDepartments, int totalDept, char qStr[])
{
   // printf("qstr %s", qStr);
  int i, j;

  for(i= 0; i< totalEmp; i++)
  {
      if(strcmp(Arr[i].lname, qStr) == 0)
      {
           printf("ID: %s\tLName: %s\tSalary: %d", Arr[i].eid, Arr[i].lname, Arr[i].sal); //replace the \t with \n in the lab
            //Students need to modify this code to print department name after printing the salary.
            for(j = 0; j<totalDept; j++)
            {
                if (strcmp(ArrayOfDepartments[j].eid, Arr[i].eid) == 0)
                {
                    printf("\tDepartment: %s", ArrayOfDepartments[j].dname);
                    break;

                }

            }
            if(j==totalDept)
                printf("\tDepartment: None");

            printf("\n");
            break;
      }

  }
  if(i==totalEmp)
        printf("Employee %s Not Found\n", qStr);

}

int totalSal_dept(Employee Arr[], int totalEmp, Dept ArrayOfDepartments[], int totalDept, char qStr[])
{
    int totalSalary = 0, i, j;

    for(i = 0; i<totalDept; i++)
    {
        //if we find the department, get the eid and look for that eid in the emp structure and add salary
        if (strcmp(ArrayOfDepartments[i].dname, qStr) == 0)
        {

            for(j= 0; j< totalEmp; j++)
            {
                //printf(".%s..%s...\n", ArrayOfDepartments[i].eid, Arr[j].eid);
                if(strcmp(ArrayOfDepartments[i].eid, Arr[j].eid) == 0)
                    totalSalary += Arr[j].sal;


             }


        }
    }

    return totalSalary;

}

void free_memory(Employee *EmpList, int total_emp, Dept *DeptList, int total_dept)
{
    //as we have dynamically allocated strings inside each employee and department, we need to free them first
    //Also note that we have used one malloc to allcoate memory for the employee list, so, we need to free the list of employee using one free. Same for dept

    for(int i=0; i<total_emp; i++)
    {
        free(EmpList[i].eid);
        free(EmpList[i].lname);
    }
    //we have free all the strings insider each emp. Now, free the EmpList
    free(EmpList);

    //do the same for the deptList

    for(int i=0; i<total_dept; i++)
    {
        free(DeptList[i].eid);
        free(DeptList[i].dname);
    }
    //we have free all the strings insider each emp. Now, free the EmpList
    free(DeptList);



}


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
  FILE *qf = fopen("query.txt", "r");
  int numQueries;
  fscanf(qf, "%d", &numQueries);

  //we really don't need to store the queries. We read a query and then process it based on the data we have in our arrays.
  for(int q = 0; q<numQueries; q++)
  {
      int query;
      char qStr[MAXSTRLN];
      fscanf(qf, "%d %s", &query, qStr);

      if(query==1)
      {
          search_employee(EmpList, total_emp, DeptList, total_dept, qStr); //search and display the employee details of employee qStr
      }
      else if (query == 2)
      {
          int totalSal = totalSal_dept(EmpList, total_emp, DeptList, total_dept, qStr); //search and return the total salary of the department qStr
          printf("Total Salary of Department %s is %d\n", qStr, totalSal);

      }

  }

  fclose(qf);

  //now free all the memory
  free_memory(EmpList, total_emp, DeptList, total_dept);

  return 0;
}

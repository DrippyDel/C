//Delali Ekpeh
// de770238
// COP3502
// Lab Assignement 2
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct StringType
{
  char *string;
  int length;
} StringType;

typedef struct Employee
{
  StringType *ename;
  double salary;
} Employee;

//Prototypes
Employee* createEmployees(char names[][50], double *salaries, int empCount);

int main()
{
  const int EMPLOYEE_COUNT = 4;

  //array of employees’ names
  char nameList[][50] = {"Bill", "Mary", "Kevin", "Denise"};

  //array of salaries, where 15.80 is the salary of Bill, 13.50 is
  // the salary of Mary, etc.
  double salaries[] = {15.80, 13.5, 20.9, 12.99};

  Employee *pEmployees = createEmployees(nameList, salaries, EMPLOYEE_COUNT);

  // Print Employees
  int e = 0;
  Employee *pEmployee = pEmployees;
  printf("\tEMPLOYEE NAME\t\tSALARY\n");
  for (e=0;e<EMPLOYEE_COUNT;++e)
  {
    printf("\t%s\t\t\t%.2lf\n",pEmployee->ename->string,pEmployee->salary);
    pEmployee++;
  }

  // Deallocate memory
  pEmployee = pEmployees;
  for (e=0;e<EMPLOYEE_COUNT;++e)
  {
    free(pEmployee->ename->string);
    pEmployee->ename->string = NULL;
    free(pEmployee->ename);
    pEmployee->ename = NULL;
    pEmployee++;
  }

  free(pEmployees);
  pEmployees = NULL;
  return 0;
}

Employee* createEmployees(char names[][50], double *salaries, int empCount)
{
  // Allocating space for an Struct Array of empCount of employees
  Employee *employeeArray = (Employee *) malloc(sizeof(Employee) * empCount);

  for (int i = 0; i < empCount; i++)
  {

    // Allocating space for an Struct Array of empCount of employee(s') name(s)
    StringType *empName = (StringType *) malloc(sizeof(StringType));

    // Allocating space for array of characters (each char of Employee name)
    empName->string = (char *) malloc(strlen(names[i]));

    strcpy(empName->string, names[i]);
    empName->length = strlen(names[i]);

    // empName[i].string = names[i];

    employeeArray[i].ename = empName;
    employeeArray[i].salary = *salaries;

    // Iterates salaries array
    salaries++;

    // printf("name[%d] = %s \n", i, name[i].string);
    // printf("name[%d] = %d \n", i, name[i].length);
    // printf("name[%d] = %s \n", i, employeeArray[i].ename->string);
    // printf("name[%d] = %.2lf \n", i, employeeArray[i].salary);
  }

  return employeeArray;
}

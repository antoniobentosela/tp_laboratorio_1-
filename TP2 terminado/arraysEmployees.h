
#ifndef ARRAYSEMPLOYEES_H_INCLUDED
#define ARRAYSEMPLOYEES_H_INCLUDED


typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} Employee;

#endif // ARRAYSEMPLOYEES_H_INCLUDED

void printEmployee(Employee x);
void printfEmployees(Employee vec[], int len);
void initEmployees(Employee employees[], int len);
int addEmployee(int proximoId, Employee employees[], int len);
Employee newEmployee(int id, char name[], char lastName[], int sector, float salary);
int findEmptyPlace(Employee employees[], int len);
int findEmployeeById(int id, Employee employees[], int len);
int removeEmployee(Employee employees[], int len);
int modifyEmployee(Employee employees[], int len);
void sortEmployees(Employee x[], int len, int order);
void informSortEmployees(Employee employees[], int len);
void informTotalSalary(Employee vec[], int len);
void informar(Employee vec[], int len);
int informMenu();
int menu();


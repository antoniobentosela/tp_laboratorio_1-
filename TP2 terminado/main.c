#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "arraysEmployees.h"

#define LEN 1000

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

int main()
{

    Employee list[LEN];
    int proximoId = 1000;
    char salir = 'n';

    initEmployees(list, LEN);


    do
    {
        switch(menu())
        {
        case 1:
            if(addEmployee(proximoId, list, LEN)){

                proximoId ++;

            };
            break;
        case 2:
                removeEmployee(list, LEN);
            break;
        case 3:
                modifyEmployee(list, LEN);
            break;
        case 4:
                printfEmployees(list, LEN);
            break;
        case 5:
                informar(list, LEN);
            break;
        case 6:
            printf("Confirm Exit?");
            fflush(stdin);
            salir = getch();
            break;
        default:
            printf("Invalid Option\n");
        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}


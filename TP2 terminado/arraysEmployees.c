#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "arraysEmployees.h"

int menu()
{

    int opcion;
    system("cls");
    printf("Option Menu\n\n");
    printf("1- Add Employee\n");
    printf("2- Remove Employee\n");
    printf("3- Modify Employee\n");
    printf("4- List Employee\n");
    printf("5- Inform\n");
    printf("6- Exit\n\n");
    printf("Write option: ");
    scanf("%d", &opcion);

    return opcion;
}


int informMenu()
{

    char opcion;

    system("cls");
    printf("Menu de Opciones\n\n");
    printf("a- Inform Employee sort\n");
    printf("b- Inform Total salarys\n");
    printf("l- Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;

}

void initEmployees(Employee employees[], int len)
{

    for(int i=0; i < len; i++)
    {
        employees[i].isEmpty = 1;
    }
}

int addEmployee (int proximoId, Employee employees[], int len)
{

    int todoOk = 0;
    int indice;
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;

    system("cls");
    printf("**** Add Employee ****\n\n");

    indice = findEmptyPlace(employees, len);

    if( indice == -1)
    {
        printf("Sistem Complete. Can not add more employees\n");
        system("pause");
    }
        else
        {
            id = proximoId;

            printf("Write name: ");
            fflush(stdin);
            gets( name );

            while(strlen(name)>=51){

            printf("Large Name. Please write another name: ");
            fflush(stdin);
            gets(name);
            }

            printf("Write Last Name: ");
            fflush(stdin);
            gets( lastName );

            while(strlen(lastName)>=51){

            printf("Large Name. Please write another name: ");
            fflush(stdin);
            gets(lastName);
            }

            printf("Write sector: ");
            scanf("%d", &sector);

            printf("Write salary:");
            scanf("%f", &salary);

            employees[indice] = newEmployee(id, name, lastName, sector, salary);
            todoOk = 1;
        }

    return todoOk;
}

Employee newEmployee(int id, char name[], char lastName[], int sector, float salary)
{
    Employee nuevoEmployee;
    nuevoEmployee.id = id;
    strcpy(nuevoEmployee.name, name);
    strcpy(nuevoEmployee.lastName, lastName);
    nuevoEmployee.sector = sector;
    nuevoEmployee.salary = salary;


    nuevoEmployee.isEmpty = 0;

    return nuevoEmployee;
}

void printEmployee(Employee x)
{
    printf("%d      %s   %s           %d          %.2f\n",
           x.id,
           x.name,
           x.lastName,
           x.sector,
           x.salary);

}

int removeEmployee(Employee employees[], int len)
{

    int todoOk = 0;
    int indice;
    int id;
    char confirma;

    system("cls");
    printf("**** Remove Employee ****\n\n");

    printf("Write id: ");
    scanf("%d", &id);

    indice = findEmployeeById(id, employees, len);

    if( indice == -1 )
    {
        printf("\nInvalid id\n");
        system("pause");
    }
    else
    {
        printEmployee(employees[indice]);
        printf("\nConfirm elimination?: ");
        fflush(stdin);
        confirma = getche();
        if( confirma == 's')
        {
            employees[indice].isEmpty = 1;
            printf("\n\nthe elimination had success\n");
            todoOk = 1;
        }
        else
        {
            printf("\n\nThe remove been cancelled\n");
        }
        system("pause");
    }
    return todoOk;
}

void printfEmployees(Employee vec[], int len)
{
    int flag = 0;
    system("cls");
    printf("**** List Employees ****\n\n");

    printf(" id       Name  and  Last Name        Sector         Salary\n");
    for(int i=0; i < len; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            printEmployee(vec[i]);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        system("cls");
        printf("\n---No Employees to show---");
    }

    printf("\n\n");
}

int findEmptyPlace(Employee employees[], int len)
{

    int indice = -1;

    for(int i=0; i < len; i++)
    {
        if( employees[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int findEmployeeById(int id, Employee employees[], int len)
{

    int indice = -1;

    for(int i=0; i < len; i++)
    {
        if( employees[i].isEmpty == 0 && employees[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int modifyEmployee(Employee employees[], int len)
{

    int todoOk = 0;
    int indice;
    int id;
    int opcion;
    int sector;
    float salary;


    system("cls");
    printf("**** Modify Employee ****\n\n");

    printf("Write id: ");
    scanf("%d", &id);

    indice = findEmployeeById(id, employees, len);

    if( indice == -1 )
    {
        printf("\nNo tenemos registrado ese legajo\n");
        system("pause");
    }
    else
    {
        printEmployee(employees[indice]);

        printf("Modificar\n\n");
        printf("Sector 1\n");
        printf("Salary 2\n");

        printf("Ingrese opcion:");
        scanf("%d", &opcion);

        if( opcion == 1)
        {
            printf("Write sector: ");
            scanf("%d", &sector);
            employees[indice].sector = sector;
            printf("Sector actualizated");
            todoOk = 1;
        }
        else if( opcion == 2)
        {
            printf("Write salary: ");
            scanf("%f", &salary);
            employees[indice].salary = salary;
            printf("Salary actualizated");
            todoOk = 1;

        }
        else
        {
            printf("No es una opcion valida\n");
        }

        system("pause");
    }
    return todoOk;
}

void informar(Employee vec[], int len)
{

    char seguir = 's';
    char confirma;

    do
    {
        switch(informMenu())
        {

        case 'a':

            informSortEmployees(vec, len);

            break;
        case 'b':

            informTotalSalary(vec, len);

            break;
        case 'l':
            printf("Confirma salida?:\n");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {

                seguir = 'n';

            }
            break;
        }

        system("pause");

    }
    while(seguir == 's');

}



void informTotalSalary(Employee vec[], int len)
{

    float total = 0;
    int contador = 0;
    float promedio;

    for(int i=0; i < len; i++)
    {

        if(vec[i].isEmpty == 0)
        {

            total += vec[i].salary;
            contador ++;

        }

    }

    for(int i=0; i < len; i++)
    {

        if(vec[i].isEmpty == 0)
        {

            promedio = total / contador;

        }

    }



    printf("\nTotal a pagar: $%.2f  Promedio: $%.2f\n\n", total, promedio);

    printf("---Empleados que superan el promedio----\n\n");

    for(int i=0; i < len; i++)
    {

        if(vec[i].isEmpty == 0 && promedio < vec[i].salary)
        {

            printEmployee(vec[i]);

        }

    }

    printf("\n");

}

void sortEmployees(Employee x[], int len, int order)
{

    Employee aux;

    printf("----Sort Employees-----\n\n");

    for(int i = 0; i < len - 1; i++)
    {

        for(int j = i + 1; j < len; j++)
        {

            if(x[i].lastName[0] > x[j].lastName[0])
            {

                aux = x[j];
                x[j] = x[i];
                x[i] = aux;


            } else if (x[i].sector > x[j].sector){

                aux.sector = x[j].sector;
                x[j].sector = x[i].sector;
                x[i].sector = aux.sector;

            }
        }
    }

    printfEmployees(x, len);

}

void informSortEmployees(Employee employees[], int len){

    sortEmployees(employees, len, 0);

}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "Linkedlist.h"

Employee* employee_new()
{
    Employee* newEmployee =(Employee*) malloc(sizeof(Employee));

    if(newEmployee != NULL)
    {
        newEmployee->id = 0;
        strcpy(newEmployee->nombre, "");
        newEmployee->horasTrabajadas = 0;
        newEmployee->sueldo = 0;

    }

    return newEmployee;
}

Employee* new_EmployeeParam(int id, char* nombre, int horasTrabajadas, int sueldo)
{
    Employee* newEmployee = employee_new();

    if(newEmployee != NULL)
    {
        if(!(employee_setId(newEmployee, id)
                && employee_setNombre(newEmployee, nombre)
                && employee_setHorasTrabajadas(newEmployee, horasTrabajadas)
                && employee_setSueldo(newEmployee, sueldo)))
        {
            free(newEmployee);
            newEmployee = NULL;
        }
    }
    return newEmployee;
}

int employee_setId(Employee* this,int id)
{

    int todoOk = 0;

    if(this != NULL && id >=0)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getId(Employee* this,int* id)
{
    int todoOk = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{

    int todoOk = 0;

    if(this != NULL && nombre != NULL && strlen(nombre) >= 3 && strlen(nombre)< 20)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;

}

int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{

    int todoOk = 0;

    if(this != NULL && horasTrabajadas >=0)
    {
       this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk = 0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{

    int todoOk = 0;

    if(this != NULL && sueldo >=0)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk = 0;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int initEmployee( Employee** vec, int tam)
{
    int todoOk = 0;

    if( vec != NULL )
    {
        todoOk = 1;
        for(int i= 0; i < tam; i++)
        {
            *(vec + i) = NULL;
        }
    }
    return todoOk;
}

int buscarLibre( int* indice, Employee** vec, int tam)
{
    int todoOk = 0;

    if( vec != NULL && indice != NULL )
    {
        *indice = -1;
        todoOk = 1;
        for(int i= 0; i < tam; i++)
        {
            if( *(vec + i) == NULL)
            {
                *indice = i;
                break;
            }
        }
    }
    return todoOk;
}
/*
int mostrarEmployee( LinkedList* lista)
{
    int todoOk = 0;
    int tam;

    Employee* auxEmployee;

    if( lista != NULL  )
    {
        tam = ll_len(lista);
        todoOk = 1;

        printf("Id   Nombre    Horas Trabajadas    Sueldo\n");

        for(int i= 0; i < tam; i++)
        {
            auxEmployee = (Employee*) ll_get(lista, i);

            if( auxEmployee != NULL)
            {
                mostrarPersonaP(auxEmployee);
            }
        }
    }
    return todoOk;
}
*/
int mostrarPersonaP(Employee* vec)
{
    int todoOk = 0;

    if( vec != NULL  )
    {
        todoOk = 1;
        printf("%4d %10s  %3d  %5d\n", vec->id, vec->nombre, vec->horasTrabajadas, vec->sueldo);
    }
    return  todoOk;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo){

        return new_EmployeeParam(atoi(idStr), nombreStr, atoi(horasTrabajadasStr), atoi(sueldo));

}




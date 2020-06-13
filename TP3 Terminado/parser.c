#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

    //int cant;
    //int indice;
    //int tam;
    int flag = 1;
    char id[1204];
    char nombre[1204];
    char horas[1204];
    char sueldo[1204];
    Employee* auxEmployee;

    //tam = ll_len(pArrayListEmployee);

    if(pFile==NULL){

        printf("No se pudo abrir el archivo\n");

    }


    while(!feof(pFile)){

        if(flag){

            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horas, sueldo);
            flag = 0;
        }
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id, nombre, horas, sueldo);
            auxEmployee = employee_newParametros(id, nombre, horas, sueldo);

            if(auxEmployee != NULL){

                ll_add(pArrayListEmployee, auxEmployee);

            }
    }




    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    Employee* auxEmpleado;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        while(!feof(pFile))
        {
            auxEmpleado = employee_new();
            fread(auxEmpleado, sizeof(auxEmpleado), 1, pFile);
            ll_add(pArrayListEmployee, auxEmpleado);
        }

    }

    return 1;
}

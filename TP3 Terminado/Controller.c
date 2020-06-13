#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno;
    FILE* pFile;

    pFile = fopen(path, "r");

    if(pFile != NULL)
    {
        retorno = parser_EmployeeFromText(pFile, pArrayListEmployee);
    }

    fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{

    FILE* pFile;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"rb");
        if(pFile!=NULL)
            parser_EmployeeFromBinary(pFile,pArrayListEmployee);
    }


    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    char nombre[20];
    int horasTrabajadas;
    int sueldo;

    Employee* newEmployee = employee_new();

    printf("Ingrese id: ");
    scanf("%d", &id);

    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%s", nombre);

    printf("Ingrese horas trabajadas: ");
    scanf("%d", &horasTrabajadas);

    printf("Ingrese sueldo: ");
    scanf("%d", &sueldo);

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


    if(pArrayListEmployee != NULL)
    {

        ll_add(pArrayListEmployee, newEmployee);

    }



    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int tam;
    int opcion;
    char nombre[20];
    int horasTrabajo;
    int sueldo;
    Employee* auxEmployee;

    tam = ll_len(pArrayListEmployee);

    printf("Ingrese id del empleado: ");
    scanf("%d", &id);

    for(int i = 0; i < tam; i++)
    {

        auxEmployee=(Employee*)ll_get(pArrayListEmployee, i);

        if(auxEmployee->id == id)
        {


            printf("1-Nombre\n");
            printf("2-HorasTrabajadas\n");
            printf("3-Sueldo\n");

            printf("Que dato desea modificar?: ");
            scanf("%d", &opcion);

            if(opcion == 1)
            {

                printf("Ingrese nuevo nombre: ");
                fflush(stdin);
                scanf("%s", nombre);
                employee_setNombre(auxEmployee, nombre);
                break;

            }
            else if(opcion == 2)
            {

                printf("Ingrese horas trabajadas: ");
                scanf("%d", &horasTrabajo);
                employee_setHorasTrabajadas(auxEmployee, horasTrabajo);
                auxEmployee->horasTrabajadas = horasTrabajo;
                break;

            }
            else if(opcion == 3)
            {

                printf("Ingrese sueldo: ");
                scanf("%d", &sueldo);
                employee_setSueldo(auxEmployee, sueldo);
                break;

            }
            else
            {

                printf("Opcion invalida\n");

            }

        }
    }

    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int tam;
    char confirma;
    Employee* auxEmployee;

    system("cls");

    printf("------Baja Empleado------\n\n");

    printf("Ingrese id del empleado: ");
    scanf("%d", &id);

    tam = ll_len(pArrayListEmployee);

    for(int i = 0; i < tam; i++)
    {

        auxEmployee=(Employee*)ll_get(pArrayListEmployee, i);

        if(auxEmployee == NULL)
        {
            printf("No existe ese Empleado\n\n");
            system("pause");


        }
        else if(auxEmployee->id == id)
        {

            printf("Confirma la eliminacion? ");
            fflush(stdin);
            scanf("%c", &confirma);

            if(confirma == 's')
            {

                ll_remove(pArrayListEmployee, i);

            }
            else
            {

                printf("Se cancelo la eliminacion\n\n");

            }
        }

    }
    return 1;

}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int tam = ll_len(pArrayListEmployee);

    Employee* auxEmployee;
    printf("  Id    Nombre    HT  Sueldo\n");
    if( pArrayListEmployee != NULL  )
    {
        for(int i= 0; i < tam; i++)
        {
            auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);

            if( auxEmployee != NULL)
            {
                mostrarPersonaP(auxEmployee);
            }
        }
    }

    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int criterio;

    printf("Ordenar Empleados\n\n");

    if(pArrayListEmployee!=NULL)
    {
        printf("1-Nombre\n");
        printf("2-Horas Trabajadas\n");
        printf("3-Sueldo\n");

        printf("Elija opcion para ordernar: ");
        scanf("%d", &criterio);

        if(criterio == 1){

            printf("\nOrdenando...\n");
            ll_sort(pArrayListEmployee, comparaPersonasNombre, 1);

        }else if(criterio == 2){

            printf("\nOrdenando...\n");
            ll_sort(pArrayListEmployee, comparaPersonasHorasTrabajadas, 1);

        }else{

            printf("\nOrdenando...\n");
            ll_sort(pArrayListEmployee, comparaPersonasSueldo, 1);

        }
    }


    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int i = 0;
    int tam;
    int id;
    int sueldo;
    int horas;
    char nombre[20];
    FILE* pFile;
    Employee* auxEmployee;

    pFile = fopen(path, "w");

    if(pFile != NULL)
    {
        tam = ll_len(pArrayListEmployee);
        fprintf(pFile, "id, nombre, horasTrabajadas, sueldo\n");

        while(i < tam){

                auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
                if(auxEmployee != NULL && employee_getHorasTrabajadas(auxEmployee, &horas)
                   && employee_getId(auxEmployee, &id)
                   && employee_getSueldo(auxEmployee, &sueldo)
                   && employee_getNombre(auxEmployee, nombre)){

                    fprintf(pFile, "%d, %s, %d, %d\n", id, nombre, horas, sueldo);
                }

            i++;
        }
    }

    fclose(pFile);

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{

    int i = 0;
    int tam;

    FILE* pFile;
    Employee* auxEmployee;

    pFile = fopen(path, "wb");

    if(pFile != NULL)
    {
        tam = ll_len(pArrayListEmployee);

        if(pFile != NULL && pArrayListEmployee!= NULL){

            for(i=0;i<tam;i++)
            {
                auxEmployee=ll_get(pArrayListEmployee,i);
                if(auxEmployee!= NULL)
                fwrite(auxEmployee,sizeof(auxEmployee),1,pFile);
            }
        }
    }
    return 1;
}


int comparaPersonasSueldo(void* a,void* b)
{
    int retorno = 0;
    Employee* p1;
    Employee* p2;

    if(a != NULL && b != NULL){

        p1 = (Employee*) a;
        p2 = (Employee*) b;
    }

    if(p1->sueldo > p2->sueldo){

        retorno = 1;

    }else if(p1->sueldo < p2->sueldo){

        retorno = -1;

    }

    return retorno;
}

int comparaPersonasNombre(void* a,void* b)
{
    int retorno = 0;

    Employee* p1;
    Employee* p2;

    if(a != NULL && b != NULL){

        p1 = (Employee*) a;
        p2 = (Employee*) b;
    }

        retorno = strcmp(p1->nombre, p2->nombre);

    return retorno;

}

int comparaPersonasHorasTrabajadas(void* a,void* b)
{
    int retorno = 0;
    Employee* p1;
    Employee* p2;

    if(a != NULL && b != NULL){

        p1 = (Employee*) a;
        p2 = (Employee*) b;
    }

    if(p1->horasTrabajadas > p2->horasTrabajadas){

        retorno = 1;

    }else if(p1->horasTrabajadas < p2->horasTrabajadas){

        retorno = -1;

    }

    return retorno;
}

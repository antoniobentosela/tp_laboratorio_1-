#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int menu();

int main()
{
    char seguir = 's';
    char confirma;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        switch(menu())
        {
        case 1:
            system("cls");
            if(controller_loadFromText("data.csv",listaEmpleados))
            {

                printf("Se han cargado los Empleados correctamente!\n");
                system("pause");

            }

            break;
        case 2:
            system("cls");
            if(controller_loadFromBinary("data.csv",listaEmpleados))
            {

                printf("Se han cargado los Empleados correctamente!\n");
                system("pause");

            }

            break;
        case 3:
            system("cls");
            if(controller_addEmployee(listaEmpleados))
            {

                printf("Alta empleado exitosa!\n");

                system("pause");

            }

            break;
        case 4:
            system("cls");
            if(controller_editEmployee(listaEmpleados))
            {

                printf("Modificacion realizada\n");
                system("pause");
            }

            break;
        case 5:
            system("cls");
            if(controller_removeEmployee(listaEmpleados))
            {

                printf("Baja exitosa!\n");
                system("pause");
            }
        case 6:
            system("cls");
            controller_ListEmployee(listaEmpleados);

            system("pause");
            break;
        case 7:
            system("cls");
            if(controller_sortEmployee(listaEmpleados))
            {

                printf("\nOrdenamiento Exitoso!\n");
                system("pause");
            }
            break;
        case 8:
            system("cls");
            if(controller_saveAsText("data.csv", listaEmpleados))
            {

                printf("\nGuardados!\n");
                system("pause");
            }
            break;
        case 9:
            system("cls");
            if(controller_saveAsBinary("data.csv", listaEmpleados))
            {

                printf("\nGuardados!\n");
                system("pause");
            }
            break;
            case 10:
            printf("Confirma salida?:\n");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {

                seguir = 'n';

            }
            break;
        }

    }
    while(seguir == 's');
    return 0;
}

int menu()
{

    int opcion;

    system("cls");
    printf("Menu de Opciones\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de empleado.\n");
    printf("4. Modificar datos de empleado.\n");
    printf("5. Baja de empleado.\n");
    printf("6. Listar empleados.\n");
    printf("7. Ordenar empleados.\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}

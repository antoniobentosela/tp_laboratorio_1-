#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "auto.h"

int menu();

int filtrarxRangoAnio(void*);
int filtrarxColor(void* unAuto);

int main()
{
    char seguir = 's';
    char confirma;

    LinkedList* lista = ll_newLinkedList();

    if(lista != NULL){

    do
    {
        switch(menu())
        {
        case 1:
            system("cls");
            if(cargarCsvAutos("autos.csv",lista))
            {

                printf("Se han cargado los Empleados correctamente!\n");
                system("pause");

            }

            break;
        case 2:
                if(ll_isEmpty(lista)){
                    system("cls");
                    printf("La lista esta vacia\n");
                    system("pause");

                }else{
                system("cls");
                listarAutos(lista);
                system("pause");
                }
            break;
        case 3:
            system("cls");
            if(altaAuto(lista))
            {

                printf("Alta auto exitosa!\n");

                system("pause");

            }

            break;
       case 4:
            system("cls");
            if(modificarAuto(lista))
            {

                printf("Modificacion realizada\n");
                system("pause");
            }

            break;
        case 5:
            system("cls");
            if(bajaAuto(lista))
            {

                printf("Baja exitosa!\n");
                system("pause");
            }
            break;

        case 6:
            system("cls");
            if(ordenarAutos(lista))
            {

                printf("\nOrdenamiento Exitoso!\n");
                system("pause");
            }
            break;
        case 7:
            system("cls");
            if(guardarAutos("autos.csv", lista))
            {
                printf("\nGuardados!\n");
                system("pause");
            }
            break;
        case 8:
            system("cls");

            if(ll_clear(lista)==0){

                printf("Elementos eliminados\n");
                system("pause");
            }

            break;

            case 9:
            printf("Confirma salida?:\n");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                ll_deleteLinkedList(lista);
                seguir = 'n';

            }
            break;
        }

    }
    while(seguir == 's');
    }

    system("cls");

    return 0;
}

int menu()
{

    int opcion;

    system("cls");
    printf("Menu de Opciones\n\n");
    printf("1. Cargar Autos de autos.csv\n");
    printf("2. Listar Autos\n");
    printf("3. Sumar un auto\n");
    printf("4. Modificar datos del auto.\n");
    printf("5. Baja de Auto.\n");
    printf("6. Ordenar autos\n");
    printf("7. Guardar autos\n");
    printf("8. Eliminar todos los autos\n");
    printf("9. Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}

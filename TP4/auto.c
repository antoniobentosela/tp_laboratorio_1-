#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "auto.h"

Auto* auto_new()
{
    Auto* newAuto =(Auto*) malloc(sizeof(Auto));

    if(newAuto != NULL)
    {
        newAuto->id = 0;
        strcpy(newAuto->marca, "");
        strcpy(newAuto->color, "");
        newAuto->anio = 0;
        newAuto->precio = 0;

    }

    return newAuto;
}

Auto* new_AutoParam(int id, char* marca, char* color, int anio, int precio)
{
    Auto* newAuto = auto_new();

    if(newAuto != NULL)
    {
        if(!(auto_setId(newAuto, id)
                && auto_setMarca(newAuto, marca)
                && auto_setColor(newAuto, color)
                && auto_setAnio(newAuto, anio)
                && auto_setPrecio(newAuto, precio)))
        {
            free(newAuto);
            newAuto = NULL;
        }
    }
    return newAuto;
}

Auto* auto_newParametros(char* idStr,char* marcaStr,char* colorStr, char* anio, char* precio)
{

    return new_AutoParam(atoi(idStr), marcaStr, colorStr, atoi(anio), atoi(precio));

}

int auto_setId(Auto* this,int id)
{
    int todoOk = 0;

    if(this != NULL && id >=0)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int auto_getId(Auto* this,int* id)
{
    int todoOk = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}

int auto_setMarca(Auto* this,char* marca)
{

    int todoOk = 0;

    if(this != NULL && marca != NULL && strlen(marca) >= 3 && strlen(marca)< 20)
    {
        strcpy(this->marca, marca);
        todoOk = 1;
    }
    return todoOk;

}

int auto_getMarca(Auto* this,char* marca)
{
    int todoOk = 0;

    if(this != NULL && marca != NULL)
    {
        strcpy(marca, this->marca);
        todoOk = 1;
    }
    return todoOk;
}

int auto_setColor(Auto* this,char* color)
{

    int todoOk = 0;

    if(this != NULL && color != NULL && strlen(color) >= 3 && strlen(color)< 20)
    {
        strcpy(this->color, color);
        todoOk = 1;
    }
    return todoOk;

}

int auto_getColor(Auto* this,char* color)
{
    int todoOk = 0;

    if(this != NULL && color != NULL)
    {
        strcpy(color, this->color);
        todoOk = 1;
    }
    return todoOk;
}

int auto_setAnio(Auto* this,int anio)
{

    int todoOk = 0;

    if(this != NULL && anio >=0)
    {
        this->anio = anio;
        todoOk = 1;
    }
    return todoOk;
}

int auto_getAnio(Auto* this,int* anio)
{
    int todoOk = 0;

    if(this != NULL && anio != NULL)
    {
        *anio = this->anio;
        todoOk = 1;
    }
    return todoOk;
}

int auto_setPrecio(Auto* this,int precio)
{

    int todoOk = 0;

    if(this != NULL && precio >=0)
    {
        this->precio = precio;
        todoOk = 1;
    }
    return todoOk;
}

int auto_getPrecio(Auto* this,int* precio)
{
    int todoOk = 0;

    if(this != NULL && precio != NULL)
    {
        *precio = this->precio;
        todoOk = 1;
    }
    return todoOk;
}

int cargarCsvAutos(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int flag = 1;
    char id[1204];
    char marca[1204];
    char color[1204];
    char anio[1204];
    char precio[1204];
    Auto* auxAuto;
    FILE* pFile;

    pFile = fopen(path, "r");

    if(pFile != NULL)
    {

        if(pFile==NULL)
        {

            printf("No se pudo abrir el archivo\n");

        }


        while(!feof(pFile))
        {

            if(flag)
            {

                fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, marca, anio, color, precio);
                flag = 0;
            }
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id, marca, anio, color, precio);
            auxAuto = auto_newParametros(id, marca, color, anio, precio);

            if(auxAuto != NULL)
            {

                ll_add(pArrayListEmployee, auxAuto);
                retorno = 1;

            }
        }
    }

    fclose(pFile);
    return retorno;
}

int mostrarAutosP(Auto* vec)
{
    int todoOk = 0;

    if( vec != NULL  )
    {
        todoOk = 1;
        printf("%4d %10s %3d %10s %5d\n", vec->id, vec->marca, vec->anio, vec->color, vec->precio);
    }
    return  todoOk;
}

int listarAutos(LinkedList* pArrayListEmployee)
{
    int tam = ll_len(pArrayListEmployee);

    Auto* auxAuto;
    printf("  Id    Marca  Anio  Color  Precio\n");
    if( pArrayListEmployee != NULL  )
    {
        for(int i= 0; i < tam; i++)
        {
            auxAuto = (Auto*) ll_get(pArrayListEmployee, i);

            if( auxAuto != NULL)
            {
                mostrarAutosP(auxAuto);
            }
        }
    }

    return 1;
}

int guardarAutos(char* path, LinkedList* pArrayListEmployee)
{
    int i = 0;
    int tam;
    int id;
    int precio;
    int anio;
    char marca[20];
    char color[20];
    FILE* pFile;
    Auto* auxAuto;

    pFile = fopen(path, "w");

    if(pFile != NULL)
    {
        tam = ll_len(pArrayListEmployee);
        fprintf(pFile, "id, marca, color,  anio, precio\n");

        while(i < tam)
        {

            auxAuto = (Auto*) ll_get(pArrayListEmployee, i);
            if(auxAuto != NULL && auto_getAnio(auxAuto, &anio)
                    && auto_getId(auxAuto, &id)
                    && auto_getPrecio(auxAuto, &precio)
                    && auto_getMarca(auxAuto, marca)
                    && auto_getColor(auxAuto, color))
            {

                fprintf(pFile, "%d, %s, %s, %d, %d\n", id, marca, color,  anio, precio);
            }

            i++;
        }
    }

    fclose(pFile);

    return 1;
}

int altaAuto(LinkedList* pArrayListEmployee)
{
    int id;
    char marca[20];
    char color[20];
    int anio;
    int precio;

    Auto* newAuto = auto_new();

    printf("Ingrese id: ");
    scanf("%d", &id);

    printf("Ingrese marca: ");
    fflush(stdin);
    scanf("%s", marca);

    printf("Ingrese color: ");
    fflush(stdin);
    scanf("%s", color);

    printf("Ingrese horas anio: ");
    scanf("%d", &anio);

    printf("Ingrese precio: ");
    scanf("%d", &precio);

    if(newAuto != NULL)
    {
        if(!(auto_setId(newAuto, id)
                && auto_setMarca(newAuto, marca)
                && auto_setColor(newAuto, color)
                && auto_setAnio(newAuto, anio)
                && auto_setPrecio(newAuto, precio)))
        {
            free(newAuto);
            newAuto = NULL;
        }
    }


    if(pArrayListEmployee != NULL)
    {

        ll_add(pArrayListEmployee, newAuto);

    }

    return 1;
}

int modificarAuto(LinkedList* pArrayListEmployee)
{
    int id;
    int tam;
    int opcion;
    char color[20];
    int anio;
    int precio;
    Auto* auxAuto;

    tam = ll_len(pArrayListEmployee);

    printf("Ingrese id del empleado: ");
    scanf("%d", &id);

    for(int i = 0; i < tam; i++)
    {

        auxAuto=(Auto*)ll_get(pArrayListEmployee, i);

        if(auxAuto->id == id)
        {

            printf("1-Color\n");
            printf("2-Anio\n");
            printf("3-Precio\n");

            printf("Que dato desea modificar?: ");
            scanf("%d", &opcion);

            if(opcion == 1)
            {

                printf("Ingrese nuevo color: ");
                fflush(stdin);
                scanf("%s", color);
                auto_setColor(auxAuto, color);
                break;

            }
            else if(opcion == 2)
            {

                printf("Ingrese anio: ");
                scanf("%d", &anio);
                auto_setAnio(auxAuto, anio);
                auxAuto->anio = anio;
                break;

            }
            else if(opcion == 3)
            {

                printf("Ingrese precio: ");
                scanf("%d", &precio);
                auto_setPrecio(auxAuto, precio);
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

int bajaAuto(LinkedList* pArrayListEmployee)
{
    int id;
    int tam;
    char confirma;
    Auto* auxAuto;

    system("cls");

    printf("------Baja Auto------\n\n");

    printf("Ingrese id del auto: ");
    scanf("%d", &id);

    tam = ll_len(pArrayListEmployee);

    for(int i = 0; i < tam; i++)
    {
        auxAuto=(Auto*)ll_get(pArrayListEmployee, i);

        if(auxAuto == NULL)
        {
            printf("No existe ese Auto\n\n");
            system("pause");


        }
        else if(auxAuto->id == id)
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

int comparaAutosAnio(void* a,void* b)
{
    int retorno = 0;
    Auto* a1;
    Auto* a2;

    if(a != NULL && b != NULL)
    {

        a1 = (Auto*) a;
        a2 = (Auto*) b;
    }

    if(a1->anio > a2->anio)
    {

        retorno = 1;

    }
    else if(a1->anio < a2->anio)
    {

        retorno = -1;

    }

    return retorno;
}

int comparaAutosMarca(void* a,void* b)
{
    int retorno = 0;

    Auto* a1;
    Auto* a2;

    if(a != NULL && b != NULL)
    {

        a1 = (Auto*) a;
        a2 = (Auto*) b;
    }

    retorno = strcmp(a1->marca, a2->marca);

    return retorno;

}

int comparaAutoPrecio(void* a,void* b)
{
    int retorno = 0;
    Auto* a1;
    Auto* a2;

    if(a != NULL && b != NULL)
    {

        a1 = (Auto*) a;
        a2 = (Auto*) b;
    }

    if(a1->precio > a2->precio)
    {

        retorno = 1;

    }
    else if(a1->precio < a2->precio)
    {

        retorno = -1;

    }

    return retorno;
}

int ordenarAutos(LinkedList* pArrayListEmployee)
{
    int criterio;

    printf("Ordenar Autos\n\n");

    if(pArrayListEmployee!=NULL)
    {
        printf("1-Marca\n");
        printf("2-Anio\n");
        printf("3-Precio\n");

        printf("Elija opcion para ordernar: ");
        scanf("%d", &criterio);

        if(criterio == 1)
        {

            printf("\nOrdenando...\n");
            ll_sort(pArrayListEmployee, comparaAutosMarca, 1);

        }
        else if(criterio == 2)
        {

            printf("\nOrdenando...\n");
            ll_sort(pArrayListEmployee, comparaAutosAnio, 1);

        }
        else
        {

            printf("\nOrdenando...\n");
            ll_sort(pArrayListEmployee, comparaAutoPrecio, 1);

        }
    }


    return 1;
}

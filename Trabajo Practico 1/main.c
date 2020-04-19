#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "biblioteca.h"

void mostrarOperandos(int valor1, int valor2, int flag1, int flag2);

int main()
{
    char seguir='n';
    char opcion;
    int flag1 = 0;
    int flag2 = 0;
    int a;
    int b;
    int resultadoSuma;
    int resultadoResta;
    int resultadoMultiplicacion;
    int resultadoDivision;
    int resultadoFactorialA;
    int resultadoFactorialB;
    int flagCarga = 0;
    int flagCalculo = 0;

    do
    {
        system ("cls");
        printf ("----Menu de opciones----\n");
        printf("\na- Ingresar operandos\n");
        printf("b- Calcular todas las operaciones\n");
        printf("c- Mostrar resultados\n");
        printf("d- Salir\n");
        printf("\n\n");
        mostrarOperandos(a,b,flag1,flag2);
        printf("\n\n");
        printf ("Ingrese opcion: ");
        opcion = getche ();
        fflush (stdin);



        switch(opcion)
        {
            case 'a':

            if(flagCarga == 0){

                a = CargarNum1 (a);
                b = CargarNum2 (b);
                flagCarga = 1;
                flag1 = 1;
                flag2 = 1;
                system ("pause");


            }

                break;

            case 'b':

                if (flagCarga == 0){

                    printf("\n\nError. Debe cargar los operandos para calcular las operaciones\n\n");

                } else {

                 if (flagCalculo == 0){

                        CalcularTodos (a, b,  &resultadoSuma,  &resultadoResta,  &resultadoMultiplicacion, &resultadoDivision, &resultadoFactorialA, &resultadoFactorialB);

                        flagCalculo = 1;
                    }

                }

                system ("pause");

                break;


            case 'c':

                 if (flagCalculo == 0){

                    printf("\n\nError. Debe hacer los calculos  para mostrar las operaciones\n\n");

               } else {

                MostrarResultados (resultadoSuma, resultadoResta, resultadoMultiplicacion, resultadoDivision, resultadoFactorialA, resultadoFactorialB);

                }

                system ("pause");

                break;

            case 'd':

                printf ("\n\nUsted eligio Salir\n\n");
                printf ("Confirma Salida?: ");
                seguir = getche ();
                fflush(stdin);
                printf("\n\n");
                system ("pause");

                break;
        }



    } while(seguir=='n');


    return 0;
}

void mostrarOperandos(int valor1, int valor2, int flag1, int flag2){

    if(flag1 == 0){

    printf ("operando = x\n");

    }else{

    printf("Operando 1: %d\n", valor1);

    }

    if(flag2 == 0){

    printf ("operando = x");

    }else{

    printf("Operando 2: %d", valor2);

    }

}

int CargarNum1 ( int a)
{


    printf("\n\n");
    printf ("\nIngrese un numero: \n");
    scanf ("%d", &a);


    return a;
}


int CargarNum2 (int b)
{



    printf ("\nIngrese otro numero: \n");
    scanf ("%d", &b);
    printf("\n\n");

    return b;
}

int CalcularSuma (int a, int b)
{

    int resultado;

    resultado = a + b;

    return resultado;

}

int CalcularResta (int a, int b)
{

    int resultado;

    resultado = a - b;

    return resultado;

}

int CalcularMultiplicacion (int a, int b)
{

    int resultado;

    resultado = a * b;

    return resultado;

}

int CalcularDivision (int a, int b){

    int flagDivision = 0;

    int resultado;

    if (b != 0){

        resultado = a / b;
        flagDivision = 1;


    }

    return resultado;

}

int factorialA (int a){

int factA = 1;

while( a > 1){

    factA = factA * a;
    a--;

}

return factA;

}

int factorial (int b){

int factB = 1;

while( b > 1){

    factB = factB * b;
    b--;

}

return factB;

}

void CalcularTodos (int a, int b, int *resultadoSuma, int *resultadoResta, int *resultadoMultiplicacion, int *resultadoDivision, int *resultadoFactorialA, int *resultadoFactorialB)
{
printf("\n\n");
*resultadoSuma = CalcularSuma(a,b);
*resultadoResta = CalcularResta(a,b);
*resultadoMultiplicacion = CalcularMultiplicacion(a,b);
*resultadoDivision = CalcularDivision(a,b);
*resultadoFactorialA = factorial (a);
*resultadoFactorialB = factorial (b);



}

void MostrarResultados(int suma, int resta, int mult, int div, int factA, int factB){

printf ("\n\n");
printf("La suma es: %d\n", suma);
printf("La resta es: %d\n", resta);
printf("La multiplicacion es: %d\n", mult);
printf("La division es: %d\n", div);
printf("El factorial del primer operando es: %d\n", factA);
printf("El factorial del segundo operando es: %d\n", factB);
printf("\n\n");



}




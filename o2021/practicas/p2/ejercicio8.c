/**
* @file ejercicio8.c
* @brief Este programa calcula el valor aproximado de 'e', dado un número ingresado por el usuario se determinara cuantas
*	 veces se realizara la operacion para calcularlo.
* @authors Gabriel Coronado, Sergio Esquivel y Sebastian Alanis
* @date 28/sep/2021
*/

#include <stdio.h>

float  calcularE(int n);
int main()
{
	int n;
	float resultado;
	printf ("\n");
	printf ("Este programa calcula el valor aproximado de 'e'.Dado un número ingresado por el usuario se determinara cuantas veces se realizara la operación para calcular 'e'");
	printf ("\n\n");
	printf ("Ingresa el número de veces que quieres que se realice la operación para calcular 'e': ");
	scanf (" %i", &n);
	printf ("\n");
	resultado = calcularE(n);
	printf ("Tu valor calculado de 'e' es: %f",resultado);
	printf ("\n\n");
	return 0;
}

/**
* @brief Esta funcion calcula el valor aproximado de 'e'.
* @authors Gabriel Coronado, Sergio Esquivel y Sebastian Alanis
* @date 28/sep/2021
* @param n es un entero, almacena el numero de veces que realizara la formula para calcular 'e'
* @return valorDeE es un decimal, almacena el valor del calculo de e
*/

float calcularE(int n)
{
	int i;
	float resul=1, valorDeE= 1;
	for(i=1; i<=n-1; i++)
	 {
			resul= resul * i;
			valorDeE= (1/resul)+valorDeE;
	 }
	return valorDeE;
}

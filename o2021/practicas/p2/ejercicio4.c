/**
* @file ejercicio4.c
* @brief Este programa calcula el valor factorial de un nùmero.
* @authors Gabriel Coronado, Sergio Esquivel y Sebastian Alanis.
* @date 14/oct/2021
*/

#include <stdio.h>
int calcularFactorial(int x);
int main()
{
	int factoria, x, resultado;
	printf ("\nEste programa calcula el factorial de un nùmero x. Inserta el valor del nùmero: ");
	scanf (" %i", &x);
	resultado = calcularFactorial(x);
	printf ("\nEl factorial de tu nùmero es: %d\n", resultado);
	return 0;
}

/**
* @brief Este programa calucla los multiplos que existen en$
* @authors Gabriel Coronado/Sergio Esquivel/Sebastian Alanis
* @date 14/oct/2021
* @param  x es entero, almacena el factorial que desea saber el usuario
* @return resultado es un entero, almacena el calculo del factorial
*/

int calcularFactorial(int x)
{
	int factorial, resultado = 1;
	for (factorial = x; factorial > 1; factorial--)
	{
		resultado = resultado * factorial;
	}
	return resultado;
}

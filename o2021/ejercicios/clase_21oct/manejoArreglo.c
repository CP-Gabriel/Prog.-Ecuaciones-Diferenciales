/**
* @file manejoArreglo.c
* @brief Este es un ejemplo de varias funciones para manipular arreglos.
	 1)Haga una funcion que permita recibir como argumento un arreglo de 4 valores enteros, en la fución permita que
	 el usuario capture los valores.
	 2)Haga otra función que reciba como argumento el arreglo de enteros y mande a imprimir los datos capturados. 
* @author clase de Guillermo Gómez
* @date 21/oct/2021
*/


#include <stdio.h>
#define SIZE 4

void capturarDatos(int dat[]);
void imprimirDatos();
int main(void)
{
	int enteros[SIZE];
	capturarDatos(enteros);
	imprimirDatos(enteros);
	return 0;
}

void capturarDatos(int dat[])
{
	int i;
	printf ("\nCaptura los datos de los arreglo\n\n");
	for (i=0; i<SIZE; i++)
	{
		printf ("Dame el dato %i: ", i);
		scanf (" %i", &dat[i]);
	}
	return;
}

void imprimirDatos(int dat[])
{
	int i;
	printf ("\nLos datos capturados en el arreglo son: \n");
	for (i=0; i<SIZE; i++)
	{
		printf ("\nEl dato en números de [%i] es: %i", i, dat[i]);
	}
	printf ("\n\n");
	return;
}

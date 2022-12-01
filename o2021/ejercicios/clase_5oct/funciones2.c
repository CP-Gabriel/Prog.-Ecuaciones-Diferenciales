/**
* @file funciones2.c
* @brief En este archivo hay varias funciones adicionales a funciones.c para dibujar figuras.
* @author clase de Guillermo
* @date 07/oct/2021
*/

#include <stdio.h>

/**
* @brief Esta función imprime un cuadro nxn
* @author clase de Guillermo
* @date 07/oct/2021
* @param n que es un entero, lado del cuadro y patrón el entero
* @return void
*/
extern void dibujarCuadroN(int lado)
{
	int i,j;
	for (j=1; j<=lado; j++)
	{
		for (i=1; i<=lado; i++)
	 	{
	  		printf (" %i", lado);
	 	}
		printf ("\n");
	}
	printf ("\n");
	return;
}

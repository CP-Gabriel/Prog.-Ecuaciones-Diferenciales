/**
* @file funciones.c
* @brief En este archivo hay varias funciones para dibujar figuras.
* @author clase de Guillermo
* @date 05/oct/2021
*/

#include <stdio.h>

/**
* @brief Esta función imprime un cuadro de chars largo x largo en pantalla
* @author clase de Guillermo 
* @date 05/oct/2021
* @param patron que es un char
* @param return void
*/
extern void dibujarCuadro(int lado, char patron)
{
	int i, j;
	for(j=1; j<=lado; j++)
	 {
		for(i=1; i<=lado; i++)
	 	 {
		 	printf(" %c", patron);
		 }
		printf ("\n");
	}
	printf ("\n");
	return ;
}

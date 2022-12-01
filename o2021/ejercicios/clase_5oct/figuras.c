/**
* @file linea.c
* @brief Este programa permite imprimir dibujos en terminal del texto.
* @author clase de Guillermo
* @date 05/oct/2021
*
* Se va a modificar el programa para que utilice una función externa 
* esta  funcion externa va a dibujar un cuadro de largo x largo
*/
#include <stdio.h>

void dibujarLinea(int largo, char patron);
void dibujarCuadro(int largo, char patron);
int main()
{
	int largo;
	char patron;
	printf ("\nIngresa el largo y patrón de la línea y del cuadro: ");
	scanf (" %i %c", &largo, &patron);
	printf ("\nLa linea:\n");
	dibujarLinea(largo, patron);
	printf ("\nEl cuadro:\n");
	dibujarCuadro(largo, patron);
	return 0;
}

/**
* @brief Eta función imprime un número de chars en pantalla.
* @author clase de Guillermo
* @date 05/oct/2021
* @param largo y es un entero
* @param 
* @patron que es char 
* @return void
*/

void dibujarLinea(int largo, char patron) {
	int i;
	for (i = 1; i<= largo; i++)
	 {
	  printf ("%c-", patron);
	 } 
	return;
}




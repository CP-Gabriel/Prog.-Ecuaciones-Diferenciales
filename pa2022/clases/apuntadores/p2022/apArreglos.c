/**
* @file apArreglos.c
* @brief Este programa es un ejercicio para practicar el manejo de arreglos con
*	 apuntadores. Hacer un ejemplo de un arreglo de reales y realizar operaciones
*	 utiliznado apuntadores. Hacer un segundo ejercicio con apuntadores dobles de reales.
*/
#include <stdio.h>

int main(void)
{
	float arreglo[4];
	float *aReal;
	float tablero[3][3];
	float *aTablero;

	*(arreglo + 3) = 33.3; //arreglo[3] = 33.3;
	aReal = (arreglo + 1);//aReal = &arreglo[1]:,;
	*aReal = (*(arreglo + 3)) *2;//arreglo[3] *2;

	printf ("\nEn arreglo[1] hay: %f y en arreglo[3] tenemos: %f\n", arreglo[1], arreglo[3]);

	tablero[2][0] = 67.5;
	tablero[1][2] = 7.1;

	aTablero = &tablero[2][2];
	*aTablero = tablero[2][0] + tablero[1][2];
	printf ("\nEn tablero[2][2] tnenemos: %f\n", tablero[2][2]);
	printf ("\n");
	return 0;
}

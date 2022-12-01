/*
* @file: evaluarFrase.c
* @brief: Este programa nos permite conocer cuantas vocales tiene una frase que ingresó el usuario; también, nos indica el
*	  número de mayúsculas y si la frase termina con punto.
*	  Se usaran apuntadores para la solución.
* @author: clase de Guillermo Gómez
* @date: 4/11/21
*/

#include "detFrase.h"

void contarEnFrase(char fr[], int *voc, int *may, int *pun);
int main (void)
{
	char frase[TAM];
	int vocales, mayusculas, punto;
	printf ("\nIngrese una frase: ");
	scanf (" %[^\n]", frase);
	contarEnFrase(frase, &vocales, &mayusculas, &punto);
	printf ("\nTu frase tiene %i vocales, %i mayúsculas ", vocales, mayusculas);
	if (punto==1)
	{
		printf (" y la frase termina en punto.\n");
	}
	else
	{
		printf (" y la frase no termina en punto.\n");
	}
	printf ("\n");
	return 0;
}

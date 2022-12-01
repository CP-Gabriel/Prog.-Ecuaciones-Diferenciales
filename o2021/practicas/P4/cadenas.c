/*
* @file: cadenas.c
* @brief: Este programa permite ingresar una frase de texto, despues codifica la frase y la muestra en pantalla, además
	  muestra los carecteres que tenga la frase.
* @authors: Gabriel Coronado/Sergio Esquivel/Sebastian Alanis.
* @date: 02/nov/2021
*/

#include <stdio.h>
#include <string.h>

void codificar(char frase[], int *numCarac);
int main(void)
{
	char frase[255];
	int numCarac=0;
	printf ("\nEste programa permite ingresar una frase de texto, despues codifica la frase\ny la muestra en pantalla, además muestra los caracteres que tenga la frase.\n");
	printf ("\nFrase original:\n");
	scanf (" %[^\n]", frase);
	codificar(frase, &numCarac);
	printf ("\nFrase codificada:\n");
	printf ("%s\n", frase);
	printf ("\nSe codificaron %i caracteres.\n", numCarac);
	printf ("\n");
	return 0;
}

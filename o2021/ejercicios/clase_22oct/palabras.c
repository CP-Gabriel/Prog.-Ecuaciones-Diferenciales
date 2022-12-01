/**
* @file palabras.c
* @brief Este programa nos permite manupular cadenas. Son
	 varios ejemplos de asignaciones de cadenas y uso
	 de funciones de strrings.
* @author clase de Guillermo Gómez
* @date 22/oct/2021
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	char nombre[40];
	char letra;
	printf ("\nDame una letra: ");//Si leo un char
		//despué de un printf, antes no debo ejecutar
		//un salto de línea\n
	scanf (" %c", &letra);//Si leo un scanf una letra,
		//es recomendable poner un espacion en " %c"
		//en el conversor
	printf ("\nLa letra que ingresaste es: %c\n", letra);
	printf ("\nDame tu nombre (sólo puedo leer una palabra):  ");
	scanf ("%s", nombre);//Cuando hago un scanf con %s,
		//sólo puedo leer una palabra.No puedo leer
		//una frase con espacios
		//Cuando leo 
	printf ("\nTu nombre es: %s\n", nombre);
	printf ("\nDame tu nombre completo: ");
	scanf (" %[^\n]", nombre);
	printf ("\nTu nombre completo es: %s\n", nombre);
	return 0;
}


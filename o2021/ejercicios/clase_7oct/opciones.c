/**
* @file opciones.c
* @brief Este programa lee opciones de letras ingresadas por un 
* usuario y apartir de las opciones, ejectura diferentes sentencias.
* Si el usuario ingresa la letra 'a' ó 'A', el programa indica  
* que se ingresó la letra a.
* Si el usuario ingresa la letra 'b' ó 'B', el programa indica
* que se ingresó la letra b.
* Para cualquier otra letra, el programa debe indicar que fue 
* otra letra diferente a la a o b.
* @author clase de Guillermo
* @date 07/oct/2021
*/
#include <stdio.h>
int main(void) 
{
	char opcion;
	printf ("\nIngrese una letra: ");
	scanf (" %c", &opcion);
	if ((opcion=='a') || (opcion == 'A'))
	 {
	  printf ("Ingresaste una letra a.\n");
	  printf ("\n");
	 }
	else 
	 {
		if ((opcion=='b') || (opcion == 'B'))
		 {
		  printf ("Ingresaste una letra b.\n");
		  printf ("\n");
		 }
		else
		 {
		  printf ("Ingresaste una que no es ni a, ni b.\n");
		  printf ("\n");
		 }
	 }
	return 0;
}

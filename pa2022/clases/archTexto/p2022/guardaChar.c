/**
* @file guardaLetras.c
* @brief este programa abre un archivo de texto para escritura; en un ciclo se leen chars ingresados
*        por el susaurio desde teclado; mientras no lea de teclado una 's'
*	 va a guardar las letras en el archivo.
* @author clase de Guillermo.
* @date: 04/feb/2022
*/

#include <stdio.h> //Para manipular funciones de archivos anexar stdio.h
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	char letra;
	fp = fopen ("letras.txt", "a");
	if (fp == NULL)
	{
		printf ("\nArchivo no disponoible.\n");
		exit(1);
	}
	do
	{
		scanf (" %c", &letra);
		fprintf(fp,"%c-> ", letra);
	}
	while(letra != 's');
	fclose(fp);
	return 0;
}

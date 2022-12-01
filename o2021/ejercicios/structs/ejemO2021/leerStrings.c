/*
*Ejemplo de archivos: Haga un programa que lea secuencialmente los strings de un archivo letras.txt
*	El programa avanza la lextura con la letra 'a' y termina con cualquier letra o fin de archivo.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	char palabra[50], opcion = 'a';
	fp = fopen("palabras.txt", "r");
	if (fp == NULL)
	{
		printf ("\nArchivo no disponible.");
		exit(1);
	}
	while ((opcion == 'a')&&(fscanf(fp,"%s", palabra) == 1))
	{
		printf("\nLeí del archivo: %s \n¿Quiéres seguir leyendo [a]?: ", palabra);
		scanf(" %c", &opcion);
	}
	fclose(fp);
	return 0;
}

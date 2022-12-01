/*
*Ejemplo de archivos: Haga un progrma que lea secuencialmente as letras de un archivo letras.txt
*	El programa avanza la lextura con la letra 'a' y termina con cualquier letra o cuando llege al final del archivo
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	char letra, opcion = 'a';
	fp = fopen("letras.txt", "r");
	if (fp == NULL)
	{
		printf ("\nArchivo no disponible.");
		exit(1);
	}
	while ((opcion == 'a')&&(fscanf(fp,"%c", &letra) == 1))
	{
		printf("\nLeí del archivo: %c \n¿Quiéres seguir leyendo [a]?: ", letra);
		scanf(" %c", &opcion);
	}
	fclose(fp);
	return 0;
}

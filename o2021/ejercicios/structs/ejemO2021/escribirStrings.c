/*
*Ejemplo de archivos: Haga un programa que escriba strings en un archivo palabras.txt
*		      el programa termina cuando el usuario escribe 's'.
*/

#include <stdio.h>
#include <stdlib.h>//biblioteca estandard, manejo de errores
#include <string.h>

int main(void)
{
	FILE *fp;
	char palabra[50];
	fp= fopen("palabras.txt", "w");//Se abre el archivo para escribir datos; esto borra contenidos previos
	if (fp==NULL)
	{
		printf ("\nArchivo no disponible.");
		exit(1);
	}
	do
	{
		printf("\nDame una palabra: ");
		scanf(" %[^\n]", palabra);
		fprintf(fp, "\n %s", palabra);
	}
	while (strcmp(palabra, "salir") != 0);//si es igual devuelve 0
	fclose(fp);
	printf ("\n");
	return 0;
}

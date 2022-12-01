/*
*Ejemplo de archivos: Haga un prohtama que escriba letras en un archivo letras.txt
*		      el programa ermina cuando el usuario escribe 's'.
*/

#include <stdio.h>
#include <stdlib.h>//biblioteca estandard, manejo de errores

int main(void)
{
	FILE *fp;
	char letra;
	fp= fopen("letras.txt", "a");//Se abre el archivo para anexar datos; esto borra contenidos previos
	if (fp==NULL)
	{
		printf ("\nArchivo no disponible.");
		exit(1);
	}
	do
	{
		printf("\nDame una letra: ");
		scanf(" %c", &letra);
		fprintf(fp, "letra: %c\n", letra);
	}
	while (letra !='s');
	fclose(fp);
	printf ("\n");
	return 0;
}

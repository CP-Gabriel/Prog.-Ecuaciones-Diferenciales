#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mostrarInstrucciones (char nomArch[]);
void ingresarPalabras (char nomArch[]);
void guardarArchivoPalabras (char nomArch[], char palabra[]);
void imprimirArchivoEnPantalla (char nomArch[]);

int main (int argc, char *argv[])
{
	char nomArch[30];
	if (argc == 2)
	{
		strcpy(nomArch, argv[1]);
		mostrarInstrucciones(nomArch);
		ingresarPalabras(nomArch);
		imprimirArchivoEnPantalla(nomArch);
	}
	else
	{
		printf ("\nError en entrada de datos.\n");
	}
	printf ("\n");
	return 0;
}

void mostrarInstrucciones (char nomArch[])
{
	printf ("\nEste programa va a guardar palabras en el archivo: %s", nomArch);
	printf ("\nLa secuencia termina con la palabra fin.\n");
	return;
}

void ingresarPalabras (char nomArch[])
{
	char palabra[20];
	do
	{
		printf ("\nDame una palabra: ");
		scanf ("%s", palabra);
		if (strcmp(palabra, "fin") != 0)
		{
			guardarArchivoPalabras (nomArch, palabra);
		}
	}
	while (strcmp(palabra, "fin") != 0);
        return;
}

void guardarArchivoPalabras (char nomArch[], char palabra[])
{
	FILE *fp;

	fp = fopen (nomArch, "a");
	if (fp == NULL)
	{
		printf ("\nArchivo no disponible.\n");
		exit(1);
	}
	fprintf (fp, "%s", palabra);
	fclose(fp);
        return;
}

void imprimirArchivoEnPantalla (char nomArch[])
{
	FILE *fp;
	char palabra[20];
	int contPal = 1;

	fp = fopen(nomArch, "r");
	if (fp == NULL)
        {
                printf ("\nArchivo no disponible.\n");
                exit(1);
        }
	while (fscanf(fp, "%s", palabra) == 1)
	{
		printf ("%i.  %s\n", contPal, palabra);
		contPal++;
	}
	fclose(fp);
        return;
}



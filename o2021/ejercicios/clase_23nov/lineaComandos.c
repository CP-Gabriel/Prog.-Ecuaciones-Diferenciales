/*
* @file lineaComandos.c
* @brief: este es un ejemplo para entender la línea de comandos.
*	  Este programa identifica en número de argumentos de línea de comandos.
*	  también los muestra en pantalla. Identifica si algo es la palabra "ibero".
*	  Modifique el programa para que anexe en el archivo de texto cuyo nombre esta
*	  en la posición argv[1] los argumentos después de argv[1]
*	  que comiencen con la letra de la 'a' -> 'g'
* @
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//argc:
//*argv:
int contarMayoresA4letras(int numCom, char *comandos[]);
int main(int argc, char *argv[])
{
	int i, pal;
	FILE *fp;
	fp = fopen(argv[1], "w");
	if (fp == NULL)
	{
		printf ("\nArchivo no disponible.\n");
		exit(1);
	}
	printf ("\nEl usuario ingresó %i argumento(s) incluyendo el ejecutable\n", argc-1);
	printf ("\nEl ejecutable es: %s", argv[0]);
	for (i=1; i<argc ; i++)
	{
		if (i!=1)
		{
			if ((argv[i][0]>= 'a')&&(argv[i][0]<='g'))
			{
				fprintf (fp, "%s\n", argv[i]);
			}
			fprintf(fp, "%s\n", argv[i]);
		}
		printf ("\nEl argumento en [%i] es: %s\n", i, argv[i]);
		if (strcmp(argv[i], "ibero")==0)
		{
			printf ("\nYo estudio aquí ;) \n");
		}
	}
	fclose(fp);
	pal=contarMayoresA4letras(argc, argv);
	printf ("\nSe ingresaron %i argumentos que tienen más de 4 chars\n", pal);
	return 0;
}

int contarMayoresA4letras(int numCom, char *comandos[])
{
	int i, mayores=0;
	for (i=2; i<numCom; i++)
	{
		if (strlen(comandos[i])>4)
		{
			mayores = mayores +1;
		}
	}
	return mayores;
}

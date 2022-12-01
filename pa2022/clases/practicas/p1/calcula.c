/**
* @
* @
* @
* @
*/

#include "misDef.h"

extern void convertirHexadecial(char arr1[], char arr2[], char arr3[], char *argv[], int tam);
extern void convertirBinario(char arr1[], char arr2[], char arr3[], char *argv[], int tam);

int main(int argc, char *argv[])
{
	char dat1[50];
	char arr1[20];
	char arr2[20];
	char arr3[20];
	int i, j, tam;

	printf ("\n");
	if(argc == 6)
	{
		sscanf (argv[1], " %i", &tam);
		printf ("tam:  %i\n", tam);
		for (i=1; i<=tam; i++)
		{
			printf ("\nIngresa el número en %s que se guardará en el arreglo1 en la posición %i: ", argv[3], i);
			scanf (" %[^\n]", &arr1[i-1]);
			printf ("\nIngresa el número en %s que se guardará en el arreglo2 en la posición %i: ", argv[4], i);
                        scanf (" %[^\n]", &arr2[i-1]);
		}
		convertirHexadecial(arr1, arr2, arr3, argv, tam);
		convertirBinario(arr1, arr2, arr3, argv, tam);
		printf ("\nContenido: %s", &arr1[0]);
		printf ("\nContenido: %s", &arr2[0]);
		printf ("\nContenido: %s", &arr1[1]);
                printf ("\nContenido: %s", &arr2[1]);
	}
	else
	{
		printf ("\nDatos de entrada incompleto.\n");
	}
	printf ("\n\n");
	return 0;
}

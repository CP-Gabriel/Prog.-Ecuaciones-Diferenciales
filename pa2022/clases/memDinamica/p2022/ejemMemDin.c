/**
* @file ejemMemDin.c
* @brief este ejemplo ilustra el manejo de memoria dinámica con el
* 	 uso de la función malloc.
*	 1) modifique el programa para que la asignación dinámica sea
*	    de n datos de tipo flotante de acuerdo al dato del usuario.
*
* @author Clase de Guillermo Gómez
* @date 31/ene/2022
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	float *apReal;
	int numDatos;

	if((argc == 2) && (sscanf(argv[1], " %i", &numDatos) == 1))
	{
		apReal = (float *)malloc(numDatos *  sizeof(float));
		if(apReal == NULL)
		{
			printf ("\nNo hay memoria disponible.\n");
			exit(1);
		}
		apReal[numDatos-1] = 33.33;
		printf("\nEn apReal[%i] tenemos: %f\n", numDatos-1, apReal[numDatos-1]);
	}
	else
	{
		printf ("\nDatos mal ingresados.\n");
	}
	printf ("\n");
	return 0;
}

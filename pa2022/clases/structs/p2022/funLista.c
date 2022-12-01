/**
* @file funLista.c
* @
* @
*/

#include "tipos.h"

extern void capturarDatos(tipoAlumno arreglo[], int tam)
{
	int i;
	for (i=0; i<tam; i++)
	{
		printf ("\nCapturando dato %i\n", i+1);
		printf ("\nIngresa nombre:");
		scanf (" %[^\n]", arreglo[i].nombre);
		printf ("\nCuenta:");
                scanf (" %i", &arreglo[i].num_cuenta);
		printf ("\nPromedio:");
                scanf (" %f", &arreglo[i].promedio);
		printf ("\nFecha de nacimiento [dia/mes/año]:");
                scanf (" %i/%i/%i", &arreglo[i].nacimiento.dia, &arreglo[i].nacimiento.mes, &arreglo[i].nacimiento.anio);
		printf ("\n");
	}
	return;
}

extern void imprimirDatos(tipoAlumno arreglo[], int tam)
{
	int i;
        for (i=0; i<tam; i++)
        {
                printf ("\nImpresión dato %i\n", i+1);
                printf ("\nNombre: %s", arreglo[i].nombre);
                printf ("\nCuenta: %i", arreglo[i].num_cuenta);
                printf ("\nPromedio: %.2f", arreglo[i].promedio);
                printf ("\nFecha de nacimiento %i/%i/%i", arreglo[i].nacimiento.dia, arreglo[1].nacimiento.mes, arreglo[1].nacimiento.anio);
                printf ("\n");
        }
	return;
}

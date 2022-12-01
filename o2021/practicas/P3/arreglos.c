/**
* @file: arreglos.c
* @brief:Este programa permitirá ingresar 5 valores reales en un primer arreglo y 5 valores reales en un segundo arreglo.
	 1)Se sumaran el primer arreglo mas el segundo arreglo, se guardará y mostrará en un tercer arreglo.
	 2)Se multiplicaran el primer arreglo por el segundo arreglo, se guardará y mostrará en el tercer arreglo.
	 3)Se ordenaran los datos del primer arreglo de menor a mayor y se mostraran en pantalla.
* @authors: Gabriel Coronado/Sergio Esquivel/Sebastian Alanis.
* @date: 23/oct/2021
*/

#include "defArreglos.h"

void imprimirInstrucciones(void);
void ingresarArr(float arreglo1[], float arreglo2[]);
void sumarArr(float arreglo1[], float arreglo2[] , float arreglo3[]);
void multiArr(float arreglo1[], float arreglo2[] , float arreglo3[]);
void ordenarArr1(float arreglo1[]);

int main(void)
{
	int i;
	float arreglo1[TAM], arreglo2[TAM], arreglo3[TAM];
	imprimirInstrucciones();
	ingresarArr(arreglo1, arreglo2);
	printf ("\nSUMA DE LOS ARREGLOS\n");
	sumarArr(arreglo1, arreglo2, arreglo3);
	for (i=1; i<=TAM; i++)
	{
		printf ("%.2f\t", arreglo3[i]);
	}
	printf("\n");
	printf ("\nMULTIPLICACIÓN DE LOS ARREGLOS\n");
	multiArr(arreglo1, arreglo2, arreglo3);
	for (i=1; i<=TAM; i++)
	{
		printf ("%.2f\t", arreglo3[i]);
	}
	printf("\n");
	printf ("\nARREGLO 1 ORDENADO\n");
	ordenarArr1(arreglo1);
	for (i=1; i<=TAM; i++)
        {
                printf ("%.2f\t", arreglo1[i]);
        }
        printf ("\n\n");
	return 0;
}

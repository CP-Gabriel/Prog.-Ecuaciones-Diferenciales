/*
* @file ejemploArreglo.c
* @brief: Este es un programa para entender cómo funcionan los arreglos
*         y como se mandan arreglos a funciones.
* @author: clase de Guillermo Gómez
* @date: 14/oct/2021
*/

#include "definiciones.h"

void ordenar(int elem, int dat[]);
float promedioArreglo(int arreglo[]);
int encontrarMayor(int arreglo[]);
int main(void)
{
        int numeros [TAM];
        int i, mayor;
        float promedio;

        numeros [0] = 10;
        numeros [1] = 23;
        numeros [2] = 0;
        printf ("\nDame el número [3] del arreglo: ");
        scanf (" %i", &numeros[3]);
        numeros [4]= numeros[0]+numeros[1];
        for (i=0; i<TAM; i++)
        {
                printf ("\nEl valor contenido en números [%i] es %i", i, numeros[i]);
        }
        printf ("\n");
	promedio = promedioArreglo(numeros);//Cuando mando un
        				    //arreglo a una función sólo debo indicar el nombre del arreglo
        printf ("\nEl promedio de los números es: %f\n", promedio);
        mayor  = encontrarMayor(numeros);
	printf ("\nEl número mayor en el arreglo es: %i\n", mayor);
	ordenar(TAM, numeros);
	return 0;
}

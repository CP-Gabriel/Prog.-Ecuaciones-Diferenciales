/*
* @file ejemloArreglo.c
* @brief: Este es un programa para entender cómo funcionan los arreglos
*	  y como se mandan arreglos a funciones.
* @author: clase de Guillermo Gómez
* @date: 14/oct/2021
*/

#include "definiciones.h"

void ordenar(int elem, int dat[]);
float promedioArreglo(int arreglo[]);
int encontrarMayor(int arreglo[]);
float devolverResultadosArreglo(int arreglo[], int *men, int *may);

int main(void)
{
	int numeros [TAM];
	int i, mayor;
	float promedio;
	float promedio2;
	int mayor2=0, menor=0;

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
	mayor = encontrarMayor(numeros);
	printf ("\nEl número mayor en el arreglo es: %i\n", mayor );
	printf ("\nEl número mayor en el arreglo es (impesión directa de la función): %i\n", mayor);
	promedio2 = devolverResultadosArreglo(numeros, &menor, &mayor2);
	printf ("\nLos resultados de la función devolverResultadosArreglo son promedio: %f menor: %i mayor: %i\n", promedio2, menor, mayor2);
	return 0;
}

void ordenar(int elem, int dat[])
{
        int i,j,k,temp;
        for (i=0; i<elem; i++)
        {
                for(j=i+1; j<elem; j++)
                {
                        if(dat[i]>dat[j])
                        {
                                temp=dat[i];
                                dat[i]=dat[j];
                                dat[j]=temp;
                        }
                }
        }
        printf ("\nEl arreglo ordenado queda así. \n");
        for(k=0; k<elem; k++)
        {
                printf("Números[%i]: %i\n", k, dat[k]);
        }
        return;
}

float promedioArreglo(int arreglo[])
{
        float resultado=0;
        int i;
        for(i=0; i<TAM; i++)
        {
                resultado= resultado + arreglo[i];
        }
        resultado= resultado/TAM;
        return resultado;
}

int encontrarMayor(int arreglo[])
{
        int may, i;
        may = arreglo[0];
        for (i=1; i<TAM; i++)
        {
                if (arreglo[i]> may)
                {
                        may = arreglo[i];
                }
        }
        return may;
}

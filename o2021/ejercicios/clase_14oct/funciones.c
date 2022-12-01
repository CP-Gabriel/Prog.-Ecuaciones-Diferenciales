/**
* @file:funciones.c
* @brief:Contiene las funciones para manejar arreglos.
* @author:clase de Guillermo Gómez
* @date: 19/oct/2021
**/

#include "definiciones.h"

/**
* @brief:Es una función que permite ordenar un arreglo de
*	 de enteros de forma de ascendente.
* @author:clase de Guillermo Gómez
* @date: 19/oct/2021
* @param elem que es el número de elementos del arreglo de enteros
* @para dat[] es la referencia de un arreglo de enteros.
* @return void
**/

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

/*
* @brief: Es una función que permite calcular el promedio d$
*         contenidos en un arreglo de enteros.
* @author: clase de Guillermo Gómez
* @date: 14/oct/2021
* @param arreglo[] es la referencia de un arreglo de entero$
* @return resultado que es un float
*/

extern float promedioArreglo(int arreglo[])
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

/*
* @brief: Es una función que permite encontrar el número ma$
*         en un arreglo.
* @author: clase de Guillermo Gómez
* @date: 15/oct/2021
* @param arreglo[] es la referencia de un arreglo de entero$
* @return may es el entero más grande
*/

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


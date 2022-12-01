/*
* @file: funcionArreglo.c
* @brief: Este archivo tiene funciones que realizan
	  operaciones con arreglos de enteros.
* @author ckase de Guillermo Gómez
* @date: 02/11/2021
*/

/*
* @brief: Esta función devuelve el promedio, el número menor
	  y mayor de los datos enteros.
* @author clase de Guillermo Gómez
* @date: 02/11/2021
* @param arreglo[] que es un arreglo de enteros.
* @param int *men que es un apuntador de entero.
* @param int *may que es un apuntador de entero.
* @return promedio que es un dato real.
*/
#include <stdio.h>

extern float devolverResultadosArreglo(int arreglo[], int *men, int *may)
{
	int i;
	float promedio=0.0;
	*men=arreglo[0];
	*may=arreglo[0];
	for (i=0; i<5; i++)
	{
		promedio = promedio+arreglo[i];
		if(*men>arreglo[i])
		{
			*men=arreglo[i];
		}
		if(*may<arreglo[i])
		{
			*may=arreglo[i];
		}
	}
	promedio= promedio/5;
	return promedio;
}

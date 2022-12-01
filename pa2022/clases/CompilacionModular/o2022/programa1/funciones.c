/**
* @file funciones.c
* @brief Este es un archivo de las funciones ariméticas que utiliza principal.c
* @author clase de Guillermo Gómez
* @date 17/01/22
*/

#include "misDef.h"

/**
* @brief Esta es una función para calcular el cuadrado de un real.
* @author clase de Guillermo Gómez
* @date 17/01/22
* @param num es un real para calcular el cuadrado.
* @return resultado es un real
*/

extern float calcularCuadrado(float num)
{
	float resultado;
	printf ("\ncalculando el cuadrado...\n");
	resultado = num*num;
	return resultado;
}

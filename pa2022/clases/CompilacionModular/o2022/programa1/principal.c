/**
* @file: principal.c
* @brief: Este es un jemplo de compilación modular. El programa principal
*	  controlará diferentes funciones internas y externas de uso aritmético.
*	  Se  pedirá un dato de un número a un usuario y con este dato se calculará
*	  el cubo (interna), cuadrado (externa)y raíz del número.
* @author clase de Guillermo Gómez
* date 12/ene/2021
*/

#include "misDef.h"
//Prototipos de la función
float calcularCubo(float num);
float calcularCuadrado(float num);
float raiz(float num);

int main(void)
{
	float numero, resultado;

	printf ("\nDame un número y haré varios cálculos: ");
	scanf (" %f", &numero);
	resultado = calcularCubo(numero);
	printf ("\nEl cubo del número es: %f\n", resultado);
	resultado = calcularCuadrado(numero);
#ifdef DEBUG
        printf ("El cuadrado del número es: %f\n", resultado);
	resultado = raiz(numero);
	printf ("\nLa raíz del número es: %f\n", resultado);
#endif
	printf ("\n");
	return 0;
}

/**
* @brief Esta es una función para clacular el cubo de un real.
* @author clase de Guillermo Gómez
* @date 17/01/22
* @param num es un real para calcular el cubo.
* @return resultado es un real
*/

float calcularCubo(float num)
{
	float resultado;
	resultado = num*num*num;
	return resultado;
}

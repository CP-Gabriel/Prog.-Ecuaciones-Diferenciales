/**
* @file ejercicio1.c
* @brief Este programa calucla los multiplos que existen entre el 0 y 100.
* @authors Gabriel Coronado/Sergio Esquivel/Sebastian Alanis
* @date 28/sep/2021
*/

#include <stdio.h>
int multiplos(void);
int main()
{
	printf("\n");
	printf("Este programa calcula los multiplos de 5 que hay entre 0 y 100");
	printf("\n\n");
	printf("Los multiplos de 5 son: ");
	multiplos();
	return 0;
}

/**
* @brief Esta funcion calcula los multiplos de 5 que hay entre 0 y 100.
* @authors Gabriel Coronado/Sergio Esquivel/Sebastian Alanis
* @date 28/sep/2021
* @param resul es un entero, almacena los multiplos de 5
* @return void
*/

int multiplos(void)
{
	int resultado;
	for (resultado = 5; resultado <= 100; resultado+=5)
        {
                printf("%i, ",resultado);
        }
        printf("\n\n");
        return 0;
}

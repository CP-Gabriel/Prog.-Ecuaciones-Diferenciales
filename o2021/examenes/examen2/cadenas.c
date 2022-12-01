/*
* @file: cadenas.c
* @brief: Este programa permite analizar una frase por el usuario, indicando el número de caracteres especial que tenga
*	  la frase y si la frase es espejo muestra un mensaje que lo es.
*	  El programa tambien permite ingresar una cadena de 7 caracteres que representa una linea de operación para que el
*         usuario indique si quiere sumar o multiplicar.Al final dara el resultado.Ejemplo:
*               0  3  0 + 2  5  0
*         La operación siempre es de números de tres digitos, nunca se ingresan especios(en todo caso serian ceros).
* @author: Gabriel Adad Coronado Placeres
* @date: 9/11/21
*/

#include <stdio.h>
#include <string.h>

int analizarFrase(char frase[], int *especiales);
int calcularOperacion(char operacion[]);
int main (void)
{
        int especiales, espejo, resultado;
        char frase[255];
	char operacion[6];
        printf ("\nIngresa una frase: ");
        scanf (" %[^\n]", frase);
        analizarFrase(frase, &especiales);
        printf("\nTu frase tiene %i caracteres especiales", especiales);
        if(espejo==1)
        {
                printf(" y tu frase es espejo.\n");
        }
        else
        {
                printf(" y tu frase no es espejo.\n");
        }
	printf ("\nIngresa la operacion a realizar: ");
	scanf (" %[^\n]", operacion);
	resultado = calcularOperacion(operacion);// Corregido por Guillermo
	printf ("\nEl resultado de su operación es: %i", resultado);
	printf ("\n");
	return 0;
}

/*
* @brief: Este programa calcula el numero de caracteres especiales de frase[] y calcula si la frase es espejo.
* @date: 09/11/21
* @author: Gabriel Adad Coronado Placeres
* @param frase[] es un arreglo string en donde se guarda la frase ingresada por el usuario
* @param *especiales es el apuntador en donde se almacena el numero de caracteres especiales de la frase
* @return espejo es en donde se almacena el valor de 1 ó 0 si la frase es espejo
*/

int analizarFrase(char frase[], int *especiales)
{
        int espejo, tam, i;
        tam= strlen(frase);
        *especiales=0;
        for (i=0; i<tam; i++)
        {
                if ((frase[i] >='!')&&(frase[i] <='/'))
                {
                        ++*especiales;
                }
		if ((frase[i] >=':')&&(frase[i] <='@'))
                {
                        ++*especiales;
                }
        }
        if ((tam%2)==0)
        {
                espejo=1;
        }
        else
        {
                espejo=0;
        }
        return espejo;
}

/*
* @brief: Esta funcion realiza la operacion de la del arreglo operacion[].
* @date: 09/11/21
* @author: Gabriel Adad Coronado Placeres
* @param operacion[] es un arreglo de string en donde se guarda la operacion
* @return resultado es en donde se guardara el resultado
*/

int calcularOperacion(char operacion[])
{
	int i, resultado, tam2;
	tam2=strlen(operacion);
	for (i=0; i<tam2; i++)
	{
		if (operacion[i]==' ')
		{
			operacion[i]=0;
		}
	}
	if (operacion[3]=='+')
	{
		resultado= ((operacion[0]+operacion[4])+(operacion[1]+operacion[5])+(operacion[2]+operacion[6]));
	}
	if (operacion[3]=='*')
        {
                resultado= (((operacion[0]*operacion[4])+(operacion[0]*operacion[5])+(operacion[0]*operacion[6]))+((operacion[1]*operacion[4])+(operacion[1]*operacion[5])+(operacion[1]*operacion[6]))+((operacion[2]*operacion[4])+(operacion[2]*operacion[5])+(operacion[2]*operacion[6])));
        }
	return resultado;
}

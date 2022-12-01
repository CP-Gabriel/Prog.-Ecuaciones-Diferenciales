/*
* @file: examen.c
* @brief: Este programa pide una frase de 24 carácteres para analizar si la frase es "espejo" o no y calcular cuantos
*	  carácteres especiales tiene.
*	  Tambien pide una operación de 7 carácteres, ejemplo:
*		030+250
*	  El programa puede sumar o multiplica, dependediendo si el usuario ingresa el símbolo de + ó x.
* @authors: Gabriel Coronado/Sergio Esquivel/Sebastian Alanis.
* @date:10/11/21
*/

#include <stdio.h>
#include <string.h>

int analizarFrase(char frase[], int *especiales);
int calcularOperacion(char operacion[], int *resultado);
int main(void)
{
	int resultado, espejo;
	int especiales;
	char operacion[6];
	char frase[25];
	printf ("\nIngresa una frase de 24 caracteres: ");
 	scanf ("%[^\n]", frase);
	espejo=analizarFrase(frase, &especiales);
	printf ("\nTu frase tiene %i caracteres especiales y tu frase", especiales);
	if(espejo==1)
	{
		printf (" es espejo\n");
	}
	else
	{
		printf (" no es espejo\n");
	}
	printf("\nIngresa la operación: ");
	scanf(" %[^\n]", operacion);
	calcularOperacion(operacion, &resultado);
	printf (" \nEl resultado de su operación es: %i\n", resultado);
	printf (" \n");
	return 0;
}

/*
* @brief: Está función analiza si la frase ingresada es espejo.También detecta en toda la frase cuáles son los carácteres especiales.
* @authors: Gabriel Coronado/Sergio Esquivel/Sebastian Alanis.
* @date: 10/11/21
* @param frase[] es el arreglo de string en donde se guarda la frase.
* @param *especiales es el apuntador donde se guarda el número de carácteres especiales que tenga la frase.
* @return mirror es la variable en donde guaradará 1 si la frase es espejo o 0 si no.
*/

int analizarFrase(char frase[], int *especiales)
{
	int i;
	int mirror=1;
	*especiales=0;
	int tam=strlen(frase);
	for (i=0; i<tam; i++)
	{
		if (((frase[i] <'A')||(frase[i] >'Z'))&&((frase[i] <'a')||(frase[i] >'z')))
		{
			*especiales=*especiales+1;
		}
	}
	for (i=0; i<12; i++)
	{
		if(frase[i]!=frase[23-i])
		{
			mirror=0;
		}
	}
	return mirror;
}

/*
* @brief: Está función analiza el arreglo operación. Si el usuario ingresa el símbolo de +, el arreglo se suma o si ingresa el símbolo *, el arreglo se multiplica.
* @authors: Gabriel Coronado/Sergio Esquivel/Sebastian Alanis.
* @date: 10/11/21
* @param operacion[] es un string que guarda la operacion
* @param *resultado es el apuntador donde guara el resultado
* @return *resultado es el apuntador donde guardará el resultado de la operación.
*/

int calcularOperacion(char operacion[], int *resultado)
{
	int i;
	int operando1=0;
	int operando2=0;
	for (i=0; i<7; i++)
	{
		if (operacion[i]==' ')
		{
			operacion[i]='0';
		}
	}
	operando1=((operacion[0]-48)*100)+((operacion[1]-48)*10)+(operacion[2]-48);
	operando2=((operacion[4]-48)*100)+((operacion[5]-48)*10)+(operacion[6]-48);
	if (operacion[3]=='+')
	{
		*resultado=operando1+operando2;
	}
	if (operacion[3]=='*')
        {
               *resultado=operando1*operando2;
        }
	return *resultado;
}

/*
* @file: funciones.c
* @brief: En este archivo se encuentran las funciones para el archivo cadena.c
* @authors: Gabriel Coronado/Sergio Esquivel/Sebastian Alanis.
* @date: 02/nov/2021
*/

#include <stdio.h>
#include <string.h>

/*
* @brief: Esta función resive como argumento la frase y sustituye las vocales por números.Sus valores son:
	  a=4
	  e=3
	  i=1
	  o=0
* @authors: Gabriel Coronado/Sergio Esquivel/Sebastian Alanis.
* @date: 02/nov/2021
* @param frase[] es un string.
* @param *numCarac es un apuntador entero del número de vocales.
* @return numCarac es el número de caractares
*/

extern int codificar(char frase[], int *numCarac)
{
	int i;
	*numCarac = *numCarac+strlen(frase);
	for(i=0; i<*numCarac; i++)
	{
		if((frase[i]=='a')||(frase[i]=='A'))
		{
			frase[i]='4';
		}
		if((frase[i]=='e')||(frase[i]=='E'))
                {
                        frase[i]='3';
                }
		if((frase[i]=='i')||(frase[i]=='I'))
                {
                        frase[i]='1';
                }
		if((frase[i]=='o')||(frase[i]=='O'))
                {
                        frase[i]='0';
                }
	}
	return *numCarac;
}

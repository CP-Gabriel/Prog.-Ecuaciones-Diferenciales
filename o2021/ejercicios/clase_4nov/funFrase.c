/*
* @file: funFrase.c
* @brief: En este archivo hay varias funciones que manejaan una frase.
* @author: clase de Guillermo Gómez
* @date: 4/11/21
*/

#include "detFrase.h"

/*
* @brief: ESta fubción nos indica cuántas vocales, mayúsculas y si termina en punto una frase.
* @author: clase de Guillermo
* @date: 4/11/21
* @param fr[] es un string
* @param *voc es un apuntador entero del número de vocales
* @param *may es un apuntador entero del número de mayúsculas
* @param *pun es un apuntador entero para detectar un punto (1/0)
* @return void
*/

extern void contarEnFrase(char fr[], int *voc, int *may, int *pun)
{
	int i, numChars;
	*voc=0;
	*may=0;
	numChars=strlen(fr);
	for (i=0; i<numChars; i++)
	{
		if((fr[i] == 'a')||(fr[i]== 'e')||(fr[i] == 'i')||(fr[i] == 'o')||(fr[i]== 'u'))
		{
			++*voc; //*voc = ++*voc, *voc = *voc+1 ó también *voc+=1
		}
		if((fr[i]=='A')||(fr[i]=='E')||(fr[i]=='I')||(fr[i]=='O')||(fr[i]=='U'))
                {
                        ++*voc; //*voc = ++*voc, *voc = *voc+1 ó también *voc+=1
                }
		if((fr[i] >= 'A')&&(fr[i] <= 'Z'))
		{
			++*may;
		}

	}
	if ((fr[numChars-1])=='.')
                {
                        *pun=1;
                }
                else
                {
                        *pun=0;
                }
	return;
}


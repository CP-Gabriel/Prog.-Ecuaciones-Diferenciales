/**
* @file manejaFrase.c
* @brief este programa es para explicar las distintas funciones de string como strlen, strcpy, strcpm, entre otras
* 1) Invertir una frase
* 2) Cambiar las letras de una frase a mayúsculas o a minúsculas.
* @author clase de Guiller Gómez
* @date 22/oct/2021
*/

#include <stdio.h>
#include <string.h>

void invertirFrase(char fr[], char inv[]);
void convertirMay(char fr[]);
int main(void)
{
	char frase[80], invertida[80];
	int numChars;
	printf ("\nEscribe una frase: ");
	scanf (" %[^\n]", frase);
	numChars= strlen(frase);
	printf ("\nTu frase tiene %i carácteres.\n", numChars);
	printf ("\nEn tu texto en frase[6] esta el char: %c\n", frase[6]);
	invertirFrase(frase, invertida);
	printf ("\nTu frase invertida es: %s\n", invertida);
	printf ("\nTu frase en mayúsculas es: %s\n", frase );
	printf ("\n");
	return 0;
}

void invertirFrase(char fr[], char inv[])
{
	int i, tam;
	tam = strlen(fr);
	for (i=0; i<tam; i++)
	{
		inv[i]= fr[tam-1-i];
	}
	inv[tam]= '\0';
	return ;
}

void convertirMay(char fr[])
{
	int i, tam;
	tam= strlen(fr);
	for (i=0; i<tam; i++)
	{
		if((fr[i]>='a')&&(fr[i]<='z'))
		{
			fr[i]=fr[i]-32;
		}
	}
	return;
}

#include <stdio.h>
#include <string.h>

int main (void)
{
	int valor;
	char frase1[80], frase2[80];
	printf ("\nDame un palabra o frase: ");
	scanf (" %[^\n]", frase1);
	printf ("\nDame una segunda palabra o frase: ");
        scanf (" %[^\n]", frase2);
	valor= strcmp(frase1, frase2);
	if(valor==0)
	{
		printf ("\nLas palabras o frases son iguales.\n");
	}
	if(valor>0)
        {
                printf ("\nLa palabra o frase 2 es menor a frase 1.\n");
        }
	if(valor<0)
        {
                printf ("\nLa palabra o frase 2 es mayor a frase 1.\n");
        }
	strcpy(frase1, frase2);
	printf ("\nSe copió la frase 2 en la frase 1\n");
	printf ("\nFrase 1: %s", frase1);
	printf ("\nFrase 2: %s", frase2);
	printf ("\n");
	
	return 0;
}

int largoFrase(char fr[])
{
	int largo= 0, i =0;
	while (fr[i] != '0')
	{
		largo = largo+1;
		i=i+1;
	}
	return largo;
}


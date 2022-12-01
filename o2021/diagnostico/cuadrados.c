/*
* @file: cuadrados.c
* @brief: Este programa imprime 4 cuadrados lado n ingresado por el usuario, cada cuadrado incrementara de dos en dos sus lados. 
* @author: Gabriel Adad Coronado Placeres
* @date: 29/10/2021
*/

#include <stdio.h>

void cuadrado1(int lado);
void cuadrado2(int lado);
void cuadrado3(int lado);
void cuadrado4(int lado);

int main(void)
{
	int lado;
	printf ("\nEste programa imprime 4 cuadrados, el lado de estos cuadrados ira incrementado de dos en dos \ny el lado de estos lo ingresaras tu.\n");
	printf ("\nIngresa el tamaño inicial de los cuadrados: ");
        scanf (" %i", &lado);
	if(lado>=2&&lado<=10)
	{
		printf ("\nCUADRADO-1\n");
		cuadrado1(lado);
		printf ("\nCUADRADO-2\n");
		cuadrado2(lado);
		printf ("\nCUADRADO-3\n");
		cuadrado3(lado);
		printf ("\nCUADRADO-4\n");
		cuadrado4(lado);
	}
	printf ("\n");
	return 0;
}

/*
* @brief: Esta función imprime un cuadrado de lado n por n ingreado por el usuario.
* @author: Gabriel Adad Coronado Placeres
* @date: 29/10/2021
* @param lado que es la variable en donde se guarda la medida incial del cuadrado.
* @return void
*/

void cuadrado1(int lado)
{
	int i, j;
	for (i=0; i<lado; i++)
	{
		for (j=0; j<lado; j++)
		{
			printf ("*");
		}
		printf ("\n");
	}
	return;
}

/*
* @brief: Esta función imprime un cuadrado de lado n por n, pero suma dos al valor inicial del lado.
* @author: Gabriel Adad Coronado Placeres
* @date: 29/10/2021
* @param lado que es la variable en donde se guarda la medida incial del cuadrado.
* @return void
*/

void cuadrado2(int lado)
{
        int i, j;
	lado= lado+2;
        for (i=0; i<lado; i++)
        {
                for (j=0; j<lado; j++)
                {
                        printf ("*");
                }
                printf ("\n");
        }
        return;
}

/*
* @brief: Esta función imprime un cuadrado de lado n por n, pero suma cuatro al valor inicial del lado.
* @author: Gabriel Adad Coronado Placeres
* @date: 29/10/2021
* @param lado que es la variable en donde se guarda la medida incial del cuadrado.
* @return void
*/

void cuadrado3(int lado)
{
        int i, j;
        lado= lado+4;
        for (i=0; i<lado; i++)
        {
                for (j=0; j<lado; j++)
                {
                        printf ("*");
                }
                printf ("\n");
        }
        return;
}

/*
* @brief: Esta función imprime un cuadrado de lado n por n, pero suma seis al valor inicial del lado.
* @author: Gabriel Adad Coronado Placeres
* @date: 29/10/2021
* @param lado que es la variable en donde se guarda la medida incial del cuadrado.
* @return void
*/

void cuadrado4(int lado)
{
        int i, j;
        lado= lado+6;
        for (i=0; i<lado; i++)
        {
                for (j=0; j<lado; j++)
                {
                        printf ("*");
                }
                printf ("\n");
        }
        return;
}

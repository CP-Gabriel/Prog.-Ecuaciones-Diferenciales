/**
* @file validarPrimo.c
* @brief Este programa valida si un número natural es o no primo.
* @author clase de Guillermo Gómez
* @date 30/sep/2021 
*/
 
#include <stdio.h>

int validarEsPrimo(int n);
void imprimirInstrucciones(void);
int main(void)
{
	int n,resultado;
	do
	{
	imprimirInstrucciones();
	scanf(" %i", &n);
	if(n>0)
	{
		resultado=validarEsPrimo(n);
		if(resultado==1)
		 {
			printf("\nTú numero %i Es Primo\n", n);
		 }
		 else
		  {
			printf("\nTú número %i No es Primo\n", n);
		  }
	}
	else
	 {
		printf("\nTú número %i ingresado no es Natural.\n", n);
	 }
	}while(n<0);
	return 0;
}

/**
* @brief Esta función muestra las instrccuines del programa.
* @author clase de Guillermo Gómez
* @date 30/sep/2021
* @param void
* @retunr void
*/

void imprimirInstrucciones(void)
{
	printf ("\nDame un número natural y te diré si es primo: ");
	return;
}


/**
* @brief Esta función valida si un número es primo.
* @author clase de Guillermo Gómez
* @date 30/sep/2021
* @param n es un número entero natural
* @retunr primo que es 1 si es primo y 0 si no lo es. 
*/

int validarEsPrimo(int n)
{
	int i,primo = 1;
	n = n;
	for(i=2;i<n;i++)
	 {
		if((n % i)==0)
		 {
			primo=0;
		 }
	 }
	return primo;
}

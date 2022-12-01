/**
* @file funciones3.c
* @brief En este archivo hay varias funciones para dibujar piramides.
* @author clase de Guillermo
* @date 08/oct/2021
*/

#include <stdio.h>

/**
* @brief Esta función imprime una piramide centrada con una patron
* @author clase de Guillermo
* @date 08/oct/2021
* @param lado que es un int
* @param patron que es un char
* @return void
*/

extern void piramidePatron(int lado, char patron)
{
        int i, j;
	if (lado%2==0)
	 {
		for(j=lado; j>=1; j-=2)
                 {

                        for(i=1; i<=j; i++)
                         {
                                printf("%c", patron);
                         }
                        printf ("\n");
		 }
		if(j<2)
		 {
			printf ("%c", patron);
		 }
	 }
	else
	 {
		for(j=lado; j>=1; j-=2)
         	 {
                	for(i=1; i<=j; i++)
                 	 {
                        	printf("%c", patron);
                 	 }
                	printf ("\n");
		 }
	 }
        printf ("\n");
        return ;
}

/**
* @brief Esta función imprime una piramide centrada con una patron
* @author clase de Guillermo
* @date 08/oct/2021
* @param patron que es un char
* @return void
*/

extern void piramideN(int lado)
{
        int i, j;
        for(j=1; j<=lado; j++)
         {
                for(i=1; i<=j; i++)
                 {
                        printf ("%i", j);
                 }
                printf ("\n");
        }
        printf ("\n");
        return ;
}

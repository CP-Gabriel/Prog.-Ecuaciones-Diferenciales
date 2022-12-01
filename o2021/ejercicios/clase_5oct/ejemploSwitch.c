/**
* @file ejemploSwitch.c
* @brief Este programa permite imprimir dibujos en terminal del texto.
*	Además es un ejemplo para conocer la sentencia switch.
*	Se practicará el uso de compilación modular.
*
*	PRUEBA DIAGNOSTICO:
*	Agregue al programa las opciones 'C' y 'D'.
*	Opción C: Haga un módulo externo en el archivo funciones3.c que permita dibujar una piramide:
*	Si base es 6:
*	1
*	22
*	333
*	4444
*	55555
*	666666
*
*	Opción D: Haga un módulo/función externa en funcion3.c que permita dibujar la siguiente figura:
*	Si base es impar, ejemplo 7
*	*******
*	 *****
*	  ***
*	   *
*
*	Si base es impar, ejemplo 3:
*	***
*	 *
*
* @author clase de Guillermo
* @date 05/oct/2021
*/

#include <stdio.h>

void dibujarCuadroN(int lado);
void dibujarCuadro(int lado, char patron);
void piramideN(int lado);
void piramidePatron(int lado, char patron);

int main(void) 
{
	char opcion,patron;
	int lado;

	printf ("\nDanos el tamaño del cuadro: ");
	scanf (" %i", &lado);
	printf ("\n¿Qué figura deseas dibujar?, cuadro con patrón ['A'], cuadro con números ['B'], piramide con numeros ['C']");
	printf ("\ny piramide con patrón centrada ['D']: ");
	scanf (" %c", &opcion);
	switch(opcion)
	{
	case 'A': case 'a':
	 {
	 	printf ("\nDame el patrón: ");
		scanf (" %c", &patron);
		printf ("\n");
		dibujarCuadro(lado, patron);
	 };
	break;
	case 'B': case 'b':
	 {
		printf ("\n");
	  	dibujarCuadroN(lado);
	 };
	break;
	case 'C': case 'c':
	 {
		printf ("\n");
		piramideN(lado);
	 };
	break;
	case 'D': case 'd':
         {
		printf ("\nDame el patrón: ");
                scanf (" %c", &patron);
                printf ("\n");
		piramidePatron(lado, patron);
         };
        break;
	default:
	 {
	 	printf ("\nOpción invalida.");
		printf ("\n\n");
	 }
	}
	return 0;
}

/**
* @file hola.c
* @brief Este es un ejemplo para entender el lenguaje C
* 	es para imprimir un mensaje simple en pantalla.
* @author clase de Guillermo Goméz
* @date 21/sep/2021
*
*/
//Seccion de declaraciones y definiciones 
#include <stdio.h>//Declaracion de la biblioteca de I/O de datos en teclado en pantalla

int main(void) // este es el programa principal  
{//Inicio de agrupador de sentencias y expresiones
	int dato; //Parte de declaracion/definición de variables 
	float dato2;
	char letra; 
	printf("\n\tHola mundo.\n"); //Una sentencia que ejecuta la funcion imprimir en pantalla
	dato= 125+37;
	dato2= 125.5 ;
	printf("\nLa suma de 125+37 es :%i\n", dato); 
	return 0;//Fin del  programa principal
}//Fin de agrupador de sentecias y expresiones

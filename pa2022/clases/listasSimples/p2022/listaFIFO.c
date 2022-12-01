/**
* @file listaFIFO.c
* @brief Este es un ejemplo para generar 3 listas: FIFO, LIFO y simple ciricular de datos enteros que están en un
*	  archivo de texto.
* @author Clase de Guillermo Gómez
* @date 28/02/22
*/

#include "tipos.h"

tipoNodo *pushFIFO(int num, tipoNodo *aux);
tipoNodo *pushLIFO(int num, tipoNodo *aux);
void recorrerLista(tipoNodo *aux);

tipoNodo *pop(tipoNodo *aux);
tipoNodo *pushCircular(int num, tipoNodo *refInicio);
void recorrerCircular(tipoNodo *aux);
tipoNodo *popCircular(tipoNodo *aux);

int main(int argc, char *argv[])
{
	tipoNodo *inicio, *inicio2, *inicio3;

	inicio = NULL;
	inicio2 = NULL;
	inicio3 = NULL;
	FILE *fp;
	int num;

	fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
		printf ("\nArchivo no disponible.\n");
		exit(1);
	}

	while(fscanf(fp, "%i", &num) == 1)
	{
		inicio = pushFIFO(num, inicio);//La función que crea la lista dinámica de nodos.
		inicio2 = pushLIFO(num, inicio2);
		inicio3 = pushCircular(num, inicio3);
	}
	fclose(fp);

	printf ("\nLista FIFO:\n");
	recorrerLista(inicio);
	printf ("\nLista LIFO:\n");
	recorrerLista(inicio2);
	printf ("\nBorrar todos los nodos de FIFO:\n");
	do
	{
		inicio = pop(inicio);//Borra registros
	        printf ("\nLista FIFO:\n");
	        recorrerLista(inicio);
	}
	while (inicio != NULL);
	printf ("\nRecorrer lista Circular:\n");
	recorrerCircular(inicio3);
	printf ("\nBorrar todos los nodos de Circular:\n");
	inicio3 = popCircular(inicio3);
	recorrerCircular(inicio3);
	printf ("\n");
	return 0;
}

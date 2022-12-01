/**
* @file funLista.c
* @brief Funciones para crear, borrar y recorrer listas: LIFO, FIFO y simple circular.
* @author clase de Guillermo Gómez
* @date 28/02/22
*/

#include "tipos.h"

/**
* @brief Esta función recibe com oargumentos un entero y la dirección inicial de una lista FIFO;
*	 con los datos anexa un nodo en la lista.
* @author clase de Guillermo Gómez
* @date 28/02/22
* @param num que es un entero.
* @param *aux que es un apuntador auxiliar.
* @return *aux que es el final de la lista.
*/

extern tipoNodo *pushFIFO(int num, tipoNodo *aux)
{
	int i = 0;
	tipoNodo *nuevo, *fin;

	fin=aux;
	nuevo =(tipoNodo *)malloc(sizeof(tipoNodo));
	if (nuevo == NULL)
	{
		printf ("\nMemoria no disponible.\n");
		exit(1);
	}
	nuevo->numero = num;
	if (aux == NULL)
	{
		aux = nuevo;
		nuevo->next = NULL;
	}
	else
	{
		while (fin->next != NULL)
		{
			++i;
			fin = fin->next;
//			printf ("\n%i FIFO", i);
		}
		fin->next = nuevo;
		nuevo->next = NULL;
	}
 	return aux;
}

void recorrerLista(tipoNodo *aux)
{
	//char r;
	while (aux != NULL)
	{
		printf ("\nEste nodo -> numero hay: %i en dir de aux: %p\n", aux->numero, aux);
		aux = aux->next;
	}
	return;
}

extern tipoNodo *pushLIFO(int num, tipoNodo *aux)
{
//	int i = 0;
	tipoNodo *nuevo;

	nuevo = (tipoNodo *)malloc(sizeof(tipoNodo));
	if (nuevo == NULL)
	{
		printf ("\nMemorira no disponible.\n");
		exit(1);
	}
	nuevo->numero = num;
//	++i;
	if (aux == NULL)
	{
		aux = nuevo;
		nuevo->next = NULL;
	}
	else
	{
//		printf ("\n%i LIFO", i);
		nuevo->next = aux;
		aux = nuevo;
	}
	return aux;
}

extern tipoNodo *pop(tipoNodo *aux)
{
	tipoNodo *borrar;
	if(aux != NULL)
	{
		borrar = aux;
		aux = aux->next;
		free(borrar);
	}
	else
	{
		printf ("\nLa lista esta vacia\n");
	}
	return aux;
}

/*
*
*
*
*
*
*
*/

extern tipoNodo *pushCircular(int num, tipoNodo *refInicio)
{
	tipoNodo *aux, *nuevo;

	nuevo = (tipoNodo *)malloc(sizeof(tipoNodo));
        if (nuevo == NULL)
        {
                printf ("\nMemorira no disponible.\n");
                exit(1);
        }
	nuevo->numero = num;
	if (refInicio == NULL)
	{
		refInicio = nuevo;
		nuevo->next = refInicio;
	}
	else
	{
		aux = refInicio;
		while(aux->next != refInicio)
		{
			aux = aux->next;
		}
		aux->next = nuevo;
		nuevo->next = refInicio;
	}
	return refInicio;
}

void recorrerCircular(tipoNodo *aux)
{
	tipoNodo *ref;
	ref = aux;
	if (ref == NULL)
	{
		printf ("\nLista vacia.\n");
	}
	else
	{
		do
		{
			printf ("\nEl nodo contiene: %i en la dirección %p\n", aux->numero, aux);
			aux = aux->next;
		}
		while (aux != ref);
	}
	return;
}

extern tipoNodo *popCircular(tipoNodo *aux)
{
	tipoNodo *borra, *refInicio;
	if (aux == NULL)
	{
		printf ("\nLista circular vacia.\n");
	}
	else
	{
		refInicio = aux;
		borra = aux;
		while (aux->next != refInicio)
		{
			aux = aux->next;
		}
	}
	return aux;
}

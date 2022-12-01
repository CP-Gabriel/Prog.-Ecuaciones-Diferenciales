/*
* @file: pizza.c
* @brief: Este programa ayuda a una pizzería automatizar sus ventas.
*	  1.Se tiene que hacer una función que permita dar de alta a los clientes, la pizza y el tamaño.
*	  2.Hacer una función que imprima en pantalla la lista de clientes capturados.
* 	  3.Hacer una funcion que ordena alfabeticamente (a-z) los datos de acuerdo al nombre.
*	  4.Hacer una función que permita calcular el total a pagar, retornar la variable para imprimirlo en main.
* @author: Gabriel Adad Coronado Placeres
* @date: 30/11/21
*/

#include "misDef.h"

void registrarCliente(struct client cliente[], int tam);
void imprimirClientes(struct client cliente[], int tam);
void registroClientes(struct client cliente[], int tam);
int calcularPago(struct client cliente[], int tam, int indice, int *total);

int main(void)
{
	int tam, indice, pago;
	int total=0;
	struct client cliente[tam];
	do
	{
		system ("clear");
		printf ("\nPIZZAS\n");
		printf ("\n¿Cuántos clientes se daran de alta? ");
		scanf (" %i", &tam);
		if ((tam>=1) && (tam<=4))
		{
			registrarCliente(cliente, tam);
		        registroClientes(cliente, tam);
		        imprimirClientes(cliente, tam);
			printf ("\nIngrese el numero del usuario que desea mostrar su total a pagar: ");
			scanf (" %i", &indice);
			calcularPago(cliente, tam, indice, &total);
			printf ("\nEl total a pagar del cliente %i es: %i", indice, total);
		}
		else
		{
			printf ("\nSolo puedo aceptar máximo a 4 clientes");
		}
	}
	while (tam>4);
	printf ("\n");
	return 0;
}

/*
* @brief: Esta funcion permite registrar los datos de los clientes (nombre, tipo de pizza y tamaño).
* @author: Gabriel Adad Coronado Placeres
* @date: 30/11/21
* @param cliente es el arreglo de strings que guarda los datos del cliente
* @tam es un entero que almacena el número de clientes que se registraran
* @return void
*/

void registrarCliente(struct client cliente[], int tam)
{
	int i;
	for (i = 0; i<tam; i++)
	{
		system ("clear");
                printf ("\nPIZZAS\n");
                printf ("\nPizzas 	     Chica           Mediana         Grande");
                printf ("\nMargarita    $100            $110            $120");
                printf ("\nPepperoni    $120            $130            $140\n");
		printf ("\nUsuario %i", (i+1));
		printf ("\nIngrese su nombre corto: ");
		scanf (" %s", cliente[i].nombre);
		printf ("\nm-Margarita		p-Pepperoni\n");
		printf ("\nIngrese la letra del tipo de pizza que quiere: ");
		scanf (" %c", &cliente[i].pizza);
		printf ("\nc-Chica		m-Mediana	g-Grande\n");
                printf ("\nIngrese la letra del tamaño de su pizza: ");
                scanf (" %c", &cliente[i].tampizza);
	}
	return;
}

/*
* @brief: Esta funcion permite imprimir los datos de los clientes en orden alfabetico.
* @author: Gabriel Adad Coronado Placeres
* @date: 30/11/21
* @param cliente es el arreglo de strings que guarda los datos del cliente
* @tam es un entero que almacena el número de clientes que se registraran
* @return void
*/

void imprimirClientes(struct client cliente[], int tam)
{
	int i;
	system ("clear");
        printf ("\nPIZZAS\n");
        printf ("\nUsuarios registrados: %i", tam);
	printf ("\n");
        for (i=0; i<tam; i++)
        {
                printf ("\nUsuario %i", (i+1));
                printf ("\nNombre: %s", cliente[i].nombre);
                if(cliente[i].pizza=='m')
                {
                        printf ("\nTipo de pizza: Margarita");
                }
                if(cliente[i].pizza=='p')
                {
                        printf ("\nTipo de pizza: Pepperoni");
                }
                if(cliente[i].tampizza=='c')
                {
                        printf ("\nTamaño de pizza: Chica");
                }
                if(cliente[i].tampizza=='m')
                {
                        printf ("\nTamaño de pizza: Mediana");
                }
		if(cliente[i].tampizza=='g')
                {
                        printf ("\nTamaño de pizza: Grande");
                }
                printf ("\n");
        }
	return;
}

/*
* @brief: Esta funcion permite ordenar los datos de los clientes en ornden alfabetico.
* @author: Gabriel Adad Coronado Placeres
* @date: 30/11/21
* @param cliente es el arreglo de strings que guarda los datos del cliente
* @tam es un entero que almacena el número de clientes que se registraran
* @return void
*/

void registroClientes(struct client cliente[], int tam)
{
	int i, j;
	struct client temp;
	for (i=0; i<tam; i++)
	{
		for (j=i+1; j<tam; j++)
		{
			if(strcmp(cliente[i].nombre, cliente[j].nombre)>0)
			{
				temp=cliente[i];
				cliente[i]=cliente[j];
				cliente[j]=temp;
			}
		}
	}
	return;
}

/*
* @brief: Esta funcion permite calcular el total a pagar de un determinado cliente
* @author: Gabriel Adad Coronado Placeres
* @date: 30/11/21
* @param cliente es el arreglo de strings que guarda los datos del cliente
* @tam es un entero que almacena el número de clientes que se registraran
* @indice es el indice del usuario que se calculara su total a pagar
* @*total es el apuntador que almacenta el total a pagar
* @return *total es un apuntador que almacena el total a pagar
*/

int calcularPago(struct client cliente[], int tam, int indice, int *total)
{
	if(cliente[indice-1].pizza=='m')
	{
		if(cliente[indice-1].tampizza=='c')
	        {
			*total = *total+100;
	        }
	        if(cliente[indice-1].tampizza=='m')
	        {
			*total = *total+110;
	        }
	        if(cliente[indice-1].tampizza=='g')
	        {
			*total = *total+120;
       		}
        }
	if(cliente[indice-1].pizza=='p')
        {
                if(cliente[indice-1].tampizza=='c')
                {
                        *total = *total+120;
                }
                if(cliente[indice-1].tampizza=='m')
                {
                        *total = *total+130;
                }
                if(cliente[indice-1].tampizza=='g')
                {
                        *total = *total+140;
                }
        }
	return *total;
}

/*
* @brief: Esta funcion permite guardar los datos de los clientes.
* @author: Gabriel Adad Coronado Placeres
* @date: 30/11/21
* @param cliente es el arreglo de strings que guarda los datos del cliente
* @tam es un entero que almacena el número de clientes que se registraran
* @return void
*/

/*
void guardarClientes(struct client cliente[], , int tam, char nomArch[])
{
	int i;
	FILE *fp;
	if (fp == NULL)
	{
		printf ("\nArchivo no disponible.\n");
		exit(1);
	}
	fprintf ("PIZZERIA");
	fprintf ("CLIENTES");
	for (i=0; i<tam; i++)
	{
		fprintf ("");
	}
	return;
}
*/

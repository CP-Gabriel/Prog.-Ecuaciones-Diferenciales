/**
* @file listaDobPet.c
* @brief A)Este programa crea una lista doble enlazada de apuntadores
*	 del tipoMascotas. Los datos para crear la lista los lee del archivo
*	 mascotas.bin.




*	 B)Se requiere de un struct que permita navegar en la lista doble y haga los siguientes cálculo:
*	   □ Promedio de edad de todas las mascotas.
*	   □ Identificar la macota que pesa menos.
*	   □ Identificar la mascota que pesa más.
*	   □ Que construya una lista de las razas sin repeticiones.
*
* @author clase de Guillermo Gómez.
* @date
*/

#include "tipos.h"

tipoNodo *crearListaDoble(tipoNodo *aux, tipoMascota mascota);
void recorrerSiguientes(tipoNodo *aux);
void recorrerAnteriores(tipoNodo *aux);
tipoNodo *borrarNodo(tipoNodo *aux);
void calcularDatosMascotas (tipoNavegador *navAux);

//void recorrerListaRazas(nodito *aux);
tipoNodo *listaFIFO(tipoNodo *aux, tipoMascota datos);
void recorrerLista(tipoNodo *aux);
tipoNodo *pop(tipoNodo *aux);

int main(int argc, char *argv[])
{
	char opcion = 's';
	tipoNodo *inicio, *inicio2;
	FILE *fp;
	tipoMascota datos;
	tipoNavegador nav;

	//Iniciar los valores del navegador.
	nav.pesoMax = 0;
	nav.pesoMin = 0;
	nav.promEdad = 0;
	nav.inicioRazas = NULL;
	nav.refInicio = NULL;
	nav.aux = NULL;

	inicio = NULL;
	inicio2 = NULL;

	fp = fopen("mascotas.bin", "r+b");
	if (fp == NULL)
	{
		printf ("\nArchivo no disponible.\n");
		exit(1);
	}
	while (fread(&datos, sizeof(tipoMascota), 1, fp) == 1)
	{
		inicio = crearListaDoble(inicio, datos);
		inicio2 = listaFIFO(inicio2, datos);
	}
	fclose(fp);
	printf ("\nRecorrido en sentido -> siguientes:");
	recorrerSiguientes(inicio);
	printf ("\nRecorrido en sentido -> anteriores:");
        recorrerAnteriores(inicio);

	printf ("\nDeseas borrar el nodo inicial: ");
	scanf (" %c", &opcion);

	while (opcion == 's')
	{
		printf ("\nDeseas borrar el nodo inicial: ");
		scanf (" %c", &opcion);
		if (opcion == 's')
		{
			inicio = borrarNodo(inicio);
			printf ("\nIMPRESION");
			recorrerSiguientes(inicio);
		}
	}
	nav.refInicio = inicio;
	nav.aux = inicio;
//	calcularDatosMascotas (&nav);
//	printf ("\nEl mayor peso registrado es: %f y el menor es: %f\n", nav.pesoMax, nav.pesoMin);
//	printf ("\nEl promedio de las edades registradas es: %f\n", nav.promEdad);
	printf ("\nLISTA FIFO:");
//	inicio2 = pop(inicio2);
	recorrerLista(inicio2);
//	recorrerListaRazas(nav.inicioRazas);
	printf ("\n");
	return 0;
}

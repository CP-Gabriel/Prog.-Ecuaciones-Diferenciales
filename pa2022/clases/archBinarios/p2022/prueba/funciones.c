/**
* @
* @
* @
*/

#include "tipos.h"

/**
* @
* @
* @
*/

extern tipoNodo *crearListaDoble(tipoNodo *aux, tipoMascota mascota)
{
	tipoNodo *nuevo, *fin;

	nuevo = (tipoNodo *)malloc(sizeof(tipoNodo));

	if(nuevo == NULL)
	{
		printf("\nMemoria no disponible\n");
		exit(1);
	}
	nuevo->datos = mascota;
	if(aux == NULL)//primer caso: lista vacía
	{
		aux = nuevo;
		nuevo->sig = aux;
		nuevo->ant = aux;
	}
	else//segundo caso: existe al menos un nodo
	{
		fin = aux->ant;
		aux->ant = nuevo;
		nuevo->sig = aux;
		nuevo->ant = fin;
		fin->sig = nuevo;
	}
	return aux;
}

/**
* @
* @
* @
*/

extern void recorrerSiguientes(tipoNodo *aux)
{
	tipoNodo *refInicio;

	refInicio = aux;
	if(aux != NULL)
	{
		do //while(aux!= refInicio)
		{
			printf("\nRaza: %s Peso: %f Edad: %i\n",aux->datos.raza,aux->datos.peso,aux->datos.edad);
			aux = aux->sig;
		}
		while(aux != refInicio);
	}
	else
	{
  		printf("\nLa lista esta vacía\n");
		exit(1);
	}
  return;
}

extern void recorrerAnteriores(tipoNodo *aux)
{
	tipoNodo *refInicio;

	refInicio = aux;
	if(aux != NULL)
	{
		//aux = aux->ant;
		do
		{
			printf ("\nRaza: %s\tPeso: %f\tEdad: %i\n", aux->datos.raza, aux->datos.peso, aux->datos.edad);
			aux = aux->ant;
		}
		while (aux != refInicio);
	}
	else
	{
		printf ("\nLista vacia.\n");
		exit(1);
	}
	return;
}

extern tipoNodo *borrarNodo(tipoNodo *aux)
{
	tipoNodo *borrar;

	if (aux != NULL)
	{
		borrar = aux;
		if (aux->sig == aux)
		{
			aux = NULL;
			free(borrar);
		}
		else
		{
			aux = aux->sig;
			borrar->ant->sig = aux;
			aux->ant = borrar->ant;
			free(borrar);
		}
	}
	else
	{
		printf ("\nNo se pueden borrar nodos en lista vacia.\n");
		exit(1);
	}
	return aux;
}

/**
* @
* @
* @
*/

////////////////ASESORIA

/*extern void verificarDatos(tipoNodo *aux)
{
        tipoNodo *refInicio;

        refInicio = aux;
        if(aux != NULL)
        {
		do
                {
                        printf("\nRaza: %s Peso: %f Edad: %i",aux->datos.raza,aux->datos.peso,aux->datos.edad);
			printf("Direccion de memoria: %p\n", aux);
                        aux = aux->sig;
                }
                while(aux != refInicio);
        }
        else
        {
                printf("\nLa lista esta vacía\n");
                exit(1);
        }
	return;
}*/

/**
* @
* @
* @
*/

/*int identificarMascotas(tipoMascota *aux, int edad, float peso)
{
	char tipo[50];
	float weight;
	int age;
	int coincidencias = 0;

	tipoNodo *refInicio;
        refInicio = aux;

        if(aux != NULL)
        {
		printf ("\nFILTRAR DATOS\n");
		printf ("Ingresa el tipo de raza o mascota que quieres buscar: ");
		scanf (" %[^\n]", tipo);
		printf ("Ingresa el peso ha filtrar: ");
		scanf (" %f", &weight);
		printf ("Ingresa el tipo de raza o mascota que quieres buscar: ");
		scanf (" %i", &age);

                printf("\nRaza: %s Peso: %f Edad: %i",aux->datos.raza,aux->datos.peso,aux->datos.edad);
		printf ("\n");
		do
                {
			if (strcmp(aux->datos.raza, tipo) == 0)
			{
				if (aux->datos.peso >= weight)
				{
					if (aux->datos.edad >= age)
					{
						//coincidencias++;
						++coincidencias;
					}
				}
			}
                        aux = aux->sig;
                }
                while(aux != refInicio);
        }
        else
        {
                printf("\nLa lista esta vacía\n");
                exit(1);
	}
	return coincidencias;
}

/////////////////////////////////ASESORIA

/**
* @
* @
* @
*/

nodito *crearFIFOrazas(nodito *aux, char nomRaza[])
{
	int existeRaza = 0;
        nodito *nuevo, *fin;
        nuevo = (nodito *)malloc(sizeof(nodito));

        if (nuevo == NULL)
        {
                printf ("\nMemoria no disponible.\n");
                exit(1);
        }
        strcpy(nuevo->raza, nomRaza);
        nuevo->next = NULL;
        if (aux == NULL)
        {
                aux = nuevo;
        }
        else
        {
                fin = aux;
 	        while (fin->next != NULL)
                {
//			do
//			{
				if (strcmp(nomRaza, fin->raza) == 0)
				{
					existeRaza = 1;
				}
	                        fin = fin->next;
//			}
//			while (fin != NULL);
			if (existeRaza == 1)
			{
				free(nuevo);
			}
			else
			{
				fin->next = nuevo;
			}
                }
        }
        return aux;
}

extern void calcularDatosMascotas (tipoNavegador *navAux)
{
	int numNodo = 0;
	if (navAux->refInicio != NULL)
	{
		navAux->pesoMin = navAux->aux->datos.peso;
		do
		{
			++numNodo;
			navAux->promEdad = navAux->promEdad + navAux->aux->datos.edad;
			if (navAux->pesoMax < navAux->aux->datos.peso)
			{
				navAux->pesoMax = navAux->aux->datos.peso;
			}

			if (navAux->pesoMin > navAux->aux->datos.peso)
                        {
                                navAux->pesoMin = navAux->aux->datos.peso;
                        }
			printf ("\nNodo %i\nRaza: %s\tPeso: %f\tEdad: %i\n", numNodo, navAux->aux->datos.raza, navAux->aux->datos.peso, navAux->aux->datos.edad);
//			navAux->inicioRazas = crearFIFOrazas(navAux->inicioRazas, navAux->aux->datos.raza);
			
			navAux->aux = navAux->aux->sig;
		}
		while (navAux->aux != navAux->refInicio);
		navAux->promEdad = navAux->promEdad / numNodo;
	}
	return;
}

/**
* @
* @
* @
*/

/*extern void recorrerListaRazas(nodito *aux)
{
	if (aux == NULL)
	{
		printf ("\nLista vacia.\n");
		exit(1);
	}
	else
	{
		printf ("\nLISTA FIFO:");
		while (aux != NULL)
		{
			printf("\nEn la dirección: %p esta la raza: %s\n", aux, aux->raza);
			aux = aux->next;
		}
	}
	return;
}
*/

extern tipoNodo *listaFIFO(tipoNodo *aux, tipoMascota mascota)
{
	int i = 0;

	tipoNodo *nuevo, *fin;
        fin = aux;

        nuevo =(tipoNodo *)malloc(sizeof(tipoNodo));
        if (nuevo == NULL)
        {
                printf ("\nMemoria no disponible.\n");
                exit(1);
        }
        nuevo->datos = mascota;
        if (aux == NULL)
        {
                aux = nuevo;
                nuevo->pass = NULL;
	}
        else
        {
                while (fin->pass != NULL)
                {
                        fin = fin->pass;
                }
                fin->pass = nuevo;
                nuevo->pass = NULL;
        }
	return aux;
}

/**
* @
* @
* @
*/

extern tipoNodo *pop(tipoNodo *aux)
{
        tipoNodo *borrar;

        if(aux != NULL)
        {
                borrar = aux;
                aux = aux->pass;
                free(borrar);
        }
        else
        {
                printf ("\nLa lista esta vacia\n");
        }
        return aux;
}

int recorrerLista(tipoNodo *aux)
{
	tipoNodo *aux2;
	int i, j;
	int borrar;
	aux2 = aux->pass;
//   	printf("\nRaza: %s\n", aux->datos.raza);
	while (aux != NULL)
	{
		aux2 = aux2->pass;
//		printf("\nRaza: %s\n", aux2->datos.raza);
		printf("\n222222222");
/*		if (strcmp(aux->datos.raza, aux2->datos.raza) == 0)
		{
			free(aux2);
		}*/
                aux = aux->pass;
        }
	while (aux != NULL)
        {
		printf("\nRaza: %s Peso: %f Edad: %i\n", aux->datos.raza, aux->datos.peso, aux->datos.edad);
		aux = aux->pass;
	}
        return borrar;
}

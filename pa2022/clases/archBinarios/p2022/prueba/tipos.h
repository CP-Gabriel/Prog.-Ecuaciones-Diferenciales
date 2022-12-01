#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mascotas
{
	char raza[80];
	float peso;
	int edad;
};

typedef struct mascotas tipoMascota;

struct nodo
{
	tipoMascota datos;
	struct nodo *sig, *ant;
	struct nodo *pass;
};

typedef struct nodo tipoNodo;

/////////////////////////////

struct lista
{
	char raza[80];
	struct lista *next;
};
typedef struct lista nodito;

struct navegador
{
	float pesoMax, pesoMin, promEdad;
	nodito *inicioRazas;
	tipoNodo *refInicio, *aux;
};

typedef struct navegador tipoNavegador;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alumnos
{
        int numCuenta;
        char nombre[40];
        float promedio;
	char carrera[40];
};
typedef struct alumnos tipoAlumno;

struct nodo
{
        tipoAlumno datos;
        struct nodo *izq, *der;
};
typedef struct nodo nodoAlumno;


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mascota
{
        int numCliente;
        char raza[40];
        char nombre[40];
        int edad;
        float peso;
};
typedef struct mascota tipoMascota;

struct nodo
{
        tipoMascota datos;
        struct nodo *izq, *der;
};
typedef struct nodo nodoMascota;

/*struct registro
{
	int infante = 0;
	int adulto = 0;
	int anciano = 0;
}
typedef struct registro tipoRegistro;*/

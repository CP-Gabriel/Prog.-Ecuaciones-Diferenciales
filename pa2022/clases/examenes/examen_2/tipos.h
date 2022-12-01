#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*struct pacientes
{
        char nombre[20];
	float peso;
	float altura;
	int trig;
};
typedef struct pacientes tipoPaciente;*/

struct nodo
{
//        tipoPaciente registro;
	char nombre[20];
        float peso;
        float altura;
        int trig;
        struct nodo *sig, *ant;
};
typedef struct nodo tipoNodo;

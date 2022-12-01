#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct pacientes
{
	char nombre[80];
	char apellido[80];
	char codigop[5];
	bool diagnostico;// = true;
	//diagnostico = false;
	char diagnostic;
	struct pacientes *next;
};

typedef struct pacientes tipoRegistro;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ciudadanos
{
	char nombre[80];
	int cp;
	int edad;
	char aplicacion[20];
	struct ciudadanos *next;
};

typedef struct ciudadanos tipoCiudadano;

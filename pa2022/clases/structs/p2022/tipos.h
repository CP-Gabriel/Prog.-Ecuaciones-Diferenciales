#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct fecha{
	int mes;
	int dia;
	int anio;
};

struct alumno{
	int num_cuenta;
	char nombre[80];
	float promedio;
	struct fecha nacimiento;
};

typedef struct alumno tipoAlumno;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct fecha
{
        int dia;
        int mes;
        int anio;
};

struct alumno
{
        char nombre[80];
        int numCuenta;
        float promedio;
        struct fecha nacimiento;
};

typedef struct alumno datAlumno;

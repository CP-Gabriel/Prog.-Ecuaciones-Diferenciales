#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct alumno
{
  char nombre[80];
  int cuenta;
  float promedio;
  struct alumno *next;
};

typedef struct alumno tipoAlumno;

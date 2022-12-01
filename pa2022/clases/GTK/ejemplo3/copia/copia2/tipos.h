#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct alumno
{
	char nombre[80];
	int cuenta;
	float promedio;
	struct alumno *next;
//        GtkWidget *entrada, *estatus, *label2;
};
typedef struct alumno tipoAlumno;

struct referencia
{
        GtkWidget *entrada, *estatus, *label2;
//        tipoAlumno *inicio;
//        int contPush, contPop;
};
typedef struct referencia ref;

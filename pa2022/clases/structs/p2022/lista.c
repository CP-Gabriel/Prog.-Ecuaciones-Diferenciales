/**
* @file lista.
* @brief este es un ejemplo de manejo de structs.
*	 1) Haga la programación para que se cree un arreglo de alumnos
*	    del tamañp que ingrese un usuario.
*	 2) Coloque un apuntador del tipoAlumno en el índice 5 del arreglo.
*	    Capture los datos del alumno con la nomb
*/
#include "tipos.h"

int main(int argc, char *argv[])
{
	tipoAlumno *lista, *apAlumno;
	int tam;
	if ((argc == 2) && (sscanf(argv[1], " %i", &tam) == 1))
	{
		lista = (tipoAlumno *)malloc(tam * sizeof(tipoAlumno));
		if(lista == NULL)
		{
			printf ("\nNo hay memoria disponible.\n");
			exit(1);
		}
		//Asignar los datos del alumno en la posición 10 del arreglo
		lista[10].num_cuenta = 234567;
		strcpy(lista[10].nombre, "Predo Pérez");
		lista[10].promedio = 9.8;
		lista[10].nacimiento.dia = 3;
		lista[10].nacimiento.mes = 5;
		lista[10].nacimiento.anio = 2001;
		printf ("\nAlumno: %s \ncta: %i \npromedio: %f \naño: %i\n", lista[10].nombre, lista[10].num_cuenta, lista[10].promedio, lista[10].nacimiento.anio);
	}
	apAlumno = &lista[4];
	apAlumno->num_cuenta = 234567;
	strcpy(apAlumno->nombre, "Toño López");
	apAlumno->promedio = 8.9;
	apAlumno->nacimiento.dia = 1;
	apAlumno->nacimiento.mes = 12;
	apAlumno->nacimiento.anio = 2002;
	printf ("\nAlumno: %s \ncta: %i \npromedio: %f \naño: %i\n", lista[4].nombre, lista[4].num_cuenta, lista[4].promedio, lista[4].nacimiento.anio);
	printf ("\n");
	return 0;
}

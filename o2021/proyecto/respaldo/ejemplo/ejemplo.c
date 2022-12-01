/*
#include "misDef.h"

extern int registrarUsuario(struct user usuario, int *nuevoUsuario);
extern void guardarDatosArchivo(struct user usuario, char nomArch[]);#include "misDef.h"
*/
#include "misDef.h"

void registrarAlumno(struct alumno alumnos/*[]*/);
void guardarDatosArchivo(struct alumno alumnos/*[]*/, char nomArch[]);
int main(void)
{
	struct alumno alumnos/*[1]*/;
	registrarAlumno(alumnos);
	guardarDatosArchivo(alumnos, "alumnos.txt");
	return 0;
}

void registrarAlumno(struct alumno alumnos/*[]*/)
{
	int i;
	/*for (i=0; i<1; i++)
	{*/
	//printf ("\nAlumno en el indice %i ", i);
	printf ("\nDame el nombre: ");
	scanf (" %[^\n]", alumnos/*[i]*/.nombre);
	printf ("\nPromedio: ");
	scanf (" %f", &alumnos/*[i]*/.promedio);
	printf ("\nCuenta: ");
        scanf (" %i", &alumnos/*[i]*/.numCuenta);
	printf ("\ndia mes año, separado en espacios: ");
        scanf (" %i %i %i", &alumnos/*[i]*/.nacimiento.dia, &alumnos/*[i]*/.nacimiento.mes, &alumnos/*[i]*/.nacimiento.anio);
	//}
	return;
}

void guardarDatosArchivo(struct alumno alumnos[], char nomArch[])
{
	int i;
	FILE *fp;
	fp=fopen(nomArch, "a");
	if (fp == NULL)
	{
		printf ("\nArchivo no disponible.");
		exit(1);
	}
	/*for (i=0; i<1; i++)
	{*/
	fprintf (fp, "%i\n", alumnos/*[i]*/.numCuenta);
	fprintf (fp, "%s\n", alumnos/*[i]*/.nombre);
	fprintf (fp, "%i/%i/%i\n", alumnos/*[i]*/.nacimiento.dia, alumnos/*[i]*/.nacimiento.mes, alumnos/*[i]*/.nacimiento.anio);
	fprintf (fp, "%f\n", alumnos¨/*[i]*/.promedio);
	//}
	fclose(fp);
	return;
}

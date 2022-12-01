/*
* @file: ejemploStruct.c
* @brief:
* 1.- Entender como capturar e imprimir los datos de una variable de struct.
* 2.- Entender como capturar e imprimir datos en una variable de arreglo de structs.
* 3.- Cómo ordenar los datos en un arreglo de structs de acuerdo de algún criterio: #cuenta ó nombre A-Z.
* 4.- Cómo localizo un registro por el número de cuenta.
* 5.- Preguntar si desea modificar los datos del alumno licalizado.
* 6.- Haga una función que mande la dirección de una variable de un struct
*     de tipo añumno y modifique el promedio dentro de la función. Es la dirección
*     de un alumno de nuestro arreglo.
*     El programa le va a preguntar al usuario qué alumno (indice del arreglo) desea que se modifique.
*     su promedio. La función va a recibir la dirección del struct en ese índice del arreglo; y con
*     la ayuda de un apuntador, va a modificar el promedio en la variable global de main.
*     Se va a mandar imprimir para verificar el cambio.
* 7.- Al final del programa, los datos deben quedar guardados en
*     el archivo alumnos.txt.
* @author: clase de Guillermo Gómez.
* @date:
*/

#include "misDef.h"

void registrarAlumno(struct alumno arr[]);
void mostrarAlumno(struct alumno arr[]);
void ordenarXpromedio(struct alumno arr[]);
void ordenarXnombre(struct alumno arr[]);
void buscarAlumno(struct alumno arr[]);
void modicarPromedio(struct alumno *pAlumno);
void guardarDatosArchivo(struct alumno arr[], char nomArch[]);
void leerDatosArchivo(struct alumno arr[], char nomArch[]);
int main(void)
{
	struct alumno unAlumno, *puntAlumno;
	struct alumno alumnos[3];
	int indice;
	char opcion;

	printf ("\n¿Deseas capturar los datos: \n");
	scanf (" %c", &opcion);
	if (opcion=='s')
	{
		registrarAlumno(alumnos);
	}
	else
	{
		leerDatosArchivo(alumnos, "alumnos.txt");
	}
	mostrarAlumno(alumnos);
        ordenarXpromedio(alumnos);
	printf ("\nAlumnos ordenadas por promedio: \n");
	mostrarAlumno(alumnos);
	printf ("\nAlumnos ordenadas por nombre: \n");
	ordenarXnombre(alumnos);
	mostrarAlumno(alumnos);
	buscarAlumno(alumnos);
	printf ("\nDame el índice del alumno a modificar: ");
	scanf (" %i", &indice);
	modicarPromedio(&alumnos[indice]);
	mostrarAlumno(alumnos);
	system ("clear");
	printf ("\nLos datos se guardaron en el archivo alumno.txt\n");
	guardarDatosArchivo(alumnos, "alumnos.txt");
	printf ("\n");
	return 0;
}

void registrarAlumno(struct alumno arr[]) {
	int i;
	for (i=0; i<3; i++)
	{
		printf ("\nAlumno en el índice %i ", i);
		printf ("\nDame el nombre: ");
		scanf (" %[^\n]", arr[i].nombre);
		printf ("\nPromedio: ");
		scanf (" %f", &arr[i].promedio);
		printf ("\nCuenta: ");
                scanf (" %i", &arr[i].numCuenta);
		printf ("\ndia mes año, separado en espacios: ");
		scanf (" %i %i %i", &arr[i].nacimiento.dia, &arr[i].nacimiento.mes, &arr[i].nacimiento.anio);
		printf ("\n");
	}
	return;
}

void mostrarAlumno(struct alumno arr[])
{
	int i;
	for (i=0; i<3; i++)
	{
		printf ("\nAlumno %i. - %s| %f | %i | %i/%i/%i  \n", i, arr[i].nombre, arr[i].promedio, arr[i].numCuenta, arr[i].nacimiento.dia, arr[i].nacimiento.mes, arr[i].nacimiento.anio);
	}
	return;
}

void ordenarXpromedio(struct alumno arr[])
{
	int i, j;
	struct alumno temp;
	for (i=0; i<3; i++)
	{
		for (j=i+1; j<3; j++)
		{
			if(arr[i].promedio < arr[j].promedio)
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	return;
}

void ordenarXnombre(struct alumno arr[])
{
        int i, j;
        struct alumno temp;
        for (i=0; i<3; i++)
        {
                for (j=i+1; j<3; j++)
                {
                        if(strcmp(arr[i].nombre, arr[j].nombre)>0)
                        {
                                temp=arr[i];
                                arr[i]=arr[j];
                                arr[j]=temp;
                        }
                }
        }
        return;
}

void buscarAlumno(struct alumno arr[])
{
	int i, cuenta, encontrado=0;
	printf ("\nDame el número de cuenta del alumno que buscas: ");
	scanf (" %i", &cuenta);
	for (i=0; i<3; i++)
	{
		if (cuenta==arr[i].numCuenta)
		{
			printf ("\nSe encontró al alumno: %s con promedio: %f y nacio en el mes: %i \n", arr[i].nombre, arr[i].promedio, arr[i].nacimiento.mes);
			encontrado=1;
		}
	}
	if(encontrado==0)
	{
		printf("\nNo se encontró al alumno con esa cuenta.\n");
	}
	return;
}

void modicarPromedio(struct alumno *pAlumno)
{
	float prom;
	char nom[80];
	printf ("\nDame el nuevo nombre: ");
        scanf (" %[^\n]", nom);
	printf ("\nDame el nuevo promedio: ");
	scanf (" %f", &prom);
	pAlumno->promedio = prom;
	strcpy(pAlumno->nombre,nom);
	return;
}

void guardarDatosArchivo(struct alumno arr[], char nomArch[])
{
	int i;
	FILE *fp;
	fp=fopen(nomArch, "w");
	if (fp == NULL)
	{
		printf ("\nArchivo no disponible.\n");
		exit(1);
	}
	for (i=0; i<3; i++)
	{
		fprintf (fp,"%i\n", arr[i].numCuenta);
		fprintf (fp,"%s\n", arr[i].nombre);
		fprintf (fp,"%i/%i/%i\n", arr[i].nacimiento.dia, arr[i].nacimiento.mes, arr[i].nacimiento.anio);
		fprintf (fp,"%f\n\n", arr[i].promedio);

	}
	fclose(fp);
	return;
}

void leerDatosArchivo(struct alumno arr[], char nomArch[])
{
	FILE *fp;
	int i;
	fp=fopen(nomArch, "r");
	if (fp == NULL)
        {
                printf ("\nArchivo no disponible.\n");
                exit(1);
	}
	for (i=0; i<3; i++)
	{
		fscanf (fp, "%i\n", &arr[i].numCuenta);//Leo el dato que es entero hasta el salto de línea que es el fin del dato
		fscanf (fp, "%[^\n]", arr[i].nombre);
		fscanf (fp, "%i/%i/%i\n", &arr[i].nacimiento.dia, &arr[i].nacimiento.mes, &arr[i].nacimiento.anio);
		fscanf (fp, "%f\n\n", &arr[i].promedio);
	}
	fclose(fp);
	return;
}

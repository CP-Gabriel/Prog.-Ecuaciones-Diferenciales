/**
* @file lista.
* @brief este es un ejemplo de manejo de structs.
*	 1) Haga la programación para que se cree un arreglo de alumnos
*	    del tamañp que ingrese un usuario.
*	 2) Coloque un apuntador del tipoAlumno en el índice 5 del arreglo.
*	    Capture los datos del alumno con la nomb
*	 3) Haga dos funciones: capturarDatos e imprimirDatos
*	    Estas funciones deben de permitir la captura de los datos
*	    de un usuario y debe permitir imprimir lo capturado.
*	 3) GUarde los datos capturados
*	 4) Modifique el programa para si el valor entero de la línea de comando es negativo, lea los datos del archivo.
*	 5) Modifique el programa para que se guarden los datos de alumnos
*	    en el arreglo en un archivo lista.bin en formato binario.
*	 6) Haga una función que revise el archivo binario, y encuentre al
*	    alumno con el mejor promedio. Imprima en pantalla el nombre completo y el promedio del mejor. Guarde los datos completos del
*	    alumno.
*	 7) SIhay alumnos empatados con el mejor promedio, quedan todos 
*/
#include "tipos.h"

void capturarDatos(tipoAlumno arreglo[], int tam);
void imprimirDatos(tipoAlumno arreglo[], int tam);
void guardarArchivo(tipoAlumno arreglo[], int tam);
void cargarArchivoAarreglo(tipoAlumno arreglo[], int tam);
void guardarArchivoBin(tipoAlumno arreglo[], int tam);
void encontrarMejorAlumno (char nomArch[]);

int main(int argc, char *argv[])
{
	tipoAlumno *lista, *apAlumno;
	int tam;

	if ((argc == 2) && (sscanf(argv[1], " %i", &tam) == 1))
	{
		if (tam>0)
		{
			lista = (tipoAlumno *)malloc(tam * sizeof(tipoAlumno));
			if(lista == NULL)
			{
				printf ("\nNo hay memoria disponible.\n");
				exit(1);
			}
			capturarDatos(lista, tam);
		}
		else
		{
			tam = -tam; //Si fuera pseudocódigo tam <- -tam
			cargarArchivoAarreglo(lista, tam);
		}
		guardarArchivo(lista, tam);
		guardarArchivoBin(lista, tam);
		imprimirDatos(lista, tam);
		encontrarMejorAlumno("lista.bin");
	}
	return 0;
}

void guardarArchivo(tipoAlumno arreglo[], int tam)
{
	FILE *fp;
	int i;

	fp = fopen("lista.txt", "w");
	if (fp == NULL)
	{
		printf("\nArchivo no disponible");
		exit(1);
	}
	for (i=0; i<tam; i++)
	{
		fprintf (fp, "%s\t", arreglo[i].nombre);
		fprintf (fp, "%i\n", arreglo[i].num_cuenta);
		fprintf (fp, "%f\n", arreglo[i].promedio);
		fprintf (fp, "%i\t%i\t%i\n", arreglo[i].nacimiento.dia, arreglo[i].nacimiento.mes, arreglo[i].nacimiento.anio);
	}
	fclose(fp);
	return;
}

void cargarArchivoAarreglo(tipoAlumno arreglo[], int tam)
{
	FILE *fp;
	int i;

	fp = fopen("lista.txt", "r");
	if (fp == NULL)
	{
		printf ("\nArchivo no disponible.\n");
		exit(1);
	}
	for (i=0; i<tam; i++)
	{
		fscanf (fp, "%[^\t]", arreglo[i].nombre );
		fscanf (fp, "%i\t", &arreglo[i].num_cuenta);
		fscanf (fp, "%f\t", &arreglo[i].promedio);
		fscanf (fp, "%i\t%i\t%i\n", &arreglo[i].nacimiento.dia, &arreglo[i].nacimiento.mes, &arreglo[i].nacimiento.anio);
	}
	fclose(fp);
	return;
}


/**
* @brief Esta función recibe un arreglo de alumnos
*	 y el número de alumnos en el arrglo. Al final los datos
*	 de todos los alumnos los guarda en lista.bin
* @author clase de Guillermo Gómez
* @date 18/feb/2022
* @param arreglo[] es un arreglo de tipoAlumno
* @param tam que es el número entero de alumno
* @return void
*/

void guardarArchivoBin(tipoAlumno arreglo[], int tam)
{
	FILE *fp;
	int i;

	fp = fopen("lista.bin", "w+b");
	if (fp == NULL)
        {
                printf ("\nArchivo no no disponible.");
                exit(1);
        }
	for (i=0; i<tam; i++)
	{
		fwrite(&arreglo[i], sizeof(tipoAlumno), 1, fp);
	}
	return;
}

/**
* @brief Esta función recibe el nombre de un archivo (string) binario
*	 y encuentra los mejores promedio y los guarda en el archivo
*	 de tecot mejores.txt
* @author clase de Guillermo Gómez
* @date 18/feb/2022
* @param nomArch[] es un string del nombre del archivo
* @return void
*/
void encontrarMejorAlumno (char nomArch[])
{
	FILE *fp, *fp1;
	tipoAlumno mejor, gancho;
	gancho.promedio = 0.0;

	fp1 = fopen(nomArch, "w");
        if (fp1 == NULL)
        {
                printf ("\nArchivo no no disponible.");
                exit(1);
        }
	fp = fopen(nomArch, "r+b");
	if (fp == NULL)
	{
		printf ("\nArchivo no no disponible.");
		exit(1);
	}
	while (fread(&mejor, sizeof(tipoAlumno), 1, fp) == 1)
	{
		if (mejor.promedio >= gancho.promedio)
		{
			gancho = mejor;//Se queda con el ultimo mejor promedio.
		}
	}
	printf ("\nEl mejor es %s con el promediazo %f\n", gancho.nombre, gancho.promedio);
	fclose(fp);

	fp = fopen(nomArch, "r+b");//Esta parte me permite identificar todos los mayores iguales
	if(fp == NULL)
	{
		printf ("\nArchivo no disponible.\n");
		exit(1);
	}
	while (fread(&mejor, sizeof(tipoAlumno), 1, fp) == 1)
	{
		if (gancho.promedio == mejor.promedio)
		{
			fprintf (fp1, "Nombre: %s promedio: %f\n", mejor.nombre, mejor.promedio);//Se queda con el últimomejor promedio
		}
	}
	fclose(fp);
	fclose(fp1);
	return;
}

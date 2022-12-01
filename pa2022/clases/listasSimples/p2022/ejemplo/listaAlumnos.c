/**
 * @file listaALumnos.c
 * @brief Este programa permite leer los datos de alumnos de un
 *	  archivo de texto desde la linea de comandos.
 *	  Los datos de los alumnos nos darán la sinformación de entrada
 *	  para crear una lista simple que será una Cola FIFO.
 *	  Una vez creada la lista, haremos reportes de los datos contenidos
 */
#include "decTipos.h"

tipoAlumno *insertarFIFO(char nom[], int cta, float prom, tipoAlumno *pt);
void recorrerListaAlumnos(tipoAlumno *pt);
void promedioAlumnos(tipoAlumno *pt);
void mayorPromedio(tipoAlumno *pt);

int main(int argc, char *argv[])
{
 	tipoAlumno *inicio;
	FILE *fp;
  	char nom[80];
  	int cta;
  	float prom;
  	inicio = NULL;

 	fp = fopen(argv[1],"r");
  	if (fp == NULL)
  	{
	    	printf ("\nArchivo no disponible.\n");
    		exit(1);
  	}
  	while (fscanf (fp, "%[^\t]", nom) == 1)
  	{
    		fscanf (fp, "%i\t", &cta);
		fscanf (fp, "%f\n", &prom);
		printf ("\ndwdwde\n");
    		inicio = insertarFIFO(nom, cta, prom, inicio);
  	}
  	fclose(fp);

	recorrerListaAlumnos(inicio);
  	promedioAlumnos(inicio);
  	mayorPromedio(inicio);
  	printf ("\n\n");
	return 0;
}

/**
*
*/

tipoAlumno *insertarFIFO(char nom[], int cta, float prom, tipoAlumno *pt)
{
  	tipoAlumno *new, *fin;
  	fin = pt;
  	new = (tipoAlumno *)malloc(sizeof(tipoAlumno));
  	if (new == NULL)
  	{
    		printf ("\nMemoria no disponible.\n");
    		exit(1);
  	}
  	strcpy(new->nombre, nom);
  	new->cuenta = cta;
  	new->promedio = prom;
  	if (pt == NULL)
  	{
    		pt = new;
    		new->next = NULL;
  	}
  	else
  	{
    		while (fin->next != NULL)
    		{
      			fin = fin->next;
    		}
      		fin->next = new;
      		new->next = NULL;
  	}
  	return pt;
}

void recorrerListaAlumnos(tipoAlumno *pt)
{
  	if (pt == NULL)
  	{
    		printf ("No disponible");
  	}
  	else
  	{
    		while (pt != NULL)
    		{
      			printf ("\nNombre: %s\tCuenta: %i\t Promedio: %f\n", pt->nombre, pt->cuenta, pt->promedio);
      			pt = pt->next;
    		}
  	}
  return;
}

void promedioAlumnos(tipoAlumno *pt)
{
  	float promedio;
  	float tot;
  	int i=1;
  	if (pt == NULL)
  	{
    		printf ("No disponible");
  	}
  	else
  	{
    		while (pt != NULL)
    		{
      			i++;
      			tot = tot + pt->promedio;
      			pt = pt->next;
    		}
    		promedio = tot/(i-1);
    		printf ("\nEl promedio es: %f", promedio);
  	}
  	return;
}

void mayorPromedio(tipoAlumno *pt)
{
  	float may;
  	if (pt == NULL)
  	{
    		printf ("No disponible");
  	}
  	else
  	{
    		while (pt != NULL)
    		{
      			may = pt->promedio;
      			if (may < pt->promedio)
      			{
				may = pt->promedio;
      			}
      			pt = pt->next;
    		}
    		printf ("\nEl mejor promedio es: %f", may);
  	}
  	return;
}

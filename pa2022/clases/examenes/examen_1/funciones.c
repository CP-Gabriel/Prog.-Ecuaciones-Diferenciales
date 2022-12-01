#include "tipos.h"

//tipoCiudadano

extern tipoCiudadano *insertarFIFO(char nom[], int postal, int age, char mes[], tipoCiudadano *pt)
{
	tipoCiudadano *new, *fin;
	fin = pt;
	new = (tipoCiudadano *)malloc(sizeof(tipoCiudadano));
	if (new == NULL)
	{
		printf ("\nMemoria no disponible.\n");
		exit(1);
	}

	strcpy(new->nombre, nom);
	new->cp = postal;
	new->edad = age;
	strcpy(new->aplicacion, mes);
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

/*
*
*/

extern tipoCiudadano *pushLIFO(char nom[], int postal, int age, char mes[], tipoCiudadano *pt)
{
        tipoCiudadano *new;
	new = (tipoCiudadano *)malloc(sizeof(tipoCiudadano));
        if (new == NULL)
        {
                printf ("\nMemorira no disponible.\n");
                exit(1);
        }
	strcpy(new->nombre, nom);
        new->cp = postal;
        new->edad = age;
        strcpy(new->aplicacion, mes);
        if (pt == NULL)
        {
                pt = new;
                new->next = NULL;
        }
        else
        {
                new->next = pt;
                pt = new;
        }
        return pt;
}

/*
*
*/

void recorrerLista(tipoCiudadano *pt)
{
	if (pt == NULL)
	{
		printf ("No disponible");
	}
	else
	{
		while (pt != NULL)
		{
			printf ("\nNombre: %s\tCP: %i\tEdad: %i\tFecha de aplicación: %s\n", pt->nombre, pt->cp, pt->edad, pt->aplicacion);
			pt = pt->next;
		}
	}
	return;
}

void actualizarAplicacion(tipoCiudadano *pt, char nomArch[])
{
        if (pt == NULL)
        {
                printf ("No disponible");
        }
        else
        {
                while (pt != NULL)
                {
			if ((pt->edad >= 10) && (pt->edad <= 29))
			{
				strcpy(pt->aplicacion, "septiembre");
			}
			if ((pt->edad >= 30) && (pt->edad <= 49))
                        {
				strcpy(pt->aplicacion, "octubre");
                        }
			if ((pt->edad >= 50) && (pt->edad <= 79))
			{
                        	strcpy(pt->aplicacion, "noviembre");
                        }
			if (pt->edad>79)
                        {
                      		strcpy(pt->aplicacion, "diciembre");
                        }

			FILE *fp;
		        fp = fopen (nomArch, "a");
		        if (fp == NULL)
		        {
	        	        printf ("\nArchivo no disponible.\n");
		        }
		        fprintf (fp, "%s", pt->aplicacion);
		        fclose(fp);

			pt = pt->next;
                }
        }
        return;
}


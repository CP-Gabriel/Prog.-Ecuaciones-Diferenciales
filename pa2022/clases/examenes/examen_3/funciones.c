/**
* @
*/

#include "tipos.h"

/**
* @
*/

extern nodoAlumno *insertarNodoArbol(nodoAlumno *pt, tipoAlumno datos)
{
        nodoAlumno *nuevo, *aux;

        aux = pt;

        int salir = 1;
        nuevo = (nodoAlumno *)malloc(sizeof(nodoAlumno));

        if (nuevo == NULL)
        {
                printf ("\nNo hay memoria disponible.");
                exit(1);
        }

        nuevo->datos = datos;
        nuevo->izq = NULL;
        nuevo->der = NULL;

	if (aux == NULL)
        {
                pt = nuevo;
        }

        while ((aux != NULL) && (salir != 0))
        {
                if (datos.numCuenta == aux->datos.numCuenta)
                {
                        printf ("\nLa cuenta %i ya se encuentra registrada en el arbol.\n", datos.numCuenta);
                        free(nuevo);
                        salir = 0;
                }

                if (datos.numCuenta > aux->datos.numCuenta)//mover a la derecha
                {
                        if (aux->der != NULL)
                        {
                                aux = aux->der;
                        }
                        else
                        {
                                aux->der = nuevo;
                                salir = 0;
                        }
                }

                if (datos.numCuenta < aux->datos.numCuenta)//mover a la derecha
                {
                        if (aux->izq != NULL)
                        {
                                aux = aux->izq;
                        }
                        else
                        {
                                aux->izq = nuevo;
                                salir = 0;
                        }
                }
        }
/////////////
/*        while ((aux != NULL) && (salir != 0))
        {
                if (datos.numCuenta == aux->datos.numCuenta)
                {
                        printf ("\nLa cuenta %i ya se encuentra registrada en el arbol.\n", datos.numCuenta);
                        free(nuevo);
                        salir = 0;
                }

		if (strcmp(datos.carrera, aux->datos.carrera) == 0)
		{
			if(datos.promedio < aux->datos.promedio)
			{
	                        if (aux->izq != NULL)
	                        {
	                                aux = aux->izq;
	                        }
	                        else
	                        {
	                                aux->izq = nuevo;
	                                salir = 0;
	                        }
			}
		}

                if (datos.numCuenta > aux->datos.numCuenta)//mover a la derecha
                {
                        if (aux->der != NULL)
                        {
                                aux = aux->der;
                        }
                        else
                        {
                                aux->der = nuevo;
                                salir = 0;
                        }
                }

                if (datos.numCuenta < aux->datos.numCuenta)//mover a la derecha
                {
                        if (aux->izq != NULL)
                        {
                                aux = aux->izq;
                        }
                        else
                        {
                                aux->izq = nuevo;
                                salir = 0;
                        }
                }
        }
*/
        return pt;
}

/**
* @
*/

extern void recorrerListaAscendente(nodoAlumno *aux)
{
        if(aux != NULL)
        {
                recorrerListaAscendente(aux->izq);
                printf ("Cuenta: %i\tNombre: %s\tPromedio: %.1f\tCarrera: %s\n", aux->datos.numCuenta, aux->datos.nombre, aux->datos.promedio, aux->datos.carrera);
/*		ref1 = aux;
		if (strcmp(ref1->datos.carrera, aux->datos.carrera) == 0)
		{
			if (ref1->datos.promedio > aux->datos.promedio)
			{
				generarInforme
			}
			else
			{
				generarInforme
			}
		}*/
                recorrerListaAscendente(aux->der);
        }
        return;
}

/**
* @
*/

extern void recorrerListaDescendente(nodoAlumno *aux)
{
        if(aux != NULL)
        {
                recorrerListaDescendente(aux->der);
                printf ("Cuenta: %i\tNombre: %s\tPromedio: %.1f\tCarrera: %s\n", aux->datos.numCuenta, aux->datos.nombre, aux->datos.promedio, aux->datos.carrera);
                recorrerListaDescendente(aux->izq);
        }
        return;
}

//////////

/*extern int buscarDirecto(nodo *aux, int num)
{
        int encontrado = 0, niveles = -1;
	int prom

        while ((aux != NULL)&&(encontrado == 0))
        {
                if (aux->num == num)
                {
                        encontrado = 1;
                        printf ("\nEl dato %i fue encontrado en el árbol.\n", num);
                }
                else
                {
                        if (num < aux->num)
                        {
                                aux = aux->izq;
                        }
                        else
                        {
                                aux = aux->der;
                        }
                        niveles++;
                }
        }
        printf ("\nSe avanzaron: %i niveles.\n", niveles);
        return encontrado;
}
*/

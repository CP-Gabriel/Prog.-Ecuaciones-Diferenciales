/**
* @file mejoresAlumnos.c
* @brief
* @author clase de Guillermo Gomez.
* @date 10/05/22
*/

#include "tipos.h"

nodoAlumno *insertarNodoArbol(nodoAlumno *pt, tipoAlumno datos);
void recorrerListaAscendente(nodoAlumno *aux);
void recorrerListaDescendente(nodoAlumno *aux);

int main(int argc, char *argv[])
{
        nodoAlumno *inicio;
        tipoAlumno registro;

        inicio = NULL;

        FILE *fp;
        fp = fopen(argv[1], "r");
        if (fp == NULL)
        {
                printf ("\nArchivo no disponible.");
                exit(1);
        }
        system("clear");
//      while (fscanf(fp, "%i\t %[^\t] %[^\t] %i\t%f\n", ) == 1)
        while (fscanf(fp , "%i\t", &registro.numCuenta) == 1)
        {
                fscanf (fp, " %[^\t]", registro.nombre);
                fscanf (fp, " %f\t", &registro.promedio);
                fscanf (fp, "%[^\n]", registro.carrera);
                inicio = insertarNodoArbol(inicio, registro);
        }
        fclose(fp);

        printf ("\nRecorrido mascotas ascendente: \n");
        recorrerListaAscendente(inicio);
        printf ("\nRecorrido mascotas descendente: \n");
        recorrerListaDescendente(inicio);

	printf ("\n");
	return 0;
}

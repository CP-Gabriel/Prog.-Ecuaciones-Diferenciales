/**
 * @file mascotas.c
 * @brief El siguiente programa realiza varios reportes sobre los datos de mascotas (cliente, nombre de la mascota, edad y
          peso) que genere una estructura de datos de árbol binario jerárquico.  Dichos datos estarán en el archivo de mascotas.txt
          el programa genera los siguientes reportes:
 *
 *        1) Recorre el árbol y genera un informe en pantalla con el número de mascotas que tengan más años de edad y menos
          kilogramos que ingrese el usuario.
 *
 * 2) Se genera un archivo petOrdenadas.txt de las mascotas en orden alfabético(A-Z) por el nombre de la mascota.
 * 3) La siguiente función actualiza la categoría dude las mascotas de acuerdo con su edad, por el siguiente criterio:
                Si tiene mas de 2años es infante.
                Más de 2 años a 6 años es adulto.
                Mas de 7 años es anciano.
 * 4) Localiza una mascota por su número de cliente en el árbol y permite modificar algunos de los datos de la mascota
 * @date : 11/mayo/22
 * @author: equipo 7
 */

#include "defTipos.h"

nodoMascota *insertarNodoArbol(nodoMascota *pt, tipoMascota datos);
void recorrerMascotaAscendente(nodoMascota *aux);
void generarReporte(nodoMascota *aux, int infante, int adulto, int anciano);
//void generarReporte(nodoMascota *aux);
////////////
void generaInforme (nodoMascota *aux,int m,float o,int *n);
////////////
nodoMascota *insertarNodoArbol2(nodoMascota *pt, tipoMascota datos);
void  buscarDirecto(nodoMascota *aux, int num);

int main (int argc, char *argv[])
{
        nodoMascota *inicio;
        tipoMascota datosTemp;
	int infante = 0;
	int adulto = 0;
	int anciano = 0;
	int num;

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
        while (fscanf(fp , "%i\t", &datosTemp.numCliente) == 1)
        {
                fscanf (fp, " %[^\t]", datosTemp.raza);
                fscanf (fp, " %[^\t]", datosTemp.nombre);
                fscanf (fp, "%i\t", &datosTemp.edad);
                fscanf (fp, "%f\n", &datosTemp.peso);
                inicio = insertarNodoArbol(inicio, datosTemp);
        }
        fclose(fp);

        printf ("\nRecorrido mascotas ascendente: \n");
        recorrerMascotaAscendente(inicio);
///////////////////
	int m, n;
	float o;
	  printf ("\nEdad:");
	  scanf (" %i", &m);
	  printf ("Peso: ");
	  scanf (" %f", &o);
	  printf ("\nSe encontraron %i mascotas que tienen más de %i años y menos de %fKilos:", n,m,o);
	  generaInforme (inicio,m,o,&n);
//	generarReporte(inicio, infante, adulto, anciano);
//	generarReporte(inicio);

///////////////////
	printf ("\nIngresa el numero de cliente del cual deseas buscar: ");
	scanf ("%i", &num);
	fp = fopen(argv[1], "r");
        if (fp == NULL)
        {
                printf ("\nArchivo no disponible.");
                exit(1);
        }
        while (fscanf(fp , "%i\t", &datosTemp.numCliente) == 1)
        {
                fscanf (fp, " %[^\t]", datosTemp.raza);
                fscanf (fp, " %[^\t]", datosTemp.nombre);
                fscanf (fp, "%i\t", &datosTemp.edad);
                fscanf (fp, "%f\n", &datosTemp.peso);
                inicio = insertarNodoArbol2(inicio, datosTemp);
        }
	buscarDirecto(inicio, num);

        printf ("\n");
        return 0;
}


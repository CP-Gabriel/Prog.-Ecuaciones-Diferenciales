/**
* @file funciones.c
* @brief Este archivo conitien las funciones del archivo mascotas.c
* @author equipo 7
* @date 11/05/2022
*/

#include "defTipos.h"

/**
* @brief Esta funcion crea el arbol binario.
* @date 11/05/2022
* @param pt es un apuntador.
* @param datos es un apuntador a estructura.
* @return;
*/

extern nodoMascota *insertarNodoArbol(nodoMascota *pt, tipoMascota datos)
//extern nodoMascota *insertarNodoArbol(nodoMascota *pt, tipoMascota datos, int n)
{
        nodoMascota *nuevo, *aux;
        aux = pt;

        int salir = 1;
        nuevo = (nodoMascota *)malloc(sizeof(nodoMascota));

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
                if (datos.numCliente == aux->datos.numCliente)
                {
                        printf ("\nEl número %i ya existe en el árbol.\n", datos.numCliente);
                        free(nuevo);
                        salir = 0;
                }
		if (strcmp(datos.nombre, aux->datos.nombre) >0)
                {
                        if (aux->der != NULL)
                        {
                                aux = aux->der;
                        }
                        else
                        {
                                aux->der = nuevo;
                                salir = 0;
//				n++;
                        }
                }
		if (strcmp(datos.nombre, aux->datos.nombre) <= 0)
                {
                        if (aux->izq != NULL)
                        {
                                aux = aux->izq;
                        }
                        else
                        {
                                aux->izq = nuevo;
                                salir = 0;
//				n++;
                        }
                }
        }
        return pt;
}

/**
 * @file funciones.c
 * @brief Esta función recorre el árbol e imprime en pantalla el número de
 *        mascotas que tengan más años y menos kgs;
 * @author equipo 7
 * @date 11/Mayo/2022
 * @param apuntador a raiz de tipo nodo mascota
 * @param m, es un entero que contiene la edad
 * @param o, es un float que contiene el peso
 * @param n, es un contador para el número de mascotas
 * @return void
 */

extern void generaInforme (nodoMascota *aux,int m,float o,int *n)
{

  if (aux!=NULL)
    {
      generaInforme (aux->izq,m,o,n);
      if (aux->datos.edad>m && aux->datos.peso<o)
	{
	  printf ("\nCliente: %i\nRaza: %s\nNombre: %s", aux->datos.numCliente, aux->datos.raza, aux->datos.nombre);
	  printf ("\nPeso:%f \t Edad: %i\n",aux->datos.peso, aux->datos.edad);
	  n=n+1;
	}
      generaInforme (aux->der,m,o,n);

    }
  return ;
}

/**
* @brief Esta funcion guarda en un archivo las mascotas ordenadas alfabeticamente de acuerdo al nombre.
* @date 11/05/2022
* @param aux es un apuntador.
* @return void
*/

extern void guardarDatos(nodoMascota *aux) //extern void guardarDatos(nodoMascota *aux, int n) 
{
        FILE *fp;
        fp = fopen("petOrdenados.txt", "a");
        if (fp == NULL)
        {
                printf ("Archivo no disponible.");
                exit(1);
        }
        else
        {
                fprintf (fp, "%i\t", aux->datos.numCliente);
                fprintf (fp, "%s\t", aux->datos.raza);
                fprintf (fp, "%s\t", aux->datos.nombre);
                fprintf (fp, "%i\t", aux->datos.edad);
		fprintf (fp, "%.2f\n", aux->datos.peso);
        }
        fclose(fp);
	return;
}

/**
* @brief Esta función recorre el arbol e imprime los registros.
 * @date 11/mayo/2022
 * @param aux es un apuntador
 * @return void
*/

extern void recorrerMascotaAscendente(nodoMascota *aux)
{
	if (aux != NULL)
	{
		recorrerMascotaAscendente(aux->izq);
/*                if (strcmp(aux->datos.raza, "bulldog") == 0)
                {
                        guardarDatos(aux);
                }*/
	        printf ("Cliente: %i\tRaza: %s\tNombre: %s\tEdad: %i\tPeso: %f\n", aux->datos.numCliente, aux->datos.raza, aux->datos.nombre, aux->datos.edad, aux->datos.peso);
		guardarDatos(aux);
	        recorrerMascotaAscendente(aux->der);
	}
        return;
}

/**
* @
*/

//extern void generarReporte(nodoMascota *aux)
/*extern void generarReporte(nodoMascota *aux, int infante, int adulto, int anciano)
{
	int tot;
        if(aux != NULL)
        {
//                generarReporte(aux->der, infante = infante, adulto = adulto, anciano = anciano);
		generarReporte(aux->izq, infante, adulto, anciano);
//		generarReporte(aux->izq);
                if (strcmp(aux->datos.raza, "cocker") == 0)
                {
                        if (aux->datos.peso > 10)
                        {
                                guardarDatos2(aux);
                        }
                }
//		generarReporte(aux->der, infante, adulto, anciano);
		if (aux->datos.edad < 2)
		{
			infante++;
		}
		if ((aux->datos.edad > 2)&&(aux->datos.edad <= 6))
		{
			adulto++;
		}
		if (aux->datos.edad > 7)
		{
			anciano++;
		}
		generarReporte(aux->izq, infante, adulto, anciano);
//                generarReporte(aux->izq, infante = infante, adulto = adulto, anciano = anciano);
//		generarReporte(aux->izq);
        }

	if (aux == NULL)
	{
		tot = infante + adulto + anciano;
		printf ("\nNumero total de mascotas %i", tot);
		printf ("\nNumero de mascotas infante %i", infante);
		printf ("\nNumero de mascotas adulto %i", adulto);
		printf ("\nNumero de mascotas anciano %i", anciano);
	}
        return;
}*/

/**
* @
*/

extern nodoMascota *insertarNodoArbol2(nodoMascota *pt, tipoMascota datos)
{
        nodoMascota *nuevo, *aux;
        aux = pt;

        int salir = 1;
        nuevo = (nodoMascota *)malloc(sizeof(nodoMascota));

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
                if (datos.numCliente == aux->datos.numCliente)
                {
                        printf ("\nEl número %i ya existe en el árbol.\n", datos.numCliente);
                        free(nuevo);
                        salir = 0;
                }

		if (datos.numCliente > aux->datos.numCliente)
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

		if (datos.numCliente < aux->datos.numCliente)
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
        return pt;
}

/**
* @bried Esta funcion lacaliza una mascota por su numero de cliente en el arbol y permite al usuario cambiar los datos de la mascota.
* @date 11/mayo/2022
* @param aux es un apuntador
* @return void
*/

extern void buscarDirecto(nodoMascota *aux, int num)
{
        int encontrado = 0;
	nodoMascota *ref;
        while ((aux != NULL)&&(encontrado == 0))
        {
                if (aux->datos.numCliente == num)
                {
                        encontrado = 1;
			ref = aux;
//                        printf ("\nLa raza %s fue encontrado en el árbol.\n", aux->datos.numCliente);
		        printf ("Cliente: %i\tRaza: %s\tNombre: %s\tEdad: %i\tPeso: %f\n", aux->datos.numCliente, aux->datos.raza, aux->datos.nombre, aux->datos.edad, aux->datos.peso);
                }
                else
                {
                        if (num < aux->datos.numCliente)
                        {
                                aux = aux->izq;
                        }
                        else
                        {
                                aux = aux->der;
                        }
                }
        }
	printf ("\n1. Raza");
	printf ("\n2. Nombre");
	printf ("\n3. Edad");
	printf ("\n4. Peso");
	int n;
	printf ("\nIngresa el numero del dato que deseas modificar de la mascota: ");

	scanf ("%i", &n);
	if (n == 1)
	{
		printf ("\nIngresa la nueva raza: ");
		char a[40];
		scanf ("%s", a);
		strcpy(aux->datos.raza, a);
	}
	if (n == 2)
        {
                printf ("\nIngresa el nuevo nombre: ");
                char name[40];
                scanf ("%s", name);
                strcpy(aux->datos.nombre, name);
        }
	if (n == 3)
        {
                printf ("\nIngresa la nueva edad: ");
		int date;
                scanf ("%i", &date);
                aux->datos.edad = date;
        }
	if (n == 4)
        {
                printf ("\nIngresa el nuevo peso: ");
		float f;
                scanf ("%f", &f);
                aux->datos.peso = f;
        }
        printf ("Cliente: %i\tRaza: %s\tNombre: %s\tEdad: %i\tPeso: %f\n", aux->datos.numCliente, aux->datos.raza, aux->datos.nombre, aux->datos.edad, aux->datos.peso);

	return;
}

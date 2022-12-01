/**
* @file funciones.c
* @brief Este archivo tiene las funciones para biblioteca.c
* @author 
* @date 01/07/22
*/

#include "tipos.h"

/**
* @brief Esta funcion permite hacer la subida de datos de un libro
* @date 01/07/22
* @author 
* @param book es un struct
* @return void
*/

extern void darDeAlta(struct libros book[])
{
	int registro, year, estado;
	char nombre[50];
	char title[50];
	char publicacion[50];
	char country[50];
	int salir;

	FILE *fp;
	do
	{
		fp = fopen("libros.txt", "a");
		if(fp == NULL)
		{
			printf ("Archivo no disponible.");
			exit(1);
		}
		system ("clear");
		printf ("\n\t\tBIBLIOTECA\n");
		printf ("\nDAR LIBROS DE ALTA\n");
		printf ("\nIngresa la clave del registro: ");
		scanf (" %i", &registro);
		printf ("\nIngresa el primer nombre y el primer apellido del autor del libro: ");
		scanf (" %[^\n]", nombre);
		printf ("\nIngresa el titulo del libro: ");
		scanf (" %[^\n]", title);
		printf ("\nIngresa la editorial del libro: ");
		scanf (" %[^\n]", publicacion);
		printf ("\nIngresa el pais de edicion del libro: ");
		scanf (" %[^\n]", country);
		printf ("\nIngresa el año de expedicion del libro: ");
		scanf (" %i", &year);
		printf ("\n0.NO\t1.SI");
		printf ("\nEl libro fue prestado: ");
		scanf (" %i", &estado);
		fprintf (fp, "%i\t%s\t%s\t%s\t%s\t%i\t%i\n", registro, nombre, title, publicacion, country, year, estado);
		fclose(fp);
		printf ("\n\t0.NO\t1.SI\n");
		printf ("\nDesea ingresar otro libro: ");
		scanf(" %i",&salir);
	}
	while(salir == 1);
	return;
}

/**
* @brief Esta funcion imprime la lista de inicio a fin.
* @date 01/07/22
* @author 
* @param book es un struct.
* @param i es un entero
* @return void
*/

void imprimirLista(struct libros book[], int i)
{
	int a;
	for (a=0; a<i; a++)
	{
		printf ("\nClave: %i", book[a].clave);
		printf ("\nAutor: %s", book[a].autor);
		printf ("\nTitulo: %s", book[a].titulo);
		printf ("\nEditorial: %s", book[a].editorial);
		printf ("\nPais de expedicion: %s", book[a].pais);
		printf ("\nAño de impresion: %i", book[a].anio);
		if (book[a].prestamo)
		{
			printf ("\nEl libro fue prestado.\n");
		}
		else
		{
			printf ("\nEl libro no ha sido prestado.\n");
		}
	}
	return;
}

/**
* @brief Esta funcion permite ver la lista de los libros, permite ordenarla alfabeticamente de acuerdo al autor, titulo
*	 y ordenarla por su año de edicion.
* @date 01/07/22
* @author
* @param book es un struct
* @param i es un entero
* @return i es un entero
*/

extern int  mostrarInformes(struct libros book[], int i)
{
	int opcion, a, b;
	struct libros temp;

	do
	{
		system ("clear");
		printf ("\n\t\tBIBLIOTECA\n");
		printf ("\nVISUALIZAR INFORMES\n");
		printf ("\n1.Ordenar lista de libros ascendentemente de acuerdo al autor.");
		printf ("\n2.Ordenar lista de libros ascendentemente de acuerdo al titulo.");
		printf ("\n3.Ordenar lista de libros ascendentemente de acuerdo al año de edición.\n");
		printf ("\nIngresa el número de la opcion que quieres hacer: ");
		scanf (" %i", &opcion);

		if (opcion == 1)//OPCION 1
		{
			for (a=0; a<i; a++)
			{
				for (b=(a+1); b<i; b++)
				{
					if(strcmp(book[a].autor, book[b].autor) >0)
					{
						temp = book[a];
						book[a] = book[b];
						book[b] = temp;
					}
				}
			}

			printf ("\nLista ordenada de acuerdo al autor:\n");
			imprimirLista(book, i);
		}

		if (opcion == 2)//OPCION 2
                {
                        for (a=0; a<i; a++)
                        {
                                for (b=(a+1); b<i; b++)
                                {
					if(strcmp(book[a].titulo, book[b].titulo) >0)
                                        {
                                                temp = book[a];
                                                book[a] = book[b];
                                                book[b] = temp;
                                        }
                                }
                        }

                        printf ("\nLista ordenada de acuerdo al titulo:\n");
                        imprimirLista(book, i);
                }

		if (opcion == 3)//OPCION 3
                {
                        for (a=0; a<i; a++)
                        {
                                for (b=(a+1); b<i; b++)
                                {
					if (book[a].anio > book[b].anio)
                                        {
                                                temp = book[a];
                                                book[a] = book[b];
                                                book[b] = temp;
                                        }
                                }
                        }

                        printf ("\nLista ordenada de acuerdo al año de publicacion:\n");
                        imprimirLista(book, i);
                }

		printf ("\n0.NO\t1.SI");
		printf ("\nDeseas ver otra lista: ");
		scanf (" %i", &opcion);
	}
	while (opcion == 1);

	return i;
}

/**
* @brief Esta funcion permite modificar los datos de los registros.
* @date 01/07/22
* @author
* @param book es un struct
* @param i es un entero
* @return i es un entero
*/

extern int modificarRegistros(struct libros book[], int i)
{
	int option, opcion, salir, clave;
	int a, b;
	char nombre[20];
	int estado, registro, edicion;
	char title[50];
	char publishing[50];
	char country[50];

	struct libros temp;

	do
	{
		system ("clear");
		printf ("\n\t\tBIBLIOTECA\n");
		printf ("\nFuncionalidades:\n");
		printf ("\n1.Modificar un registro.");
		printf ("\n2.Eliminar un registro.\n");
		printf ("\nIngresa el número de la opcion que deseas realizar: ");
		scanf (" %i", &option);

		if (option == 1)
		{
			imprimirLista(book, i);
			printf ("\nIngresa la clave del registro que deseas modificar: ");
			scanf (" %i", &clave);
			do
			{
				printf ("\n1.Clave de registro.");
				printf ("\n2.Autor.");
				printf ("\n3.Titulo.");
				printf ("\n4.Editorial.");
				printf ("\n5.País de edicion.");
				printf ("\n6.Año de edicion.");
				printf ("\n7.Estado del libro.\n");
				printf ("\nIngresa el número la opcion que deseas modificar del registro %i: ", clave);
				scanf (" %i", &opcion);
				for (a=0; a<i; a++)
				{
					if (book[a].clave == clave)
					{
						if (opcion == 1)
						{
							printf ("\nIngresa la nueva clave de registro: ");
							scanf (" %i", &registro);
							book[a].clave = registro;
						}

						if (opcion == 2)
						{
							printf ("\nIngresa el nuevo nombre del autor del libro: ");
							scanf (" %[^\n]", nombre);
							strcpy(book[a].autor, nombre);
						}

						if (opcion == 3)
						{
							printf ("\nIngresa el nuevo titulo del libro: ");
							scanf (" %[^\n]", title);
							strcpy(book[a].titulo, title);
						}


						if (opcion == 4)
                                                {
							printf ("\nIngresa la nueva editorial del libro: ");
                                                        scanf (" %[^\n]", publishing);
                                                        strcpy(book[a].editorial, publishing);
                                                }

						if (opcion == 5)
                                                {
                                                        printf ("\nIngresa el nuevo pais de edicion del libro: ");
                                                        scanf (" %[^\n]", country);
                                                        strcpy(book[a].pais, country);
                                                }

						if (opcion == 6)
						{
							printf ("\nIngresa el nuevo año de edicion del libro: ");
	                                                scanf (" %i", &edicion);
							book[a].anio = edicion;
						}

						if (opcion == 7)
                                                {
                                                        printf ("\nIngresa el nuevo estado de prestamo del libro: ");
                                                        scanf (" %i", &estado);
                                                        book[a].prestamo = estado;
                                                }

						printf ("\nRegistro modificado:");
						printf ("\nClave: %i", book[a].clave);
				                printf ("\nAutor: %s", book[a].autor);
				                printf ("\nTitulo: %s", book[a].titulo);
				                printf ("\nEditorial: %s", book[a].editorial);
				                printf ("\nPais de expedicion: %s", book[a].pais);
				                printf ("\nAño de impresion: %i", book[a].anio);
				                if (book[a].prestamo)
				                {
			        	                printf ("\nEl libro fue prestado.\n");
				                }
				                else
				                {
				                        printf ("\nEl libro no ha sido prestado.\n");
				                }

					}
				}
				printf ("\n0.NO\t1.SI");
				printf ("\nDeseas realizarle otro cambio al registro %i: ", clave);
				scanf (" %i", &salir);
			}
			while (salir == 1);
		}
		if (option == 2)
		{
			imprimirLista(book, i);
			printf ("\nIngresa la clave del registro del libro el cual desea borrar: ");
                        scanf (" %i", &clave);
			for (a=0; a<i; a++)
			{
				if (book[a].clave == clave)
				{
					temp = book[a];
					book[a] = book[a+1];
					for (b=(a+1); b<i; b++)
					{
						book[b] = book[b+1];
					}
					i = i-1;
				}
			}
			printf ("\nLista modificada: ");
			imprimirLista(book, i);
		}
		printf ("\n\t0.NO\t1.SI\n");
                printf ("\nDesea modificar otro registro: ");
                scanf(" %i",&opcion);
	}
	while (opcion == 1);
	return i;
}

/**
* @brief Esta funcion permite buscar libros de acuerdo al tipo de autor y titulo
* @date 01/07/22
* @author
* @param book es un struct
* @param i es un entero
* @return void
*/

extern void buscarRegistro(struct libros book[], int i)
{
	int opcion, continuacion;
	int a = 0;
	char busqueda[50];

	do
	{
		system ("clear");
		printf ("\n\t\tBIBLIOTECA\n");
		printf ("\nFuncionalidades:\n");
		printf ("\n1.Buscar libros de acuerdo al autor.");
		printf ("\n2.Buscar libros de acuerdo al titulo.");
		printf ("\nIngresa el número de la opcion que deseas realizar: ");
		scanf (" %i", &opcion);
		if (opcion == 1)
		{
			printf ("\nIngresa el nombre del autor de acuerdo al cual quieres buscar libros relacionados: ");
			scanf (" %[^\n]", busqueda);
			do
			{
				if (strcmp(book[a].autor, busqueda) == 0)
				{
					printf ("\nRegistro encontrado:");
					printf ("\nClave: %i", book[a].clave);
					printf ("\nAutor: %s", book[a].autor);
					printf ("\nTitulo: %s", book[a].titulo);
					printf ("\nEditorial: %s", book[a].editorial);
					printf ("\nPais de expedicion: %s", book[a].pais);
					printf ("\nAño de impresion: %i", book[a].anio);
					if (book[a].prestamo)
					{
						printf ("\nEl libro fue prestado.\n");
					}
					else
					{
						printf ("\nEl libro no ha sido prestado.\n");
					}
					printf ("\n\t0.NO\t1.SI\n");
					printf ("\nQuiere pasar a la siguiente coincidencia: ");
					scanf (" %i", &continuacion);
				}
				a++;
			}
			while((a != i));
			printf("\nNo hay otra coincidencia.");
		}

		if (opcion == 2)
		{
			printf ("\nIngresa el titulo del libro de acuerdo al cual quieres buscar libros relacionados: ");
	                scanf (" %[^\n]", busqueda);
	                do
	                {
	                        if (strcmp(book[a].titulo, busqueda) == 0)
	                        {
	                                printf ("\nRegistro encontrado:");
	                                printf ("\nClave: %i", book[a].clave);
	                                printf ("\nAutor: %s", book[a].autor);
					printf ("\nTitulo: %s", book[a].titulo);
        	                        printf ("\nEditorial: %s", book[a].editorial);
	                                printf ("\nPais de expedicion: %s", book[a].pais);
	                                printf ("\nAño de impresion: %i", book[a].anio);
	                                if (book[a].prestamo)
	                                {
	                                        printf ("\nEl libro fue prestado.\n");
	                                }
					else
	                                {
	                                        printf ("\nEl libro no ha sido prestado.\n");
	                                }
	                                printf ("\n\t0.NO\t1.SI\n");
	                                printf ("\nQuiere pasar a la siguiente coincidencia: ");
	                                scanf (" %i", &continuacion);
	                        }
	                        a++;
	                }
                        while((a != i));
	                printf("\nNo hay otra coincidencia.\n");
		}
		printf ("\n\t0.NO\t1.SI\n");
		printf ("\nQuiere realizar otra busqueda: ");
		scanf (" %i", &continuacion);
	}
	while (continuacion == 1);
	return;
}

/**
* @brief Esta funcion permite buscar libros de acuerdo a su pais y año en comun.
* @date 01/07/22
* @author 
* @param book es un struct
* @param i es un entro
* @return void
*/

void buscarPorPaisAnio(struct libros book[], int i)
{
        int opcion, continuacion, anio;
        int a = 0;
        char busqueda[50];
	char pais[50];

        do
        {
                system ("clear");
		printf ("\n\t\tBIBLIOTECA\n");
		printf ("\nBuscar libros de acuerdo a país y año:\n");
		printf ("\nIngrese el pais : ");
		scanf (" %[^\n]", pais);
		printf ("\nIngrese el año de expedicion: ");
		scanf (" %i", &anio);
		do
		{
			if (strcmp(book[a].pais, pais) == 0)
			{
				if(book[a].anio == anio)
				{
                                        printf ("\nRegistro encontrado:");
                                        printf ("\nClave: %i", book[a].clave);
                                        printf ("\nAutor: %s", book[a].autor);
                                        printf ("\nTitulo: %s", book[a].titulo);
                                        printf ("\nEditorial: %s", book[a].editorial);
                                        printf ("\nPais de expedicion: %s", book[a].pais);
                                        printf ("\nAño de impresion: %i", book[a].anio);
                                        if (book[a].prestamo)
                                        {
                                                printf ("\nEl libro fue prestado.\n");
					}
					else
                                        {
						printf ("\nEl libro no ha sido prestado.\n");
					}
	                                        printf ("\n\t0.NO\t1.SI\n");
	                                        printf ("\nQuiere pasar a la siguiente coincidencia: ");
	                                        scanf (" %i", &continuacion);
				}
			}
			a++;
		}
		while((a != i));

		printf("\nNo hay otra coincidencia.");
		printf ("\n\t0.NO\t1.SI\n");
		printf ("\nQuiere realizar otra busqueda: ");
		scanf (" %i", &continuacion);
        }
        while (continuacion == 1);
        return;
}

/**
* @brief Esta funcion permite guardar los datos en el arreglo book con los cambios realizados
* @date 01/07/22
* @author
* @param book es un struct
* @param i es un entero
* @return void
*/

extern void salirYguardar(struct libros book[], int i)
{
	int a;

	FILE *fp;
	fp = fopen("libros.txt", "w");
	if(fp == NULL)
	{
		printf ("Archivo no disponible.");
		exit(1);
	}
	system ("clear");
	for (a=0; a<i; a++)
	{
		fprintf (fp, "%i\t%s\t%s\t%s\t%s\t%i\t%i\n", book[a].clave, book[a].autor, book[a].titulo, book[a].editorial, book[a].pais, book[a].anio, book[a].prestamo);
	}
	fclose(fp);
	printf ("\n\nSe actualizaron los datos.\n\n");
	return;
}

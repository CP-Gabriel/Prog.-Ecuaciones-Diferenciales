#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern void ejercutarSQL(char query[]);

void verLibros()
{
	int i;
	char query[1024] = "";

	system ("clear");
        printf ("\n\t\tBibiblioteca ibero\n\n");
        printf ("\nLista de Libros\n\n");
	sprintf(query, "SELECT * FROM pro_Books");
	ejercutarSQL(query);
	scanf ("%i", &i);

	printf ("\n");
	return;
}

void solicitarPrestamos(int cuenta)
{
	char query[1024] = "";
	int libros, i;
	long double idLibro;

	system ("clear");
        printf ("\n\t\tBibiblioteca ibero\n\n");
 	printf ("\nSolicitar Prestamo\n\n");
	printf ("\nCuantos libros deseas solicitar: ");
	scanf ("%i", &libros);

	sprintf(query, "CALL pro_CrearSolicitud(RIGHT(RAND(), 10), %i)", cuenta);
//	printf ("\n%s", query);
//	ejercutarSQL(query);

	for (i=0; i<=libros; i++)
	{
		printf ("\n%i.Ingresa el id del libro a solicitar: ", i+1);
		scanf (" %Lf", &idLibro);
		sprintf(query, "CALL pro_SolicitarLibros(67977230, %.0Lf)", idLibro);
	        ejercutarSQL(query);
	}
	return;
}

void regresarLibros()
{
	char query[1024] = "";
	long double idLibro;

	system ("clear");
        printf ("\n\t\tBibiblioteca ibero\n\n");
	printf ("\nRegresar Libros\n\n");
	printf ("\nIngresa el id del libro que quieres regresar: ");
	scanf ("%Lf", &idLibro);

/*	printf ("\nIngresa el id del libro que quieres regresar: ");
        scanf (" %i", &idLibro);*/

	sprintf(query, "CALL pro_devolverLibros(67977230, %.0Lf)", idLibro);
	ejercutarSQL(query);
        scanf ("%Lf", &idLibro);

	return;
}

void menuSolicitante(int cuenta)
{
        int temp = 0;
        int opcion;

        do
        {
                system ("clear");
                printf ("\n\t\tBibiblioteca ibero\n\n");
                printf ("\nCesion Solicitante\n\n");
                printf ("\nMenu:");
                printf ("\n1. Visualizar libros");
                printf ("\n2. Pedir prestamos");
                printf ("\n3. Regresar libros.");
		printf ("\n4. Cerrar Cesion.\n");
                printf ("\nIngresa el numero de la opcion que deseas realizar: ");
                scanf ("%i", &opcion);

                if (opcion == 1)
                {
                        verLibros();
                        temp = 1;
                }
                else if (opcion == 2)
                {
                        solicitarPrestamos(cuenta);
                        temp = 1;
                }
		else if (opcion == 3)
                {
                        regresarLibros();
                        temp = 1;
                }
        }
        while (temp == 1);

        printf ("\n");
        return;
}

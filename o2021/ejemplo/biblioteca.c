/**
* @file biblioteca.c
* @brief 
* @author 
* @date 01/07/22
*/

#include "tipos.h"

void darDeAlta(struct libros book[]);
int mostrarInformes(struct libros book[], int i);
int modificarRegistros(struct libros book[], int i);
void buscarRegistro(struct libros book[], int i);
void buscarPorPaisAnio(struct libros book[], int i);
void salirYguardar(struct libros book[], int i);

int main(void)
{
	struct libros book[100];
	int opcion;
	int salir=1;
	int fin=0;
	int i = 0;

        FILE *fp;
        fp = fopen("libros.txt", "r");
        if (fp == NULL)
        {
                printf ("\nArchivo no disponible.\n");
                exit(1);
        }
        system ("clear");
        while (fscanf(fp, " %i\t", &book[i].clave) == 1)
        {
                fscanf(fp, " %[^\t]", book[i].autor);
                fscanf(fp, " %[^\t]", book[i].titulo);
                fscanf(fp, " %[^\t]", book[i].editorial);
                fscanf(fp, " %[^\t]", book[i].pais);
                fscanf(fp, " %i\t", &book[i].anio);
                fscanf(fp, " %i\n", &book[i].prestamo);
                i++;
        }
        fclose(fp);

	do
	{
		system("clear");
		if (fin == 1)
		{
			printf ("\nSe le regreso al menú principal\n");
		}
		printf ("\n\tBIBLIOTECA\n");
		printf ("\nFuncionalidades: \n");
		printf ("\n1.Dar de alta un libro.");
		printf ("\n2.Ver informe de libros.");
		printf ("\n3.Modificar o dar de baja un libro.");
		printf ("\n4.Buscar un libro por titulo o autor.");
		printf ("\n5.Buscar por país o año.");
		printf ("\n6.Salir del programa.\n");
		printf ("\nIngresa el número de la opcion que quieres hacer: ");
		scanf (" %i", &opcion);

		if (opcion == 1)
		{
			darDeAlta(book);
			fin = 1;
		}
		if (opcion == 2)
		{
			i = mostrarInformes(book, i);
			fin = 1;
		}
		if (opcion == 3)
		{
			i = modificarRegistros(book, i);
			fin = 1;
		}
		if (opcion == 4)
		{
			buscarRegistro(book, i);
			fin = 1;
		}
		if (opcion == 5)
		{
			buscarPorPaisAnio(book, i);
			fin = 1;
		}
		if (opcion == 6)
		{
			salirYguardar(book, i);
			salir = 0;
		}
	}
	while(salir != 0);
	return 0;
}

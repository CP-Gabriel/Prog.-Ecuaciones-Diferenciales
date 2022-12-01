#include "tipos.h"

extern tipoCiudadano *insertarFIFO(char nom[], int postal, int age, char mes[], tipoCiudadano *pt);
extern tipoCiudadano *pushLIFO(char nom[], int postal, int age, char mes[], tipoCiudadano *pt);
void actualizarAplicacion(tipoCiudadano *ptm, char nomArch[]);
void recorrerLista(tipoCiudadano *pt);

int main (int argc, char *argv[])
{
	tipoCiudadano *inicio1, *inicio2, *inicio3, *inicio4;
	char nom[80];
	int postal;
	int age;
	char mes[20];
	char nomArch[20];

	int cpingresado;
        char mesingresado[20];

	strcpy(nomArch, argv[1]);

	inicio1= NULL;
	inicio2= NULL;
	inicio3= NULL;
	inicio4= NULL;

	FILE *fp;
	fp = fopen(argv[1], "r");
        if(fp == NULL)
        {
                printf ("\nArchivo no disponible.\n");
                exit(1);
        }

	printf ("\nIngresa el código postal que quieres buscar: ");
        scanf (" %i", &cpingresado);
        printf ("\nIngresa el mes postal que quieres buscar: ");
        scanf (" %s", mesingresado);
	
	while (fscanf (fp, "%[^\t]", nom) == 1)
	{
		fscanf (fp, "%i\t", &postal);
		fscanf (fp, "%i\n", &age);
		fscanf (fp, "%s\n", mes);
		inicio1 = insertarFIFO(nom, postal, age, mes, inicio1);
		inicio2 = pushLIFO(nom, postal, age, mes, inicio2);
	}
	fclose(fp);
	printf ("\nLista FIFO:");
	actualizarAplicacion(inicio1, nomArch);
        recorrerLista(inicio1);
        printf ("\nLista LIFO:");
	actualizarAplicacion(inicio2, nomArch);
        recorrerLista(inicio2);
	printf("\n");
	return 0;
}

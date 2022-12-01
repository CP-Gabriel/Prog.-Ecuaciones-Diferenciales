#include "tipos.h"

tipoNodo *pushFIFO(int num);
int main(int argc, char *argv[])
{
	tipoNodo inicio;
	inicio = NULL;
	FILE *fp;
	int num;

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf ("\nArchivo no disponible.\n");
	}
	while(fscanf(fp, "%i", &num) == 1)
	{
		inicio = pushFIFO(num); //La función pushFIFO crea la lista dinámica de nodos.
	}
	fclose(fp);
	return 0;
}

tipoNodo *pushFIFO(int num)
{
	
}

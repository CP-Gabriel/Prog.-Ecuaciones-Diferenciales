#include "tipos.h"

tipoFrase *pushLIFO(char palabras[], tipoFrase *aux);
//tipoFrase *parte1(tipoFrase *aux);
void parte1(tipoFrase *aux);
void recorrerLista(tipoFrase *aux);

int main(int argc, char *argv[])
{
	char palabras[50];
	tipoFrase *inicio, *inicio2;
	inicio = NULL;
	inicio2 = NULL;

        FILE *fp;
        fp = fopen(argv[1], "r");
        if(fp == NULL)
        {
                printf ("\nArchivo no disponible.\n");
                exit(1);
        }
	while(fscanf(fp, "%s", palabras) == 1)
        {
                inicio = pushLIFO(palabras, inicio);
        }
        fclose(fp);
	printf ("\nLista LIFO:\n");
//	inicio = parte1(inicio);
	parte1(inicio);
        recorrerLista(inicio);
	printf ("\n");
	return 0;
}

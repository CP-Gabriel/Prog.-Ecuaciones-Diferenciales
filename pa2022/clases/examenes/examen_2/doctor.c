/**
* @file
* @brief
* @author
* @date
*/

#include "tipos.h"

//tipoNodo *crearListaDoble(tipoNodo *aux, tipoPaciente paciente);
tipoNodo *crearListaDoble(tipoNodo *aux, char name[], float weight, float height, int diag);
void recorrerSiguientes(tipoNodo *aux);
void recorrerAnteriores(tipoNodo *aux);

tipoNodo *listaFinal(tipoNodo *aux);
void recorrerSiguientes2(tipoNodo *aux);
void recorrerAnteriores2(tipoNodo *aux);

void filtrarResultados(float filtroPeso, float filtroAltura, tipoNodo *aux);
void crearTablero(tipoNodo *aux);

int main(int argc, char *argv[])
{
	tipoNodo *inicio, *fin;
//	tipoPaciente registro;
	char name[20];
	float weight;
	float height;
	int diag;
	float filtroPeso, filtroAltura;
	sscanf (argv[1], " %f", &filtroPeso);
	sscanf (argv[2], " %f", &filtroAltura);

	FILE *fp;
	inicio = NULL;
	fp = fopen("pacientes.txt", "r");

        if (fp == NULL)
        {
                printf ("\nArchivo no disponible.\n");
                exit(1);
        }

//	while (fread(&registro, sizeof(tipoPaciente), 1, fp) == 1)
	while (fscanf(fp, "%s\t", name) == 1)
        {
		fscanf (fp, "%f\t", &weight);
		fscanf (fp, "%f\t", &height);
		fscanf (fp, "%i\n", &diag);
//                inicio = crearListaDoble(inicio, registro);
                inicio = crearListaDoble(inicio, name, weight, height, diag);
        }
        fclose(fp);

/*        printf ("\nRecorrido en sentido -> siguientes:\n");
        recorrerSiguientes(inicio);

        printf ("\nRecorrido en sentido -> anteriores:\n");
        recorrerAnteriores(inicio);*/

	fin = listaFinal(inicio);

/*        printf ("\nRecorrido en sentido -> siguientes:\n");
        recorrerSiguientes2(inicio);
	printf ("\nRecorrido en sentido -> anteriores:\n");
        recorrerAnteriores2(fin);*/

	filtrarResultados(filtroPeso, filtroAltura, inicio);
	crearTablero(inicio);

	printf ("\n");
	return 0;
}

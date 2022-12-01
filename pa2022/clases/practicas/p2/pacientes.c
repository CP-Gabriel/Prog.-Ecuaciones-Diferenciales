/**
* @file
* @brief
* @date
* @author
*/
#include "tipos.h"

tipoRegistro *pushCircular(char nom[], char apell[], char cp[], bool covid, char siOno, tipoRegistro *refInicio);
//tipoRegistro *pushCircular(char nom[], char apell[], char cp[], tipoRegistro *refInicio);
tipoRegistro *insertarFIFO(char nom[], char apell[], char cp[], bool covid, char siOno, tipoRegistro *aux);

void recorrerCircular(tipoRegistro *aux);
void recorrerLista(tipoRegistro *aux);
void opcionR(tipoRegistro *aux);
void opcionC(tipoRegistro *aux);

int main(int argc, char *argv[])
{
	tipoRegistro *inicio, *inicio2;
	int i;
	char nom[80];
	char apell[80];
	char cp[5];
	/*int codificado;
	codificado = 0;*/
	bool covid;
	char siOno, opcion;

	inicio = NULL;
	inicio2 = NULL;

	FILE *fp;
	fp = fopen(argv[1], "r");
        if (fp == NULL)
        {
                printf ("\nArchivo no disponible.\n");
                exit(1);
        }
	while (fscanf(fp,"%s", nom) == 1)
        {
		fscanf (fp, "%s\t", apell);
               	fscanf (fp, "%s\t", cp);
		/*codificado = strtol(cp, NULL, 10);	CONVERTIR EL STRING EN ENTERO
		printf ("\nCodificado: %i\n", codificado);*/
		
		/*for (i = 1; i < strlen(cp); i++)
		{
			cp[i] = codificado[i];		CODIFICAR EL STRING MENOS LA PRIMERA POSICIÓN
			printf ("\nCodigo Postal: %c\n", cp[i]);
			//printf ("\nCodificado: %c\n", codificado[i]);
		}*/
		fscanf (fp, "%c\n", &siOno);
                inicio = pushCircular(nom, apell, cp, covid, siOno, inicio);
		//inicio2 = insertarFIFO(nom, apell, cp, covid, siOno, inicio2);
        }
        fclose(fp);
/*
	printf ("\nFuncionalidad:");
	printf ("\nOpcion 'r': Recorrer la lista de pacientes 1 a uno.");
	printf ("\nOpcion 'c': Identificar pacientes con covid.");
	printf ("\nOpcion 's': Salir del programa.");
	printf ("\n\nIngresa la opcion que quieres realizar: ");
	scanf ("%c", &opcion);
	if (opcion == 'r')
	{
		opcionR(inicio);
	}
	if (opcion == 'c')
        {
		opcionC(inicio);
        }
	else
        {

        }
*/

	printf ("\nRecorrer lista Circular:");
        recorrerCircular(inicio);
//	recorrerLista(inicio);
/*	printf ("\nLista FIFO:");
	recorrerLista(inicio2);
	recorrerCircular(inicio2);*/
	printf ("\n");
	return 0;
}

/**
* @file catMascotas.c
* @brief Este ejemplo manipula archivos binarios. Utiliza como ejemplo
*	 un catálogo de registros de mascotas (raza, peso y edad).
*	 A) El programa permite guardar en el archivo binario mascotas.bin
*	 los datos que cataloga el usuario. Ingresa tantas mascitas como desee.
*	 El programa calcula el tamaño del archivo y número de mascotas catalogadas
*	 utilizando las funciones de archivos binario.
*
*	 B) Imprima un infotme en pantalla de la información capturada en mascotas.bin
*	 e indique la posición relatica (su posiciónde inicio a fin) en el
*	 archivo de cada registro.
*
*	 C) Permita que el usuario modifique los datos de una mascota que este en una posición dada
*	 del archivo binario
* @author clase de Guillermo Gómez
* @date 11/marzo/2022

*/

#include "tipos.h"

void guardarMascota(tipoMascota datos);
void imprimirPosArch(char nomArch[]);
void modificarArchBin(char nomArch[], int pos, tipoMascota datos);

int main(int argc, char *argv[])
{
	tipoMascota mascota;
	char opcion = 's';
	int tamArch, numMascotas;
	int pos;

	FILE *fp;
	fp = fopen("mascotas.bin", "r+b");
	if(fp==NULL)
	{
	  	printf("\nEl archivo no esta disponible.\n");
  		exit(1);
	}

	fseek (fp, 0, SEEK_END);
	tamArch = ftell(fp);
	numMascotas = tamArch/sizeof(tipoMascota);
	printf ("\nEl tamaño en bytes del archivo es: %i tipoMascota tiene %li bytes, entonces tienes %i mascotas\n", tamArch, sizeof(tipoMascota), numMascotas);
	fclose(fp);

	while (opcion == 's')
	{
		system("clear");
		printf ("\nDame la raza: ");
		scanf (" %[^\n]", mascota.raza);
		printf ("\nDame peso y edad: ");
		scanf (" %f %d", &mascota.peso, &mascota.edad);
		guardarMascota(mascota);
		printf ("\n¿Deseas ingresar otra mascota? ");
                scanf (" %c", &opcion);
	}
	imprimirPosArch("mascotas.bin");

	printf ("\nCapture los datos y la posicion de la mascota que desee modificar.\n");
	printf ("\nDame la raza: ");
        scanf (" %[^\n]", mascota.raza);
        printf ("\nDame peso y edad: ");
        scanf (" %f %d", &mascota.peso, &mascota.edad);
//        guardarMascota(mascota);
        printf ("\nDame la posición: ");
	scanf(" %i", &pos);
	modificarArchBin("mascotas.bin", pos, mascota);
	imprimirPosArch("mascotas.bin");

	return 0;
}

/**
* @brief Esta funcion recibe los datos de una mascota y los anexa en un
*	 archivo binario "mascotas.bin".
* @author clase de Guillermo Gómez
* @date 11/marzo/2022
* @param
* @return void
*/

void guardarMascota(tipoMascota datos)
{
	FILE *fp;
	fp = fopen("mascotas.bin", "a+b");
	if (fp == NULL)
	{
		printf ("\nEl archivo no esta disponible.\n");
		exit(1);
	}
	else
	{
		fwrite (&datos, sizeof(tipoMascota), 1, fp);
	}
	fclose(fp);
	return;
}


void imprimirPosArch(char nomArch[])
{
	int pos = 0;
	tipoMascota datos;

	FILE *fp;
	fp =fopen(nomArch, "r+b");
	if (fp == NULL)
        {
                printf ("\nEl archivo no esta disponible.\n");
                exit(1);
        }
        else
	{
		while(fread(&datos, sizeof(tipoMascota), 1, fp) == 1)
		{
			printf ("\nEn la posición: %i tenemos: %s de edad: %i con un peso de: %f\n", pos, datos.raza, datos.edad, datos.peso);
			pos++;
		}
	}
	fclose (fp);
	return;
}

void modificarArchBin(char nomArch[], int pos, tipoMascota datos)
{
	FILE *fp;
        fp =fopen(nomArch, "r+b");
        if (fp == NULL)
        {
                printf ("\nEl archivo no esta disponible.\n");
                exit(1);
        }
	else
	{
		fseek (fp, pos*sizeof(tipoMascota), SEEK_SET);
		fwrite (&datos, sizeof(tipoMascota), 1, fp);
	}
	fclose (fp);
	return;
}

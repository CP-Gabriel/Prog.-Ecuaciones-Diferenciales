/**
* @file leeChar.c
* @brief este progrrama abre un archivo de texto para lectura;
*	 debe ir leyendo los carácteres y debe verificar si no es
*	 el fin de archivo.
* @author clase de Guillermo.
* @date: 04/feb/2022
*/

#include <stdio.h> //Para manipular funciones de archivos anexar $
#include <stdlib.h>

int main(void)
{
        FILE *fp;
        char letra;
        fp = fopen ("letras.txt", "r");
        if (fp == NULL)
        {
                printf ("\nArchivo no disponoible.\n");
                exit(1);
        }
	while (fscanf (fp, " %c", &letra) == 1)
	{
		printf ("\nSe leyó: %c\n", letra);
	}
	fclose(fp);
	return 0;
}

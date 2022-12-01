/**
* Esta es una modificación ejemplo.
* @file linea.c
* @brief Este es un ejemplo del uso de la línea de comandos.
* @author clase de Guillermo Gómez
* @date 17/01/22
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
        int i;
        printf ("\nEl usuarios ingresó %i argumentos incluyendo el ejecutable.\n", argc);
        for (i=0; i<argc; i++)
        {
                printf ("El argumento %i es: %s\n", i, argv[i]);
        }
        printf ("\n");
        return 0;
}


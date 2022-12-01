/**
* @file hexadecimal.c
* @brief En este programa se encuentra una función para el archivo principal.
* @authors Equipo 7
* @date 08/02/22
*/

#include "misDef.h"

/**
* @brief Esta función convierte un número hexadecimal en decimal.
* @authors Equipo 7
* @date 08/02/22
* @param arr1 es un arreglo de strings que almacena el primer número ingresado por el usuario.
* @param argv es un arreglo de char que almacena los datos ingresados en la línea de ejecución por el usuario.

* @param arr2 es un arreglo de strings que almacena el segundo número ingresado por el usuario.
* @return dat1 es un apuntador a un entero que almacena el primer número hexadecimal ingresado en decimal
* @return dat2 es un apuntador a un entero que almacena el segundo número hexadecimal ingresado en decimal
*/

extern int convertirHexadecial(char arr1[], char arr2[], char *argv[], float *dat1, float *dat2)
{
        int i, j, tam;
        int pot;

        if (strcmp(argv[3], "hexadecimal") == 0)
        {
                tam = strlen(arr1);
                for (j=tam-1; j>1; j--)
                {
                        pot = pot*16;
                        if(j==(tam-1))
                        {
                                pot = 1;
                        }
                        if (arr1[j]=='0')
                        {
                                *dat1 = *dat1+0*pot;
                        }
                        if (arr1[j]=='1')
                        {
                                *dat1 = *dat1+1*pot;
                        }
                        if (arr1[j]=='2')
                        {
                                *dat1 = *dat1+2*pot;
                        }
                        if (arr1[j]=='3')
                        {
                                *dat1 = *dat1+3*pot;
                        }
                        if (arr1[j]=='4')
                        {
                                *dat1 = *dat1+4*pot;
                        }
                        if (arr1[j]=='5')
                        {
                                *dat1 = *dat1+5*pot;
                        }
                        if (arr1[j]=='6')
                        {
                                *dat1 = *dat1+6*pot;
                        }
                        if (arr1[j]=='7')
                        {
                                *dat1 = *dat1+7*pot;
                        }
                        if (arr1[j]=='8')
                        {
                                *dat1 = *dat1+8*pot;
                        }
                        if (arr1[j]=='9')
                        {
                                *dat1 = *dat1+9*pot;
                        }
                        if (arr1[j]=='A')
                        {
                                *dat1 = *dat1+10*pot;
                        }
                        if (arr1[j]=='B')
                        {
                                *dat1 = *dat1+11*pot;
                        }
                        if (arr1[j]=='C')
                        {
                                *dat1 = *dat1+12*pot;
                        }
                        if (arr1[j]=='D')
                        {
                                *dat1 = *dat1+13*pot;
                        }
                        if (arr1[j]=='E')
                        {
                                *dat1 = *dat1+14*pot;
                        }
                        if (arr1[j]=='F')
                        {
                                *dat1 = *dat1+15*pot;
                        }
                }
        }
        if (strcmp(argv[4], "hexadecimal") == 0)
        {
                tam = strlen(arr2);
                for (j=tam-1; j>1; j--)
                {
                        pot = pot*16;
                        if(j==(tam-1))
                        {
                                pot = 1;
                        }
                        if (arr2[j]=='0')
                        {
                                *dat2 = *dat2+0*pot;
                        }
                        if (arr2[j]=='1')
                        {
                                *dat2 = *dat2+1*pot;
                        }
                        if (arr2[j]=='2')
                        {
                                *dat2 = *dat2+2*pot;
                        }
                        if (arr2[j]=='3')
                        {
                                *dat2 = *dat2+3*pot;
                        }
                        if (arr2[j]=='4')
                        {
                                *dat2 = *dat2+4*pot;
                        }
                        if (arr2[j]=='5')
                        {
                                *dat2 = *dat2+5*pot;
                        }
                        if (arr2[j]=='6')
                        {
                                *dat2 = *dat2+6*pot;
                        }
                        if (arr2[j]=='7')
                        {
                                *dat2 = *dat2+7*pot;
                        }
                        if (arr2[j]=='8')
                        {
                                *dat2 = *dat2+8*pot;
                        }
                        if (arr2[j]=='9')
                        {
                                *dat2 = *dat2+9*pot;
                        }
                        if (arr2[j]=='A')
                        {
                                *dat2 = *dat2+10*pot;
                        }
                        if (arr2[j]=='B')
                        {
                                *dat2 = *dat2+11*pot;
                        }
                        if (arr2[j]=='C')
                        {
                                *dat2 = *dat2+12*pot;
                        }
                        if (arr2[j]=='D')
                        {
                                *dat2 = *dat2+13*pot;
                        }
                        if (arr2[j]=='E')
                        {
                                *dat2 = *dat2+14*pot;
                        }
                        if (arr2[j]=='F')
                        {
                                *dat2 = *dat2+15*pot;
                        }
                }
        }
                //printf ("\nResultado: %i", dat1);
                //printf ("\nResultado: %.2f", dat2);
        return *dat1, *dat2;
}





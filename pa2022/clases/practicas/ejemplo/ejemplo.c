/**
* @file ejemplo.c
* @brief 
* @authors Equipo 7
* @date 08/02/22
*/

#include "misDef.h"

extern int convertirHexadecial(char arr1[], char arr2[], char *argv[], float *dat1, float *dat2);
extern int convertir(char arr3[], float *dat3, int *x);
extern void resultado (char arr1[], char arr2[] , char arr3[], char *argv[], float dat3, int x);

int main(int argc, char *argv[])
{
        char arr1[50];
        char arr2[50];
        char arr3[50];
        int i, j, x, tam;
        float dat1;
        float dat2;
        float dat3;

        if(argc == 6)
        {
                sscanf (argv[1], " %i", &tam);
                for (i=1; i<=tam; i++)
                {
			printf ("\n");
                      	printf ("\nIngresa el número en %s que se guardará en el arreglo1 en la posición %i: ", argv[3], i);
                        scanf (" %[^\n]", arr1);
        	        printf ("\nIngresa el número en %s que se guardará en el arreglo2 en la posición %i: ", argv[4], i);
                        scanf (" %[^\n]", arr2);

			//CONVERSIONES DE BASES
			dat1=0;
		        dat2=0;
		        dat3=0;
			convertirHexadecial(arr1, arr2, argv, &dat1, &dat2);
			//
			if (strcmp(argv[3], "decimal") == 0)
                        {
				dat1 = strtol(arr1, NULL, 10);
                        }
			if (strcmp(argv[4], "decimal") == 0)
                        {
				dat2 = strtol(arr2, NULL, 10);
                        }
			//OPERACIONES
			if (*argv[2] == '+')
			{
				dat3 = dat1 + dat2;
			}
			if (*argv[2] == '-')
                        {
                                dat3 = dat1 - dat2;
                        }
			if (*argv[2] == 'x')
                        {
                                dat3 = dat1 * dat2;
                        }
			if (*argv[2] == '/')
                        {
                                dat3 = dat1 / dat2;
                        }
			if (*argv[2] == '^')
                        {
				dat3 = 1;
				for (int i=0; i<dat2; i++)
				{
					dat3 = dat3 * dat1;
				}
                        }
			//FIN DE LAS OPERACIÓNES

			//IMPRESIÓN DE RESULTADOS
			resultado(arr1, arr2 , arr3, argv, dat3, x);
			//
                }
        }
        else
        {
                printf ("\nDatos de entrada incompleto.\n");
        }
        printf ("\n\n");
        return 0;
}

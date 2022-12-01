/**
* @file potencia.c
* @brief En este programa se encuentra la una función del programa "principal".
* @authors Equipo 7
* @date 08/02/22
*/
#include "misDef.h"

/**
* @brief Esta función permite convertir un número decimal a hexadecimal.
* @authors Equipo 7
* @date 08/02/22
* @param original es un entero que almacenará un número ingresado por el usuario.
* @param decimal es un entero que copia el valor de original para poder hacer la conversión de decimal a hexadecimal¨.
* @param i es un entero que empiza desde 0 y que va sumandose de 1 en 1 ya que va hacer la posición en la que se guardará el número en hexadecimal en el arreglo conv[].
* @param hex[] es un arreglo de char que almacena los valores hexadecimal según su posición para realizar la conversión de bases.
* @return void
*/

extern int convertir(char arr3[], float *dat3, int *x)
{
	int original, decimal;
	char hex[16]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	decimal = *dat3;
	*x=2;
	while(decimal>=16)
	{
		*x= *x+1;
		if(decimal == *dat3)
		{
			arr3[2] = hex[decimal%16];
			decimal = decimal/16;
		}
		arr3[*x] = hex[decimal%16];
                decimal = decimal/16;
	}
	*x=*x+1;
	arr3[*x] = hex[decimal];
	arr3[*x+1] = 'x';
        arr3[*x+2] = '0';
	return *arr3, *x;
}

/**
* @brief
* @authors Equipo 7
* @date 08/02/22
* @param
* @return
*/

extern void resultado (char arr1[], char arr2[] , char arr3[], char *argv[], float dat3, int x)
{
	//IMPRESIÓN DE RESULTADOS
	//printf ("\nNúmero 1 en decimal: %i", dat1);
	//printf ("\nNúmero 2 en decimal: %i", dat2);
	int j;
	printf ("\n\tArreglo 1\t%s", arr1);
	printf ("\n\tArreglo 2\t%s", arr2);
	if (strcmp(argv[5], "decimal") == 0)
	{
		if (*argv[2] == '/')
		{
			printf ("\n\tArreglo 3\t%.2f", dat3);
		}
		else
		{
			printf ("\n\tArreglo 3\t%.0f", dat3);
		}
		//printf ("\nEl resultado de la operación en %s que se guardó en el arreglo 3 es: %i", argv[5], dat3);
		}
		if (strcmp(argv[5], "hexadecimal") == 0)
		{
			convertir(arr3, &dat3, &x);
			printf ("\n\tArreglo 3\t");
			for (j=(x+2); j>=0; j--)
			{
				printf ("%c", arr3[j]);
			}
	}
	//FIN DE LA IMPRESIÓN DE RESULTADOS
	return;
}

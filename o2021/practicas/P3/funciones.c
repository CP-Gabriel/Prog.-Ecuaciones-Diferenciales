/*
* @file: funciones.c
* @brief: Este programa contiene las funciones.
* @authors: Gabriel Coronado/Sergio Esquivel/Sebastian Alanis.
* @date: 23/oct/2021
*/

#include "defArreglos.h"

/*
* @brief: Esta función muestra las instrucciones del programa.
* @authors: Gabriel Coronado/Sergio Esquivel/Sebastian Alanis.
* @date: 23/oct/2021
* @param void
* @return void
*/

extern void imprimirInstrucciones(void)
{
	printf ("\nEste programa permite ingresar un grupo de 5 valores y un segundo grupo de 5 valores para \ncalcular la suma y multiplicación de cado uno de ellos, al final mostrará los valores del \nprimer grupo ordenados de menor a mayor\n");
	return;
}

/*
* @brief: Esta función permite ingresar los números de los dos arreglos al usuario.
* @authors: Gabriel Coronado/Sergio Esquivel/Sebastian Alanis.
* @date: 23/oct/2021
* @param arreglo1[] es la referencia del primer arreglo de números ingresados.
* @param arreglo2[] es la referencia del segundo arreglo de números ingresados.
* @return void
*/

extern void ingresarArr(float arreglo1[], float arreglo2[])
{
	int i, j;
	printf ("\nPRIMER ARREGLO\n");
	for (i=1; i<=TAM; i++)
	{
		printf ("Ingresa el valor [%i] : ", i);
		scanf (" %f", &arreglo1[i]);
	}
	printf ("\nSEGUNDO ARREGLO\n");
        for (j=1; j<=TAM; j++)
        {
                printf ("Ingresa el valor [%i] : ", j);
                scanf (" %f", &arreglo2[j]);
        }
	return;
}

/*
* @brief: Esta función  permite sumar arreglo1 más arreglo2.
* @authors: Gabriel Coronado/Sergio Esquivel/Sebastian Alanis.
* @date: 23/oct/2021
* @param arreglo1[] es la referencia del primer arreglo de números ingresados.
* @param arreglo2[] es la referencia del segundo arreglo de números ingresados.
* @param arreglo3[] es la referencia del arreglo en el que se guardará la suma de arreglo1 más el arreglo2.
* @return void
*/

extern void sumarArr(float arreglo1[], float arreglo2[], float arreglo3[])
{
	int i;
	for (i=1; i<=TAM; i++)
	{
		arreglo3[i]= arreglo1[i]+arreglo2[i];
	}
	return;
}

/*
* @brief: Esta función permite multiplicar arreglo1 por arreglo2.
* @authors: Gabriel Coronado/Sergio Esquivel/Sebastian Alanis.
* @date: 23/oct/2021
* @param arreglo1[] es la referencia del primer arreglo de números ingresados.
* @param arreglo2[] es la referencia del segundo arreglo de números ingresados.
* @param arreglo3[] es la referencia del arreglo en el que se guardará la multiplicación de arreglo1 por arreglo2.
* @return void
*/

extern void multiArr(float arreglo1[], float arreglo2[], float arreglo3[])
{
        int i;
        for (i=1; i<=TAM; i++)
        {
                arreglo3[i]= arreglo1[i]*arreglo2[i];
        }
        return;
}

/*
* @brief: Esta función ordena los datos del primer arreglo de menor a mayor.
* @authors: Gabriel Coronado/Sergio Esquivel/Sebastian Alanis.
* @date: 23/oct/2021
* @param arreglo1[] es la referencia del primer arreglo de números ingresados y es donde se guardarán los datos ordenados.
* @return void
*/

extern void ordenarArr1(float arreglo1[])
{
	int i, j;
	float temp;
	for (i=1; i<=TAM; i++)
	{
		for (j=i+1; j<=TAM; j++ )
		{
			if (arreglo1[i]>arreglo1[j])
			{
				temp=arreglo1[i];
				arreglo1[i]=arreglo1[j];
				arreglo1[j]=temp;
			}
		}
	}
	return;
}

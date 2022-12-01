#include <stdio.h>
#define TAM 10

int busquedaBinariaLineal(int x, int arr[], int n);
void bubbleSort(int arr[], int elem);

int main(void)
{
	int arreglo[TAM] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
	int i, num, posicion;

	printf ("\nDatos en desorden:\n");
	for (i=0; i<TAM; i++)
	{
		printf ("%i \t", arreglo[i]);
	}
	printf ("\n");
	bubbleSort(arreglo, TAM);
	printf ("\nDatos en orden:\n");
	for (i=0; i<TAM; i++)
	{
		printf ("%i \t", arreglo[i]);
	}
	printf ("\n");
	printf ("\nDame el número que deseas buscar: ");
	scanf (" %i", &num);
	posicion = busquedaBinariaLineal(num, arreglo, TAM);
	if (posicion > 0)
	{
		printf ("\nEn el número %i está en la posición [%i]\n", num, posicion);
	}
	else
	{
		printf ("El número buscado no existe, la posición es: %i", posicion);
	}
	printf ("\n");
	return 0;
}

void bubbleSort(int arr[], int elem)
{
	int i, j, temp;
	for (i=0; i<=(elem-2); i++)
	{
		for(j = (i+1); j<=(elem-1); j++)
		{
			if (arr[i] > arr[j])// ascendente
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return;
}

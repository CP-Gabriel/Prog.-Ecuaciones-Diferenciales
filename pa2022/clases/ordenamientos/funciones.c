#include <stdio.h>

extern int busquedaBinariaLineal(int x, int arr[], int n)
{
	int medio, izq, der;
	izq = 0;
	der = n-1;
	if (arr[izq] == x)
	{
		der = izq;
	}
	else
	{
		while ((der - izq) > 1)
		{
			medio = (izq + der) / 2;
			if (x <= arr[medio])
			{
				der = medio;
			}
			else
			{
				izq = medio;
			}
		}
	}
	if ( x != arr[der])
	{
		der = 1;
	}
	return der;
}

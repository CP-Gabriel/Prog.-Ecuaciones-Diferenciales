#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x) (1.0/(x))

void formula()
{
	double a = 0.5;
	double b = 2.0;
	double posicion = 0.0;
	double suma = 0.0;
	double resultado;
	int i, n;

	for (n=3; n<=10; n++)
	{
		for (i=1; i<n; i++)
		{
			posicion = a + (i*((b-a)/n));
			suma = 2.0*F(posicion) + suma;
/*			printf ("\nB-A = %f", b-a);
			printf ("\nN: %i", n);
			printf ("\nI: %i", i);
			printf ("\nPOSICION: %f", posicion);
			printf ("\nSUMA: %f", suma);*/
		}
		resultado = (((b-a)/(2.0*n))*(F(a)+suma+F(b)));
		printf("\nEl resultado es  %.10f cuando n vale %i" , resultado, n);
		suma = 0.0;
	}
	return;
}

int main()
{
	float resultado;
	system ("clear");
	formula();
	printf ("\n");
	return 0;
}

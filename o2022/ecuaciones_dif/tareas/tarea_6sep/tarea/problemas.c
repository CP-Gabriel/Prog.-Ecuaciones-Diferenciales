#include "tipos.h"

extern float dx(float x , float y);
extern float pendienteInfinito();
extern int intersecciones(float *x, float *y);
extern int puntosCriticos(float *puntoCritico);

int main()
{
	float x, y, puntoCritico;

	system ("clear");

	printf ("\nLa pendiente en cero es: %f", dx(0, 0.00001));
	printf ("\nLa pendiente en infinito es: %f", pendienteInfinito());
	intersecciones(&x, &y);
	printf ("\nLa interseccion en X es: %f", x);
	printf ("\nLa interseccion en Y es: %f", y);

	if (puntosCriticos(&puntoCritico) == 1)
	{
		printf ("\nEl punto critico es: %f", puntoCritico);
	}
	else
	{
		printf ("\nNO TIENE PUNTOS CRITICOS");
	}
	printf ("\n\n");
	return 0;
}

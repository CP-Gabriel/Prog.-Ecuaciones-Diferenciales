#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define F(t)(t-cos(t))
#define F(t)(16-pow(t,2))
/*float df(float ta, float h)
{
        float t = ta + h;
        return (F(t) - F(ta))/h;
}

float resultados(float min, float sust, float derv)
{
        return (min - (sust/derv));
}*/
float sumatoria(int inicio, int fin)
{
	float area;
	float suma = 0.0;
	float altura, base;

	for (int i=inicio; i<=fin; i++)
	{
		altura = F(i);
		base = i-(i-1);
		area = base*altura;
//		suma = (0.5*F(i))+suma;
		suma = suma + area;
//		suma = (altura*base)+suma;
	}
	return suma;
}

int main(void)
{
	int inicio = 0;
	int fin = 3;
	system ("clear");
	float resultado = sumatoria(inicio, fin);

	printf ("\nResultado: %f\n", resultado);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x) (1.0/(x))

void formula()
{
	double a = 0.5;
	double b = 2.0;
	double area = 0.0;
	double delta, w;
	int n, i;

        for (n=4; n<=4; n++)
        {
		delta = (b-a)/n;
		for (i=1; i<=n; i++)
		{
			//POR EL CENTRO
//			w = a + ((i*((b-a)/n))-((b-a)/(2.0*n)));

			//POR LA IZQUIERDA
//			w = a + ((i*((b-a)/n))-((b-a)/(n)));

			//POR LA DERECHA
			w = a + ((i*((b-a)/n)));
			printf ("\n Punto: %f", w);
			area = (F(w)*delta)+area;
                }
		printf ("\nEl resultado cuando n vale %i es %f", n, area);
		area = 0.0;
        }
        return;
}

int main()
{
        float resultado;
//        system ("clear");
        formula();
        printf ("\n");
        return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(t) ((sin(t)) - (cos(t)) - 1.1 )

/**
* @brief Esta funcion calcula una derivada.
* @param ta es un float con el valor a evaluar de x.
* @param h es un float con el valor de h que se tomara para el limite.
* @rerturn va a hacer un float con el valor de la ecuacion realizada.
*/
float df(float ta, float h)
{
        float t = ta + h;
        return (F(t) - F(ta))/h;
}
float resultados(float min, float sust, float derv)
{
        return (min - (sust/derv));
}

/**
* @brief Este programa calcula el valor de una raiz con el metodo de Newrton
*/
int main(void)
{
        float reslt[100];
        float h = 0.01f;
        float min;
        double resultado, resultado2;
	int i, j;
	int iter = 1;

        system("clear");

        min = -3;
        reslt[0] = min;

        for (j=1; j<=100; j++)
        {
                reslt[j] = resultados(min, F(min), df(min,h));
                min = reslt[j];
        }

	for (i=1; i<=100; i++)
	{
		resultado = reslt[i];
		for (j=(i+1); j<=10; j++)
		{
			iter++;
			resultado2 = reslt[j];
			if(resultado2 == resultado)
			{
				iter++;
				if (iter=11)
				{
					printf ("\nEl resultado de la raíz en el intervalo -2 y -4 es: %f", resultado);
					iter = (iter-6)+i;
					printf ("\nEl numero de iteraciones necesarias para calcularlo fue de: %i\n", iter);
					printf ("\nMuestreo: ");
					for (int a=1; a<=iter; a++)
					{
						printf ("\nIteracion %i resultado %f", a, reslt[a]);
					}
				        printf ("\n\n");
					return 0;
				}
			}
		}
	}

        return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x) (pow((((3.0*x)-1)/((pow(x,2))+3)),2))

/**
* @brief Esta funcion calcula la deriva de progresiva
* @author Gabriel Coronado
* @date 22/09/22
* @param ta es un float con el valor a evaluar de x.
* @param h es un float con el valor de h que se tomara para el limite.
* @rerturn va a hacer un float con el valor de la ecuacion realizada.
*/
float primerDerivada(float ta, float h)
{
        float t = ta + h;
        return (F(t) - F(ta))/h;
}
float segundaDerivada(float ta, float h)
{
        float t = ta + h;
        return (primerDerivada(t,h) - primerDerivada(ta,h))/h;
}
float tercerDerivada(float ta, float h)
{
        float t = ta + h;
        return (segundaDerivada(t,h) - segundaDerivada(ta,h))/h;
}
float cuartaDerivada(float ta, float h)
{
        float t = ta + h;
        return (tercerDerivada(t,h) - tercerDerivada(ta,h))/h;
}


/**
* @brief Este programa calcula la deriva progresiva, regresiva y central de una ecuacion
* @author Gabriel Coronado
* @date 22/09/22
*/
int main()
{
        float x = 1;
        float h = 0.01;
	int i;
	float reslt[4];
        //SE UTILIZO WOLFRAM PARA SABER EL RESULTADO REAL
        float real = -.25;

        system ("clear");

	reslt[0] = primerDerivada(x,h);
	reslt[1] = segundaDerivada(x,h);
	reslt[2] = tercerDerivada(x,h);
	reslt[3] = cuartaDerivada(x,h);

	for (i=0; i<4; i++)
	{
		printf ("\n Derivada %i: %f", (i+1), reslt[i]);
	}

        printf ("\n");
        return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x,y) ((3.0*(y)) - (x))
//#define W(x) (x/3)
#define G(x,y) (y)
/*float F(float x , float y)
{
	return (3.0*y-x);
}
float G(float x, float y)
{
	return (y);
}*/

float rungeKutta4(float x, float y, float h)
{
        float k1, k2, k3, k4;

//        k1 = h*(F(x, y));
        k1 = h*(F(x, y));
/*	printf ("\nK1: %f", k1);
	printf ("\nX: %f", x);
	printf ("\nY: %f", y);
	printf ("\nH: %f", h);*/

        k2 = h*(F((x + (h/2)), (y + ((k1 * h) / 2))));
	k3 = h*(F((x + (h/2)), (y + ((k2 * h) / 2))));
        k4 = h*(F((x + h), (y + (k3 * h))));
        return (h*(y + ((h/6) * (k1 + (2*k2) + (2*k3) + k4))));
}

float rungeKutta42(float x, float y, float h)
{
        float k1, k2, k3, k4;

        k1 = h*(G(x, y));
/*      printf ("\nK1: %f", k1);
        printf ("\nX: %f", x);
        printf ("\nY: %f", y);
        printf ("\nH: %f", h);*/

        k2 = h*(G((x + (h/2)), (y + ((k1 * h) / 2))));
        k3 = h*(G((x + (h/2)), (y + ((k2 * h) / 2))));
        k4 = h*(G((x + h), (y + (k3 * h))));
        return h*((y + ((h/6) * (k1 + (2*k2) + (2*k3) + k4))));
}

int main()
{
        float x=0;
        float h=0.1;
//        float i, yBiPrima, uPrima=1.0, yRunge=0.0;
        float i, yBiPrima, uPrima=1.0, yRunge=0.0;

//        system ("clear");

        printf ("\nValor X, Valor Y, Valor U\n");

        printf ("%f, 1.00000, 1.00000\n", x);

        for (x=h; x<=(0.3+h); x+=h)
        {
/*
//		printf ("X: %f\nY: %f\n H: %f\n", x-h, yRunge, h);
		yBiPrima = rungeKutta4(x-h, yRunge, h);
//		printf ("Y2: %f\n\n", yBiPrima);
		uPrima = rungeKutta4(x-h, yBiPrima, h);
//                printf ("%f, %f, %f\n", x, yBiPrima, uPrima);
//		yRunge = yBiPrima;
		yRunge = uPrima;*/

/*		uPrima = rungeKutta4(x-h, uPrima, h);
		yBiPrima = rungeKutta4(x-h, uPrima, h);
		uPrima = yBiPrima;*/

		uPrima = rungeKutta4(x-h, uPrima, h);
		yBiPrima = rungeKutta42(x-h, uPrima, h);
//                printf ("%f, %f, %f, %f\n", x, yBiPrima, uPrima, W(x));
                printf ("%f, %f, %f\n", x, yBiPrima, uPrima);
		uPrima = yBiPrima;
        }

        printf ("\n");
        return 0;
}

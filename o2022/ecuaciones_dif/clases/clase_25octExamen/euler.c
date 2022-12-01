#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define F(x,y) (-0.5*pow(x,4) + 4*pow(x,3) - 10*pow(x,2) + 8.5*x + 1)
#define F(x,y) ((pow(x,2)*y) + (pow(x,2)/2))

double derivadaX(double x, double y, double h)
{
        double i = x + h;
        double j = x - h;

        return ((F(i,y)-F(j,y))/(2*h));
}

int main()
{
        double x = 1;
        double y = 1;
        double h = 0.01;
        double valYEuler[20];
        int i;
        valYEuler[0] = 1.0;

        system ("clear");

        for (x=0.25; x<=4; x+=0.25)
        {
                i++;
                valYEuler[i] = valYEuler[i-1] + (derivadaX((x-0.5), valYEuler[i-1], h)*0.5);
		printf ("Valor real de Y%i: %f\n", i-1, F(x, y));
        }

        i = 0;
        for (x=0; x<=4; x+=0.25)
        {
                i++;
//              printf ("%f\n", valYEuler[i-1]);
                printf ("Valor de Y%i: %f\n", i-1, valYEuler[i-1]);
        }

        printf ("\n");
        return 0;
}

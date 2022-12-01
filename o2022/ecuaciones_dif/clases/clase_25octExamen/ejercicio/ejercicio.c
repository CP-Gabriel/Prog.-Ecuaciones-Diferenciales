#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define F(x,y) (-0.5*pow(x,4) + 4*pow(x,3) - 10*pow(x,2) + 8.5*x + 1)
//#define F(x,y) ((pow(,(-2*x)))/4)
#define F(x,y) ((exp(-2*x)/4) * (pow(x,4) + 4))

double derivadaX(double x, double y, double h)
{
        double i = x + h;
        double j = x - h;

        return ((F(i,y)-F(j,y))/(2*h));
}

int main()
{
        double x = 0;
//        double y = 1;
        double h = 0.01;
        double valYEuler[20], valYreal[20];
        int i;
        valYEuler[0] = 1.0;

        system ("clear");

        for (x=0.5; x<=4; x+=0.5)
        {
                i++;
                valYEuler[i] = valYEuler[i-1] + (derivadaX((x-0.5), valYEuler[i-1], h)*0.5);
		valYreal[i-1] = F(x-0.5, 0);
        }

        i = 0;
        printf ("\n");

        for (x=0; x<=4; x+=0.5)
        {
                i++;
                printf ("Valor de Y%i de Euler: %f\n", i-1, valYEuler[i-1]);
//		printf ("Valor real de Y%i: %f\n", i-1, valYreal[i-1]);
//              printf ("%f\n", valYEuler[i-1]);
        }

        i = 0;
        for (x=0; x<=4; x+=0.5)
        {
                i++;
		printf ("Valor real de Y%i: %f\n", i-1, F(x, y));
//                printf ("%f\n", F(x, y));
        }

        printf ("\n");
        return 0;
}

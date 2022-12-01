#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define dy(x,y) ((4*x) -(1*y) +1)
#define dz(x,y) ((2*y) -(1*x))

double eulerYPredictor(double x, double y)
{
        double h = 0.1;
	x = x-h;
        return (y + (h*dy(x,y)));
}
double eulerZPredictor(double y, double z)
{
        double h = 0.1;
        return (z + (h*dz(y,z)));
}


double eulerYCorrectivo(double x, double y, double yPredictor)
{
        double h = 0.1;
	x = x-h;
        return (y + ((h/2)*(dy(x, y) + dy((x+h), yPredictor))));
}
double eulerZCorrectivo(double y, double z, double yCorrectivo, double zPredictor)
{
        double h = 0.1;
        return (z + ((h/2)*(dz(y, z) + dz(yCorrectivo, zPredictor))));
}


int main()
{
        double x = 0.0;
        double y = 1.0;
        double z = 1.0;
        double yPredictor, yCorrectivo, zPredictor;

        system ("clear");
        printf ("Valor X\t|Y Predictor\t|Y Corrector\t|Z Predictor\t|Z Corrector\t|\n");
        printf ("--------|---------------|---------------|---------------|---------------|\n");
        printf ("%.1f\t|\t0.00000\t|\t1.00000\t|\t1.00000\t|\t1.00000\t|\n", x);

        for (x=0.1; x<=0.5; x+=0.1)
        {
                yPredictor = eulerYPredictor(x, y);
		zPredictor = eulerZPredictor(y, z);
		yCorrectivo = eulerYCorrectivo(x, y, yPredictor);
		z = eulerZCorrectivo(y, z, yCorrectivo, zPredictor);
		printf ("%.2f\t|\t%.5f\t|\t%.5f\t|\t%.5f\t|\t%.5f\t|\n", x, yPredictor, yCorrectivo, zPredictor, z);
                y = eulerYCorrectivo(x, y, yPredictor);
        }

        return 0;
}

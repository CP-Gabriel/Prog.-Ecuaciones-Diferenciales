#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define G(x) (-2*pow(x,3) + 12*pow(x,2) - 20*x + 8.5)
//#define F(x) (-0.5*pow(x,4) + 4*pow(x,3) - 10*pow(x,2) + 8.5*x + 1)
#define F(x,y) ((exp(-2*x)/4)*(pow(x,4)+4))
#define dy(x,y) ((pow(x,3))*(exp(-2*x))-(2*y))

double eulerPredictor(double x, double y)
{
        double h = 0.1;
//      double h = 0.05;
        return (y + (dy(x-h,y)*h));
}

double eulerCorrectivo(double x, double y, double yPredictor)
{
	double h = 0.1;
	return (y + (h/2)*(dy(x, y) + dy((x+h), yPredictor)));
}

int main()
{
        double x = 0.0;
        double y = 1.0;
	double yPredictor;

        system ("clear");
        printf ("Valor X\t|\tY real\t|Y Predictor\t|Y Corrector\t|\n");
        printf ("--------|---------------|---------------|---------------|\n");
        printf ("%.1f\t|\t%.5f\t|\t1.00000\t|\t1.00000\t|\n", x, F(x,y));

        for (x=0.1; x<=1; x+=0.1)
//        for (x=0.05; x<=1; x+=0.05)
        {
		yPredictor = eulerPredictor(x,y);
                printf ("%.2f\t|\t%.5f\t|\t%.5f\t|\t%.5f\t|\n", x, F(x,y), eulerPredictor(x,y), eulerCorrectivo(x, y, yPredictor));
                y = eulerPredictor(x,y);
        }

        return 0;
}

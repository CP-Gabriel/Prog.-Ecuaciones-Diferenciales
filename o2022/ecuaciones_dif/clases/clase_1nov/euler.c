#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G(x) (-2*pow(x,3) + 12*pow(x,2) - 20*x + 8.5)
#define F(x) (-0.5*pow(x,4) + 4*pow(x,3) - 10*pow(x,2) + 8.5*x + 1)

/*double df(double x)
{
        double xh = x + h;
        double h = 0.01;
        return (F(xh) - F(x))/h;
}*/

double euler(double x, double y)
{
	double h = 0.1;
//	double h = 0.25;
	return (y + G((x-h))*h);
}

int main()
{
	double x = 0.0;
	double y = 1.0;

	system ("clear");
	printf ("Valor X\t|\tY real\t|\tY Euler\t|\n");
	printf ("--------|---------------|---------------|\n");
	printf ("%.1f\t|\t%.5f\t|\t1.00000\t|\n", x, F(x));

	for (x=0.1; x<=1; x+=0.1)
//	for (x=0.25; x<=4; x+=0.25)
	{
		printf ("%.2f\t|\t%.5f\t|\t%.5f\t|\n", x, F(x), euler(x,y));
		y = euler(x,y);
	}

	return 0;
}

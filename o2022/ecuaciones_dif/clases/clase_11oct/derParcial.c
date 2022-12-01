#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x,y) (pow(x,2)-(3*(pow(x,3)*pow(y,2)))+(4*x)-(2*pow(y,3))+6)

double derivadaX(double x, double y, double h)
{
        double i = x + h;
        double j = x - h;

        return ((F(i,y)-F(j,y))/(2*h));
}
double derivadaY(double x, double y, double h)
{
        double i = y + h;
        double j = y - h;

        return ((F(x,i)-F(x,j))/(2*h));
}
/*double derivadaZ(double x, double y, double h)
{
        double i = z + h;
        double j = z - h;

        return ((F(x,y,i)-F(x,y,j))/(2*h));
}*/
double deltaW(double x, double deltaX, double y, double deltaY)
{
	double i = x + deltaX;
	double j = y + deltaY;

	return (F(i,j)-F(x,y));
}
double derivadaW(double x, double deltaX, double y, double deltaY, double h)
{
	return ((derivadaX(x,y,h)*deltaX)+(derivadaY(x,y,h)*deltaY));
}


int main()
{
        double xIni, xFin, deltaX;
	double yIni, yFin, deltaY;
	double h = 0.01;
	double resRealDelta, resDelta;
	double resRealDeriv, resDeriv;
	double error;
	int caso = 1;

        system ("clear");

	if (caso == 1)
	{
		resRealDelta = 7.49;
		resRealDeriv = 7.38;

		xIni = -2;
		xFin = -2.02;
		yIni = 3;
                yFin = 3.01;

		deltaX = xFin - xIni;
		deltaY = yFin - yIni;

		resDelta = deltaW(xIni, deltaX, yIni, deltaY);
		error = fabs(100*((resRealDelta-resDelta)/resRealDelta));
		printf ("\n\tDELTA W\nRESULTADO REAL: %.2f", resRealDelta);
	        printf ("\nEl valor de delta W es: %.4f", resDelta);
		printf ("\nEl error porcentual encontrado fue de: %f", error);

		resDeriv = derivadaW(xIni, deltaX, yIni, deltaY, h);
		error = fabs(100*((resRealDeriv-resDeriv)/resRealDeriv));
	        printf ("\n");
		printf ("\n\tDERIVADA DE W\nRESULTADO REAL: %.2f", resRealDeriv);
		printf ("\nEl valor de la derivada de W es: %.4f", resDeriv);
		printf ("\nEl error porcentual encontrado fue de: %f\n", error);
	}

        printf ("\n");
        return 0;
}

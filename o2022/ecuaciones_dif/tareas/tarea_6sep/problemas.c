#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define F(x)(9.0*x-2)
//#define F(x)(2+8.0*x-5.0*(pow(x,2)))

//#define F(x)(1/(x-2))
#define F(x)(1*(pow(x-2,-1.0)))

//#define F(x)(sqrt(3.0*x+1))
//#define F(x)(pow(3.0*x+1, 0.5))

float dx(float x, float h)
{
        float xh = x + h;
        return (F(xh) - F(x))/h;
}

int main(void)
{
	float x1, x2, derv;
	float x = 1.0;
	float h = 0.01;

	system ("clear");
	x1 = dx(x,h);
	printf ("\nResultado: %f", x1);
	printf ("\nResultado redondeado: %.0f", x1);
	x = 0.00;
	x2 = dx(x,h);
        printf ("\nResultado de la constante: %f", x2);
        printf ("\nResultado redondeado de la constante: %.0f", x2);
	printf ("\nValor de x: %.0f", round(x1-x2));
/*	printf ("\nResultado 2 : %f", x2);
	printf ("\nResultado 2 redondeado: %.3f", x2);
        printf ("\nResultado de x: %.2fx", x1-x2);
        printf ("\nResultado de x redondeado: %.2fx", round(x1)-round(x2));
        printf ("\nOPERACION %.3fx %.3f=0", round(x1-x2), round(x2));
	float reslt = round(-1.0*(x2))/round(x1-x2);
        printf ("\nVALOR DE X: %.2f", reslt);
        printf ("\nVALOR DE Y: %.2f", F(reslt));*/
        printf ("\n\n");
        return 0;
}

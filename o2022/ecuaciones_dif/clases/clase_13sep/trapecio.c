#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x) (1/(1+x))
//#define G(x) (1/(pow((1-(pow(x,2))),0.5)))
#define G(x) (1/(pow((1+(pow(x,2))),0.5)))
#define H(x) (pow((1+(pow(x,3))),0.5))
#define J(x) (1/(pow((4-(pow(x,2))),0.5)))

void formula()
{
        double a;
        double b;
        double posicion = 0.0;
        double suma = 0.0;
        double resultado;
        int i, n;

	//PRIMER CASO
	n = 8;
	a = 0;
	b = 3;

	for (i=1; i<n; i++)
	{
		posicion = a + (i*((b-a)/n));
		suma = 2.0*F(posicion) + suma;
/*                      printf ("\nB-A = %f", b-a);
                        printf ("\nN: %i", n);
                        printf ("\nI: %i", i);
                        printf ("\nPOSICION: %f", posicion);
                        printf ("\nSUMA: %f", suma);*/

	}
	resultado = (((b-a)/(2.0*n))*(F(a)+suma+F(b)));
	printf ("\nPRIMER CASO");
	printf("\nEl resultado es  %.10f cuando n vale %i\n" , resultado, n);
	suma = 0.0;
	//FIN PRIMER CASO

	//INICIO SEGUNDO CASO
	n = 4;
        a = 0.01;
        b = 1;

        for (i=1; i<n; i++)
        {
                posicion = a + (i*((b-a)/n));
                suma = 2.0*G(posicion) + suma;
/*                      printf ("\nB-A = %f", b-a);
                        printf ("\nN: %i", n);
                        printf ("\nI: %i", i);
                        printf ("\nPOSICION: %f", posicion);
                        printf ("\nSUMA: %f", suma);*/
        }
//        resultado = (((b-a)/(2.0*n))*(G(a)+suma+G(b)));
	resultado = (((b-a)/(2.0*n))*(G(a)+suma+G(b)));
	printf ("\nSEGUNDO CASO");
        printf("\nEl resultado es  %.10f cuando n vale %i\n" , resultado, n);
        suma = 0.0;
	//FIN SEGUNDO CASO

	//INICIO TERCER CASO
        n = 4;
        a = 2;
        b = 3;

        for (i=1; i<n; i++)
        {
                posicion = a + (i*((b-a)/n));
                suma = 2.0*H(posicion) + suma;
        }
        resultado = (((b-a)/(2.0*n))*(H(a)+suma+H(b)));
        printf ("\nTERCER CASO");
        printf("\nEl resultado es  %.10f cuando n vale %i\n" , resultado, n);
        suma = 0.0;
        //FIN TERCER CASO

	//INICIO CUARTO CASO
        n = 6;
        a = 0;
        b = 0.6;

        for (i=1; i<n; i++)
        {
                posicion = a + (i*((b-a)/n));
                suma = 2.0*J(posicion) + suma;
        }
        resultado = (((b-a)/(2.0*n))*(J(a)+suma+J(b)));
        printf ("\nCUARTO CASO");
        printf("\nEl resultado es  %.10f cuando n vale %i" , resultado, n);
        suma = 0.0;
        //FIN CUARTO CASO


        return;
}

int main()
{
        float resultado;
        system ("clear");
        formula();
        printf ("\n");
        return 0;
}

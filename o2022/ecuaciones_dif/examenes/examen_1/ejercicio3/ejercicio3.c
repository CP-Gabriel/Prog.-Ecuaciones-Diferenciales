#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x) (0.2 + (25.0*(x)) - (200.0*(pow(x,2))) + (675.0*(pow(x,3))) - (900.0*(pow(x,4))) + (400.0*(pow(x,5))))

/**
* @brief Estafuncion resulve una integral por la regla del trapezoide.
* @param a es un float que guarda la posicion en limite inferior de la integral.
* @param b es un float que guarda la posicion en limite superior de la integral.
* @return resultado es un float.
*/

float trapezoide(float a, float b)
{
        float posicion = 0.0;
        float suma = 0.0;
        float resultado;
        int i;
	int n = 4;

	for (i=1; i<n; i++)
	{
		posicion = a + (i*((b-a)/n));
		suma = 2.0*F(posicion) + suma;
	}
	resultado = (((b-a)/(2.0*n))*(F(a)+suma+F(b)));
	suma = 0.0;
        return resultado;
}

/**
* @brief Estafuncion resulve una integral por la regla de simpson de 1/3.
* @param a es un float que guarda la posicion en limite inferior de la integral.
* @param b es un float que guarda la posicion en limite superior de la integral.
* @return resultado es un float.
*/

float simpson_1_3 (float a, float b)
{
        float h = (b-a)/2;
        float resultado;

        resultado = h/3 * ((F(a)) + (4.0 * (F((a+b)/2))) + (F(b)));
        return resultado;
}

/**
* @brief Estafuncion resulve una integral por la regla de simpson de 3/8.
* @param a es un float que guarda la posicion en limite inferior de la integral.
* @param b es un float que guarda la posicion en limite superior de la integral.
* @return resultado es un float.
*/

float simpson_3_8 (float a, float b)
{
        float resultado;

	resultado = ((b-a)/8) * ((F(a)) + (3.0 * (F(((2.0*a)+b)/3))) + (3.0 * (F(((2.0*b)+a)/3))) + (F(b)));
        return resultado;
}

/**
* @brief Este programa calcula una integral con los metodos del trapezoide, simposon 1/3 y simpson 3/8, ademas calcula el
* @	 error en los resultados.
*/
int main()
{
        float a = 0;
        float b = 0.8;
        float resultado;
	//SE UTILIZO WOLFRAM PARA CALCULAR EL RESULTADO REAL
	float resul_real = 1.64053;
	float error;

        system ("clear");

	//TRAPEZOIDE
        printf ("\nEl resultado de la integral con la regla del trapezoide es: %f", trapezoide(a, b));
	error = 100*((resul_real - (trapezoide(a, b)))/resul_real);
        printf ("\nEl error porcentual obtenido con la regla del trapezoide fue de:  %f\n", error);
	//

	//SIMPSON 1/3
        printf  ("\nEl resultado de la integral con la regla de simpson de 1/3: %f", simpson_1_3 (a, b));
	error = 100*((resul_real - (simpson_1_3 (a, b)))/resul_real);
        printf ("\nEl error porcentual obtenido con la regla de simpson de 1/3:  %f\n", error);
	//

	//SIMPSON 3/8
	printf  ("\nEl resultado de la integral con la regla de simpson de 3/8: %f", simpson_3_8 (a, b));
	error = 100*((resul_real - (simpson_3_8 (a, b)))/resul_real);
        printf ("\nEl error porcentual obtenido con la regla de simpson de 3/8:  %f\n", error);
	//

        printf ("\n");
        return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x) (pow((((3.0*x)-1)/((pow(x,2))+3)),2))

/**
* @brief Esta funcion calcula la deriva de progresiva
* @param ta es un float con el valor a evaluar de x.
* @param h es un float con el valor de h que se tomara para el limite.
* @rerturn va a hacer un float con el valor de la ecuacion realizada.
*/
float df_Progresiva(float ta, float h)
{
        float t = ta + h;
        return (F(t) - F(ta))/h;
}

float segunda_df_Progresiva(float ta, float h)
{
        float t = ta + h;

	//La formula obtenida viene al usar la formula de limites para la formula progresiva ocupandola para cada termino del numerador
        return (df_Progresiva(t,h) - df_Progresiva(ta,h))/h;
}


/**
* @brief Esta funcion calcula la deriva de regresiva
* @param ta es un float con el valor a evaluar de x.
* @param h es un float con el valor de h que se tomara para el limite.
* @rerturn va a hacer un float con el valor de la ecuacion realizada.
*/
float df_Regresiva(float ta, float h)
{
        float t = ta - h;
        return (F(ta) - F(t))/h;
}
float segunda_df_Regresiva(float ta, float h)
{
        float t = ta - h;

	//La formula obtenida viene al usar la formula de limites para la formula regresiva ocupandola para cada termino del numerador
        return (df_Regresiva(ta,h) - df_Regresiva(t,h))/h;
}

/**
* @brief Esta funcion calcula la deriva de central.
* @param ta es un float con el valor a evaluar de x.
* @param h es un float con el valor de h que se tomara para el limite.
* @rerturn va a hacer un float con el valor de la ecuacion realizada.
*/
float df_Central(float ta, float h)
{
        float t = ta + h;
        float t2 = ta - h;

        return (F(t) - F(t2))/(2*h);
}
float segunda_df_Central(float ta, float h)
{
        float t = ta + h;
        float t2 = ta - h;

	//La formula obtenida viene al usar la formula de limites para la formula central ocupandola para cada termino del numerador
        return (df_Central(t,h) - df_Central(t2,h))/(2*h);
}


/**
* @brief Este programa calcula la deriva progresiva, regresiva y central de una ecuacion
*/
int main()
{
        float x = 1;
        float h = 0.01;
	float reslt, reslt2, reslt3;
	float error, error2, error3;
	//SE UTILIZO WOLFRAM PARA SABER EL RESULTADO REAL
	float real = -.25;

	system ("clear");
        printf ("\nRESULTADO REAL EVALUANDO A X = 1 ES %f\n", real);

	reslt = segunda_df_Progresiva(x,h);
        printf ("\nEl valor de la derivada progresiva es de: %f", reslt);
	error = fabs((100*(reslt-real)/real));
        printf ("\nEl error obtenido en la derivada progresiva es: %f\n", error);

	reslt2 = segunda_df_Regresiva(x,h);
        printf ("\nEl valor de la derivada regresiva es de: %f", reslt2);
	error2 = fabs(100*((reslt2-real)/real));
        printf ("\nEl error obtenido en la derivada regresiva es: %f\n", error2);

	reslt3 = segunda_df_Central(x,h);
        printf ("\nEl valor de la derivada central es de: %f", reslt3);
	error3 = fabs(100*((reslt3-real)/real));
        printf ("\nEl error obtenido en la derivada central es: %f\n", error3);


	if ((error<error2)&&(error<error3))
	{
		printf ("\nEl mejor metodo para calcular la segunda derivada es la derivada progresiva.");
	}

	if ((error2<error)&&(error2<error3))
        {
                printf ("\nEl mejor metodo para calcular la segunda derivada es la derivada regresiva.");
        }

	if ((error3<error)&&(error3<error2))
        {

                printf ("\nEl mejor metodo para calcular la segunda derivada es la derivada central.");
        }

        printf ("\n");
        return 0;
}

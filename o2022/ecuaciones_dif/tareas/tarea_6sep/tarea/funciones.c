#include "tipos.h"

//Inicio Funciones
//EJERCICIO 1
//#define F(x) (((9.0*(x))-2))

//EJERCICIO 2
//#define F(x) (2+(8.0*x)-(5.0*(pow(x,2))))

//EJERCICIO 3
//#define F(x) (1/(x-2))

//EJERCICIO 4
//#define F(x) (sqrt((3.0*x)+1))
//#define F(x) (pow((3.0*x+1),0.5))

//EJERCICIO 5
//#define F(x) (pow(x,3)+(x))

//EJERCICIO 6
//#define F(x) ((10*(pow(x,2)))+(9.0*x)-4)

//EJERCICIO 7
//#define F(x) (((8*(pow(x,2)))-(6.0*x)+11)/(x-1))

//EJERCICIO 8
//#define F(x) ((8-(x)+(3*(pow(x,2))))/(2-(9.0*x)))

//EJERCICIO 9
//#define F(x) (pow(((5.0*x)-4),-2))

//EJERCICIO 10
//#define F(x) (((3.0*x)-1)/(pow(x,2)))

//EJERCICIO 11
//#define F(x) ((pow(((3.0*x)-8),-2))*(pow(((7.0*(pow(x,2)))+4),-3)))

//EJERCICIO 12
#define F(x) (pow(((6.0*x)-7),3))*pow(((8*(pow(x,2)))+9),2)
//Fin funciones

//Variables constantes
#define incrementoInterseccion 0.01
#define incrementoPendiente 1000

/**
* @
*/

float dx(float ta, float h)
{
	float t = ta + h;
	return (F(t) - F(ta))/h;
}

/**
* @
*/

float pendienteInfinito()
{
//	float pendiente;
	float t;
	float a = 0.0;
	float h = 0.001;

	float df = 0.0;
	float df2 = 0.0;
	int encontrado = 0;

	t = a + h;

	do
	{
		df2 = df;
//		df = dx(a,h);
		df = (F(t)-F(a))/h;

		if (df2 == df)
		{
			a = a + incrementoPendiente;
			encontrado++;
		}
	}
	while (encontrado < 10);

	return df;
}

/**
* @
*/

int intersecciones(float *x, float *y)
{
	int i = 0;
	float t = 0.0;
	float temp;
	float k = 0.0;
	int a = 0;

	*y = F(0);

	do
	{
		i++;
		temp = k;
		k = F(t);

		if(temp == k)
		{
			t = t + incrementoInterseccion;
		}

		if((k > temp)&&((k != 0)||(abs(k) < 0.1))&&(k > 0))
                {
                        t = t - (incrementoInterseccion * 2);
                }

		if((k < temp)&&((k != 0)||(abs(k) < 0.1))&&(k < 0))
                {
                        t = t + (incrementoInterseccion * 2);
                }

                if(k == 0 || abs(k) < 0.1)
                {
                        *x = t;
			a = t;
                }

		if(i > 10000)
                {
			return 0;
                }
	}
	while(a == 0);
	return 1;
}

/*
*
*/

int puntosCriticos(float *puntoCritico)
{
	float temp = 0.0;
	float y = 0.0;
	float t = 0.0;
	int i = 0;
	int a = 0;

        do
        {
                i++;
                temp = y;
                y = F(t);

                if(temp == y)
                {
                        t = t + incrementoInterseccion;
                }

                if(abs(y) > abs(temp))
                {
                        t = t + incrementoInterseccion;
                }

                if(abs(y) < abs(temp))
		{
			a = 1;
                        *puntoCritico = t + (incrementoInterseccion/2);
                }

                if(i > 10000)
		{
                        break;
                }
        }
        while(a == 0);

        i = 0;
        temp = 0.0;
        y =0.0;
        t = 0.0;

        do
        {
                i++;
                temp = y;
                temp =F(t);

                if(temp == y)
                {
                        t = t - incrementoInterseccion;
                }

                if(abs(y) > abs(temp))
                {
                        t = t - incrementoInterseccion;
                }

                if(abs(y) < abs(temp))
                {
                        a = 1;
                        *puntoCritico = (t - (incrementoInterseccion / 2));
                }
                if(i > 10000)
                {
                        break;
                }
        }
        while(a == 0);

        if(a == 0)
        {
                return 0;
        }
        return 1;
}

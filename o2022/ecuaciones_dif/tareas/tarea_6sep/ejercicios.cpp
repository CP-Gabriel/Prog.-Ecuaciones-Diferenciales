//BIBLIOTECAS
#include <iostream>
#include <math.h>

using namespace std;

//CONSTANTES
#define incrementoInterseccion 0.01
#define incrementoPendiente 1000

//FUNCIÓN MATEMÁTICA
//#define F(x) (9*(x)-2)
//#define F(x) (2+(8*x)-(5*pow(x,2)))
//#define F(x) 1/(x-2)
//#define F(x) pow((3*x+1), 0.5)
//#define F(x) (pow(x,3))+x
//#define F(x) (10*(pow(x,2)))+(9*x)-4
//#define F(x) ((8*(pow(x,2)))-(6*x)+11)/(x-1)
//#define F(x) (pow((5*x)-4,-2))
//#define F(x) ((3*x)-1)/(pow(x,2))
//#define F(x) pow((3*x)-8, -2)*pow((7*(pow(x,2))+4),-3)
#define F(x) pow((6*x)-7, 3)*pow((8*(pow(x,2))+9),2)

//FUNCIONES
/**
**/

float derivarFuncion(float a, float h)
{
	float df, t=a+h;

	df=(F(t)-F(a))/h;

	return df;
}

/**
**/

float encontrarPendienteAlInfinito(void)
{
	float pendiente=0.0, t, a=0.0, h=0.00001;
	double df=0.0, dfTemporal=0.0;
	int coincidencia=0;
	t=a+h;

	do
	{
		dfTemporal=df;
		df=(F(t)-F(a))/h;

		if(dfTemporal==df)
		{
			a=a+incrementoPendiente;
			coincidencia++;
		}
	}
	while(coincidencia<10);
	pendiente=df;

	return pendiente;
}

/**
**/

int encontrarIntersecciones(float *interX, float *interY)
{
	int vueltas=0;
	float i=0.0;
	float valor_temporal, valorY=0;
	bool encontrado=false;
	*interY=F(0);

	do
	{
		vueltas++;
		valor_temporal=valorY;
		valorY=F(i);
		if(valor_temporal==valorY)
		{
			i=i+incrementoInterseccion;
		}
		if((valorY>valor_temporal)&&((valorY!=0)||(abs(valorY)<0.1))&&(valorY>0))
		{
			i=i-(incrementoInterseccion*2);
		}
                if((valorY<valor_temporal)&&((valorY!=0)||(abs(valorY)<0.1))&&(valorY<0))
		{
			i=i+(incrementoInterseccion*2);
		}
		if(valorY==0 || abs(valorY)<0.1)
		{
			*interX=i;
			encontrado=true;
		}
		if(vueltas>10000)
		{
			return 0;
		}
	}
	while(encontrado==false);

	return 1;
}

/**
**/

int encontrarPuntosCriticos(float *puntoCritico)
{
        float valor_temporal=0.0, valorY=0.0, i=0.0;
	int vueltas=0;
	bool encontrado=false;

	do
	{
		vueltas++;
                valor_temporal=valorY;
     		valorY=F(i);
		if(valor_temporal==valorY)
		{
			i=i+incrementoInterseccion;
		}
		if(abs(valorY)>abs(valor_temporal))
		{
                        i=i+incrementoInterseccion;
		}
		if(abs(valorY)<abs(valor_temporal))
		{
			encontrado=true;
			*puntoCritico=i+(incrementoInterseccion/2);
                }
		if(vueltas>10000)
		{
			break;
		}
	}
	while(encontrado==false);

	vueltas=0;
	valor_temporal=0.0;
	valorY=0.0;
	i=0.0;
        do
	{
                vueltas++;
                valor_temporal=valorY;
                valorY=F(i);
                if(valor_temporal==valorY)
		{
                        i=i-incrementoInterseccion;
                }
                if(abs(valorY)>abs(valor_temporal))
		{
                        i=i-incrementoInterseccion;
                }
                if(abs(valorY)<abs(valor_temporal))
		{
                        encontrado=true;
                        *puntoCritico=i-(incrementoInterseccion/2);
                }
                if(vueltas>10000)
		{
                        break;
                }
        }
	while(encontrado==false);

	if(encontrado==false)
	{
		return 0;
	}

	return 1;
}

//MAIN
int main(void)
{
	float interseccionX, interseccionY, puntoCritico;
        cout<<endl<<"-------------------------------------"<<endl;
	cout<<endl<<"--PUNTOS ESPECIFICOS DE UNA FUNCIÓN--"<<endl;
        cout<<endl<<"-------------------------------------"<<endl;
	cout<<endl<<"La pendiente en cero es: "<<derivarFuncion(0,0.00001)<<endl;
	cout<<"La pendiente en el infinito es: "<<encontrarPendienteAlInfinito()<<endl;;
	encontrarIntersecciones(&interseccionX, &interseccionY);
	cout<<"La interseccion en \"X\" es: "<<interseccionX<<endl<<"La interseccion en \"Y\" es: "<<interseccionY<<endl;

	if(encontrarPuntosCriticos(&puntoCritico)==1)
	{
		cout<<"El punto critico mas cercano a cero es: "<<puntoCritico<<endl;
	}
	else
	{
                cout<<"NO HAY PUNTOS CRITICOS"<<endl;
	}
        cout<<endl<<"-------------------------------------"<<endl;

	return 0;
}

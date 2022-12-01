#include <iostream>
#include <cmath>
using namespace std;

//9
#define E(x)((5*x)-4)
#define F(t)(pow(t,-2))

float df(float ta, float h)
{
	float t = ta+h;
	return (F(E(t))-F(E(ta)))/h;
}

int main()
{
	//primer alcance: puntos especificos de pendiente
	float a=0.0f;
	float h=0.001f;
	float r, max=-100000.0f, min=100000.0f;
	int i;

	cout << "Pendiente en 0=" << df(a,h) << endl;
	a=INFINITY;

	cout << "Pendiente en infinito=" << df(a,h) << endl;
	cout << "Aproximacion -10 a 10" << endl;

	//segundo alcance; donde cambia el signo?
	for (float a=-10; a<10; a+=0.1)
	{
		r=df(a,h);
		//cout << a << " = " << r << endl;

		//Comparacion para cambio de signo, Cambiar operador si resulta en -10 (< por > y viceversa)
		if(r<0)
		{
			cout << "La pendiente cambia de signo en=" << a << endl;
			//comprobacion asintota

			if(abs(r) > 100000)
        		{
				cout << a << " es una asintota" << endl;
				break;
			}
		}
	}

	//Maximo, minimo y cruce en Y
	for (float a=-10; a<10; a+=0.1)
	{
		r=F(E(a));
		//cout << a << " = " << r << endl;

		if(min>r)
		{
			min=r;
		}

      		if(max<r)
		{
			max=r;
		}

		if(a<0.08 && a>-0.08)
		{
			cout << "El cruce en y es en =" << r << endl;
		}
	}

	//Raiz y cruce en X, Cambiar valor de a para acercar a raiz de cada formula
	a=0.1f;

	for(i=0;i<100000;i++)
	{
		r=a-(F(E(a))/df(a,0.01));
		//cout << "X" << i+2 << "=" << r << endl;
		//cout << "r=" << r << " a=" << a << endl;

		if(isunordered(r, a)==true)
		{
			cout << "No tiene raices o aproximacion muy lejana"<< endl;
			break;
		}

		else if(trunc(a*1000)==trunc(r*1000))
		{
			cout << "La raiz/cruce en x es en=" << r << endl;
			break;
		}
		a=r;
	}
	cout << "Maximo local=" << max << endl;
	cout << "Minimo local=" << min << endl;

	return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

#define F(x) (1/(1+x))

//Regla de simpson de 1/3
float simpsonPar (float a, float b)
{
 b = 2;
 a = 0.5;
  float i;
  float suma=0.0, d;

  suma=((b-a)/6*(F(a)+(4*F((a+b)/2))+F(b)));
  return suma;
}

//Trapecio por la derecha
float trapecio (float a, float b)
{
  float i;
  float suma=0.0, d;

  d=(b-a)/8;

  for (i=a;i<b;i+=d)
    {
      suma+= F(i+d);
    }
  suma= (d/2)*(F(a)+(2*suma)+F(b));
  return suma;
}

//Aproximacion por suma al centro
float sumatoria (float a, float b)
{
  float i;
  float suma=0.0, d;

  d=(b-a)/8;

  for (i=a;i<b;i+=d)
    {
      suma+= F(i+(d/2))*d;
    }
  return suma;
}

int main()
{
//  float ini=0.0;
  float ini=0.5;
//  float fin=3.0;
  float fin=2.0;
  float result = simpsonPar(ini,fin);
  cout << "La respuesta por simpson es " << result << endl;
  result = trapecio(ini,fin);
  cout << "La respuesta por trapecio es " << result << endl;
  result = sumatoria(ini,fin);
  cout << "La respuesta por aproximiacion al centro es " << result << endl;
  return 0;
}

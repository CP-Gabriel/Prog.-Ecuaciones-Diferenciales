#include <stdio.h>
#include <math.h>

#define F(t)(pow(t,2)-6.0*t)

float df(float ta, float h)
{
        float t = ta +h;
        return (F(t) - F(ta))/h;
}

int main()
{
	float a = 0.0f;
	float h = 0.01f;
	printf ("\nPara t=0: %f", df(a,h));
	a = 4.0f;
	printf ("\nPara t=4: %f", df(a,h));
	for(float a=0; a<5; a+=0.5)
	{
		printf ("\nPara a= %f  %f", a, df(a,h));
	}
	printf ("\n");
	return 0;
}

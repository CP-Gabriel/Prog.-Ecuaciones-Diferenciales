#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x)(cos(x))

float df_Progresiva(float ta, float h)
{
        float t = ta + h;
        return (F(t) - F(ta))/h;
}

float df_N_Progresiva(float x, float h, int n)
{
	if (n == 0)
	{
		return 1;
	}

	else
	{
		return (((df_N_Progresiva(x, h, (n-1)))-(df_Progresiva(x, h)))/h);
	}
}

int main()
{
        float a = 0.0f;
        float h = 0.01f;
	int n = 2;

	printf ("\nDERIVADA: %f",  df_N_Progresiva(a, h, n));
        printf ("\n");
        return 0;
}

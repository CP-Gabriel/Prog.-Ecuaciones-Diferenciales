#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(t)(pow(t,2)-7)

float df(float ta, float h)
{
        float t = ta + h;
        return (F(t) - F(ta))/h;
}

float resultados(float min, float sust, float derv)
{
	return (min - (sust/derv));
}

int main(void)
{
	float reslt[8];
	float h = 0.01f;
	float min, max;
	int resultado, i, j;
	float resltmin, resltmax;
	system("clear");
	for (i=0; i<6; i++)
	{
		resultado = F(i);
	if (resultado < 0)
		{
			resltmin = resultado;
			min = i;
		}
		if (resultado > 0)
                {
			resltmax = resultado;
                        max = i;
			break;
                }
//		printf ("\nRESULTADO: %i", resultado);
	}
//	printf ("\nMIN: %i\tMAX: %i", min, max);
//	printf ("\nRESULTADO MIN: %i", c);
//	printf ("\nRESULTADO MAX: %i", d);

//	float derv = df(min,h);
//	printf ("\nDERIVADA: %f", derv);

//	float e;
	reslt[0] = min;
	printf ("\nRESULTADO: %.2f", reslt[0]);
	for (j=1; j<=8; j++)
	{
/*		printf ("\nMIN: %f", min);
	        printf ("\nSUSTITUCION: %f", F(min));
	        printf ("\nDERIVADA: %f", df(min,h));*/

		reslt[j] = resultados(min, F(min), df(min,h));
		printf ("\nRESULTADO: %f", reslt[j]);
		min = reslt[j];
	}
/*	e = resultados(min, c, derv);
	printf ("\nRESULTADO FINAL %.2f", e);*/

//	e = resultados(min, F(min), df(min,h));
/*	printf ("\nMIN: %i", min);
	printf ("\nRESUL MIN: %f", c);
	printf ("\nDERIVADA: %f", derv);
	printf ("\nRESULTADO FINAL %.2f", e);*/

	printf ("\n\n");
	return 0;
}

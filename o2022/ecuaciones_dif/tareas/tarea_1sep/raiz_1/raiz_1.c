#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(t)(pow(t,3)-3.0*t+1)

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

/*        for (i=1; i<=8; i++)
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
        }*/

//	printf ("\nMIN: %.0f\tMAX: %.0f", min, max);

//      float derv = df(min,h);
//      printf ("\nDERIVADA: %f", derv);
	min = 1.5;
        reslt[0] = min;

/*	printf ("\nMIN: %f", min);
	printf ("\nSUSTITUCION: %f", F(min));
	printf ("\nDERIVADA: %f", df(min,h));*/

//        printf ("\nRESULTADO: %.2f", reslt[0]);
        for (j=1; j<=8; j++)
        {
/*		printf ("\nMIN: %f", min);
                printf ("\nSUSTITUCION: %f", F(min));
                printf ("\nDERIVADA: %f", df(min,h));*/

                reslt[j] = resultados(min, F(min), df(min,h));
                printf ("\nRESULTADO: %f", reslt[j]);
                min = reslt[j];
//	        printf ("\n\n");
        }

        printf ("\n\n");
        return 0;
}

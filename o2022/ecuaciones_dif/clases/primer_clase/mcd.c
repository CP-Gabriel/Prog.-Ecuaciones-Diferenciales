#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int num1, num2, c, b;
	int temporal;
	double time_spent = 0.0;
	int a = 0;

	clock_t begin = clock();

	printf ("ALEATORIO: %i\n", rand());

	printf ("\nIngresa el dividendo: ");
	scanf ( " %i", &num1);
	printf ("\nIngresa el divisor: ");
        scanf ( " %i", &num2);
	c = num1;
	b = num2;

	while (num2 != 0)
	{
		a++;
	        temporal = num2;
	        num2 = num1 % num2;
        	num1 = temporal;
	}

	clock_t end = clock();
	printf ("\nEl mcd de %i y %i es: %i", c, b, temporal);
	time_spent += (double)(end - begin);
	printf ("\nEl numero de iteraciones realizadas %i", a);
	printf ("\nEl tiempo transcurrido para la ejecucion del programa fue de %f segundos\n", time_spent);
	printf ("\n");
	return 0;
}

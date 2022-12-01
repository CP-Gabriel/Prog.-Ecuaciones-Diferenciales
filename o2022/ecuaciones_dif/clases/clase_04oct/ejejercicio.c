#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int number;

	system ("clear");
	for (int i=0; i<100; i++)
	{
		number = rand() % 100;
		printf ("%i", number);
		number = rand() % 100;
		printf (",%i\n", number);
	}
	return 0;
}

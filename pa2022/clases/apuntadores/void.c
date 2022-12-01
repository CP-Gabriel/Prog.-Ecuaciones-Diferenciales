#include <stdio.h>

int main(void)
{
	void *p;
	int numero = 1;
	char letra = 'A';

	p = &numero;
	printf ("\nEl valor de la variable numero es: %i y el valor al que apunta p es: %i\n", numero, *((int *)p));
	p = &letra;
	printf  ("\nEl valor de la varible letra es: %c y el valor al que apunta p es: %c\n", letra, *((char *)p));
	printf ("\n");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char cuenta[30];
	char contrasena[30];

	printf ("\nIngresa tu cuenta: ");
	scanf (" %[^\n]", cuenta);
	printf ("\nIngresa tu contraseña: ");
	scanf (" %[^\n]", contrasena);

	printf ("\nCUENTA: %s\n", cuenta);
	printf ("\nCONTRASEÑA: %s\n", contrasena);
	return 0;
}

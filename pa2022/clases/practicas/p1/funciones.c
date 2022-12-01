/**
* @
*/

#include "misDef.h"

extern void convertirHexadecial(char arr1[], char arr2[], char arr3[], char *argv[], int tam)
{
	int i;
	char dat1[50];
	char dat2[50];
	char dat3[50];

	for (i=1; i<=tam; i++)
	{
		if (strcmp(argv[3], "hexadecimal") == 0)
		{
			//strcpy (dat1, arr1[i-1]);
			sscanf (arr1, " %s", dat1);
			printf ("X %s : \n", dat1);
		}
		/*
		if (strcmp(argv[4], "hexadecimal") == 0)
	        {
			sscanf (arr2[i], "%s", dat2);
			printf ("X %s : \n", dat2);
	        }
	        if (strcmp(argv[5], "hexadecimal") == 0)
	        {
			sscanf (arr3[i], "%s", dat3);
			printf ("X %s : \n", dat3);
        	}
		*/
	}
	return;
}

extern void convertirBinario(char *arr1[], char *arr2[], char arr3[], char *argv[], int tam)
{
	int i, x;
	for (i=0; i<=(tam-1); i++)
	{
		if (strcmp(argv[3], "binario") == 0)
	        {
			x = sizeof(arr1[i]);
			printf ("X %i : \n", x);
	        }
		if (strcmp(argv[4], "binario") == 0)
	        {
			x = sizeof(arr2[i]);
			printf ("X %i : \n", x);
	        }
		if (strcmp(argv[5], "binario") == 0)
	        {
			x = sizeof(arr3[i]);
			printf ("X %i : \n", x);
	        }
	}
	return;
}

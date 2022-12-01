#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct frases
{
	char palabra[50];
        struct frases *next, *pass;
};

typedef struct frases tipoFrase;


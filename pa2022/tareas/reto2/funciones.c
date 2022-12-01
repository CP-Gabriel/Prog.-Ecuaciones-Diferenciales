#include "tipos.h"

extern tipoFrase *pushLIFO(char palabras[], tipoFrase *aux)
{
        tipoFrase *nuevo;
        nuevo = (tipoFrase *)malloc(sizeof(tipoFrase));
        if (nuevo == NULL)
        {
                printf ("\nMemorira no disponible.\n");
                exit(1);
        }
	strcpy(nuevo->palabra, palabras);
        if (aux == NULL)
        {
                aux = nuevo;
                nuevo->next = NULL;
        }
        else
        {
                nuevo->next = aux;
                aux = nuevo;
        }
        return aux;
}

/*ctipoFrase *pop(tipoFrase *aux)
{
        tipoFrase *borrar;
        if(aux != NULL)
        {
                borrar = aux;
                aux = aux->next;
                free(borrar);
        }
        else
        {
                printf ("\nLa lista esta vacia\n");
        }
        return aux;
}*/

/*extern tipoFrase *parte1(tipoFrase *aux)
{
	tipoFrase *borrar;
	char comp[50];
	int tam;

        while (aux != NULL)
        {
		strcpy(comp, aux->palabra);
		tam = strlen(comp);
		if (comp[tam-1] == 'o')
		{
//			borrar = aux;
//			free(borrar);
//			aux = pop(aux);
			aux = aux->next;
		}
		else
		{
			borrar = aux;
                        free(borrar);
//			aux = pop(aux);
			aux = aux->next;
 		}
		aux = aux->next;
        }
        return aux;
}*/

//extern tipoFrase *parte1(tipoFrase *aux)
void parte1(tipoFrase *aux)
{
        tipoFrase *borrar;
        char comp[50];
        int tam;

        while (aux != NULL)
        {
                strcpy(comp, aux->palabra);
                tam = strlen(comp);
                if (comp[tam-1] == 'o')
                {
                        aux = aux->next;
                }
                else
                {
//                        borrar = aux;
//                        free(borrar);
//                        aux = aux->next;

			borrar = aux;
	                aux = aux->next;
	                free(borrar);

/*                        aux = pop(aux);
			aux = aux->next;*/
                }
        }
        return;
}

void recorrerLista(tipoFrase *aux)
{
	do
//	while (aux != NULL)
        {
                printf ("\nPALABRA: %s\n", aux->palabra);
		aux = aux->next;
        }
	while (aux->next != NULL);
	return;
}

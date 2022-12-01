/**
* @file
* @brief
* @date
* @author
*/

#include "tipos.h"

extern tipoRegistro *pushCircular(char nom[], char apell[], char cp[], bool covid, char siOno, tipoRegistro *refInicio)
{
        tipoRegistro *aux, *new;
        new = (tipoRegistro *)malloc(sizeof(tipoRegistro));
        if (new == NULL)
        {
                printf ("\nMemorira no disponible.\n");
                exit(1);
        }
        strcpy(new->nombre, nom);
        strcpy(new->apellido, apell);
        strcpy(new->codigop, cp);
	new->diagnostic = siOno;

	if (new->diagnostic == 's')
        {
		covid = true;
        }
        else
        {
        	covid = false;
        }
        new->diagnostico = covid;

        if (refInicio == NULL)
        {
                refInicio = new;
                new->next = refInicio;
        }
        else
        {
                aux = refInicio;
                while(aux->next != refInicio)
                {
                        aux->next = refInicio;
                }
                aux->next = new;
                new->next = refInicio;
        }
        return refInicio;
}

/**
* @
*/

extern void recorrerCircular(tipoRegistro *aux)
{
        tipoRegistro *ref;
        ref = aux;
        if (ref == NULL)
        {
                printf ("\nLista vacia.\n");
        }
        else
        {
                do
                {
			printf ("\nNombre: %s\t Apellido: %s\t Codigo Postal: %s\tCovid: %c\n", aux->nombre, aux->apellido, aux->codigop, aux->diagnostic);
			//printf ("\nNombre: %s\tApellido: %s\tCódigo Postal: %s\n", aux->nombre, aux->apellido, aux->codigop);
                        aux = aux->next;
                }
                while (aux != ref);
		
/*		while (aux != NULL)
                {
                        printf ("\nNombre: %s\t Apellido: %s\t Codigo Postal: %s\tCovid: %c\n", aux->nombre, aux->apellido, aux->codigop, aux->diagnostic);
//                      printf ("\nNombre: %s\tApellido: %s\tCódigo Postal: %s\n", aux->nombre, aux->apellido, aux->codigop);
                        aux = aux->next;
                }*/
        }
        return;
}

/**
* @
*/

extern tipoRegistro *insertarFIFO(char nom[], char apell[], char cp[], bool covid, char siOno, tipoRegistro *aux)
{
        tipoRegistro *new, *fin;
        fin = aux;
        new = (tipoRegistro *)malloc(sizeof(tipoRegistro));
        if (new == NULL)
        {
                printf ("\nMemoria no disponible.\n");
                exit(1);
        }

	strcpy(new->nombre, nom);
        strcpy(new->apellido, apell);
        strcpy(new->codigop, cp);
	new->diagnostic = siOno;
	
        if (new->diagnostic == 's')
        {
                covid = true;
        }
        else
        {
                covid = false;
        }
        new->diagnostico = covid;
	
        if (aux == NULL)
        {
                aux = new;
                new->next = NULL;
        }
        else
        {
                while (fin->next != NULL)
                {
                        fin = fin->next;
                }
                fin->next = new;
                new->next = NULL;
        }
        return aux;
}

/**
* @
* @
*/

extern void recorrerLista(tipoRegistro *aux)
{
        if (aux == NULL)
        {
                printf ("No disponible");
        }
        else
        {
                while (aux != NULL)
                {
                	printf ("\nNombre: %s\t Apellido: %s\t Codigo Postal: %s\tCovid: %c\n", aux->nombre, aux->apellido, aux->codigop, aux->diagnostic);
//			printf ("\nNombre: %s\tApellido: %s\tCódigo Postal: %s\n", aux->nombre, aux->apellido, aux->codigop);
                        aux = aux->next;
                }
		
/*		do
                {
                        printf ("\nNombre: %s\t Apellido: %s\t Codigo Postal: %s\tCovid: %c\n", aux->nombre, aux->apellido, aux->codigop, aux->diagnostic);
                        //printf ("\nNombre: %s\tApellido: %s\tCódigo Postal: %s\n", aux->nombre, aux->apellido, aux->codigop);
                        aux = aux->next;
                }
                while (aux != NULL);*/
        }
	return;
}

/**
* @
*/

extern void opcionR(tipoRegistro *aux)
{
        tipoRegistro *ref;
        ref = aux;
	int opcion, modificar, accion;
	int i=1;
        if (ref == NULL)
        {
                printf ("\nLista vacia.\n");
        }
        else
        {
                do
                {
			i++;
			do
			{
				system("clear");
				printf ("\nPaciente %i", i-1);
				if (accion == 1)
				{
					printf ("\nREGISTRO ACTUALIZADO");
				}
	                	printf ("\n1.Nombre: %s\t 2.Apellido: %s\t 3.Codigo Postal: %s\t4.Covid: %c\n", aux->nombre, aux->apellido, aux->codigop, aux->diagnostic);
				printf ("\n1.Si    0.No");
				if (accion == 1)
				{
					accion = 0;
					printf ("\nDesea modificar otra cosa: ");
					scanf (" %i", &opcion);
				}
				else
				{
					accion = 0;
					printf ("\nDesea modificar algo: ");
					scanf (" %i", &opcion);
				}
				if (opcion == 1)
				{
					accion = 1;
					printf ("\nIngresa el número de lo que quires modificar: ");
					scanf (" %i", &modificar);
					if (modificar == 1)
					{
						printf ("\nMODIFICAR NOMBRE");
						printf ("\nIngresa el nuevo nombre: ");
						scanf (" %s", aux->nombre);
					}
					if (modificar == 2)
                                        {
                                                printf ("\nMODIFICAR APELLIDO");
                                                printf ("\nIngresa el nuevo apellido: ");
                                                scanf (" %s", aux->apellido);
                                        }
					if (modificar == 3)
                                        {
                                                printf ("\nMODIFICAR CODIGO POSTAL");
                                                printf ("\nIngresa el nuevo codigo postal: ");
                                                scanf (" %s", aux->codigop);
                                        }
					if (modificar == 4)
                                        {
                                                printf ("\nMODIFICAR DIAGNOSTICO");
                                                printf ("\nIngresa el nuevo diagnostico: ");
                                                scanf (" %c", &aux->diagnostic);
                                        }
				}
			}
			while (accion == 1);
//                      printf ("\nNombre: %s\t Apellido: %s\t Codigo Postal: %s\n", aux->nombre, aux->apellido, aux->codigop);
                        aux = aux->next;
                }
                while (aux != ref);
        }
	return;
}

/**
* @
* @
* @
*/

extern void opcionC(tipoRegistro *aux)
{
        tipoRegistro *ref;
        ref = aux;
        if (ref == NULL)
        {
                printf ("\nLista vacia.\n");
        }
        else
        {
                do
                {
			if (aux->diagnostico)
			{
				printf ("\nNombre: %s\t Apellido: %s\t Codigo Postal: %s\tCovid: %c\n", aux->nombre, aux->apellido, aux->codigop, aux->diagnostic);
			}
                        aux = aux->next;
                }
                while (aux != ref);
        }
	return;
}

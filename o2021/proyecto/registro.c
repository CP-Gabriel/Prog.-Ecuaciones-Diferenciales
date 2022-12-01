/*
* @file:
* @brief:
* @authors:
* @date:
*/

#include "misDef.h"

/*
* @brief:
* @authors: Gabriel Coronado/Segio Esquivel/ Sebastian Alanis.
* @date
* @param
* @return
*/

extern int registrarDatos(struct user usuario[], int *nuevoUsuario, int x)
{
	int tam, error;
	char aux[80];
	int i, j;
	for (i=x; i<(x+1); i++)
	{
		do
		{
			system ("clear");
			*nuevoUsuario=1;
			error=0;
			printf ("\nVENTA DE BICICLETAS\n");
			printf ("\nCREAR NUEVO USUARIO\n");
			printf ("\nDATOS PERSONALES\n");
			printf ("\n1.Ingrese su nombre o nombres: ");
			scanf (" %[^\n]", usuario[i].nombre.nombres);
			/*tam=strlen(usuario[i].nombre.nombres);
			strcpy(aux, usuario[i].nombre.nombres);
			for (j=0; j<tam; j++)
			{
				if ((aux[j]!=' ')&&((aux[i]<'A') || (aux[i]>'Z'))&&((aux[j]<'a') || (aux[j]>'z')))
				{
					error=1;
					printf (" \nerror: %i", error);
				}
			}*/
			printf ("\n2.Ingrese su apellido paterno: ");
			scanf (" %[^\n]", usuario[i].nombre.apellidop);
			/*tam=strlen(usuario[i].nombre.apellidop);
                        strcpy(aux, usuario[i].nombre.apellidop);
			for (j=0; j<tam; j++)
                        {
                                if (((aux[i]<'A') || (aux[i]>'Z'))&&((aux[j]<'a') || (aux[j]>'z')))
                        	{
                                        error=1;
					printf (" \nerror: %i", error);
                                }
                        }*/
			printf ("\n3.Ingresa tu apellido materno: ");
                        scanf (" %[^\n]", usuario[i].nombre.apellidom);
                        /*tam=strlen(usuario[i].nombre.apellidom);
                        strcpy(aux, usuario[i].nombre.apellidom);
                        for (j=0; j<tam; j++)
                        {
                                if (((aux[i]<'A') || (aux[i]>'Z'))&&((aux[j]<'a') || (aux[j]>'z')))
                                {
                                        error=1;
					printf (" \nerror: %i", error);
                                }
                        }*/
			printf ("\n4.Ingrese su clave de lector: ");
                        scanf (" %[^\n]", usuario[i].ife);
                        /*tam=strlen(usuario[i].ife);//Borrar este renglon al final
                        strcpy(aux, usuario[i].ife);//Borrar tam en for y poner 18
                        for (j=0; j<tam; j++)
                        {
                                if (((aux[i]<'0') || (aux[i]>'9'))&&((aux[i]<'A') || (aux[i]>'Z'))&&((aux[j]<'a') || (aux[j]>'z')))
                                {
                                        error=1;
					printf (" \nerror: %i", error);
                                }
                        }*/
			printf ("\n5.Ingrese su correo electrónico: ");
                        scanf (" %[^\n]", usuario[i].correo);
                        /*tam=strlen(usuario[i].correo);
                        strcpy(aux, usuario[i].correo);
                        for (j=0; j<tam; j++)
                        {
                                if ((aux[i]!='@')&&(aux[i]!='_')&&(aux[i]!='-')&&(aux[i]!='.')&&((aux[i]<'0') && (aux[i]>'9'))&&((aux[i]<'A') && (aux[i]>'Z'))&&((aux[j]<'a') && (aux[j]>'z')))
                                {
                                        error=1;
					printf (" \nerror: %i", error);
                                }
                        }*/
			if (error==1)
			{
				printf ("\nIngreso mal algún dato, por favor verifique sus datos e ingréselos nuevamente.");
			}
		}
		while (error==1);
	}
	return *nuevoUsuario;
}

/*
* @brief:
* @authors: Gabriel Coronado/Segio Esquivel/ Sebastian Alanis.
* @date
* @param
* @return
*/

extern int registrarDireccion(struct user usuario[], int *nuevoUsuario, int *datos, int x)
{
	int tam, error;
	char aux[80];
        int i, j;
        for (i=x; i<(x+1); i++)
        {
                do
                {
                        system ("clear");
                        error=0;
			*datos=1;
                        printf ("\nVENTA DE BICICLETAS\n");
                        printf ("\nCREAR NUEVO USUARIO\n");
			if (*nuevoUsuario==1)
			{
				*nuevoUsuario=0;
				printf ("\nTus datos personales están guardados.\n");
			}
                        printf ("\nDOMICILIO\n");
                        printf ("\n1.Ingrese su calle: ");
                        scanf (" %[^\n]", usuario[i].direccion.calle);
                        /*tam=strlen(usuario[i].direccion.calle);
                        strcpy(aux, usuario[i].direccion.calle);
                        for (j=0; j<tam; j++)
                        {
                                if ((aux[j]!=' ')&&((aux[i]<'0') || (aux[i]>'9'))&&((aux[i]<'A') || (aux[i]>'Z'))&&((aux[j]<'a') || (aux[j]>'z')))
                                {
                                        error=1;
                                        printf (" \nerror: %i", error);
                                }
                        }*/
			printf ("\n2.Ingrese su número interior: ");
                        scanf (" %[^\n]", usuario[i].direccion.numero);
                        /*tam=strlen(usuario[i].direccion.numero);
                        strcpy(aux, usuario[i].direccion.numero);
                        for (j=0; j<tam; j++)
                        {
                                if (((aux[i]<'0') || (aux[i]>'9'))&&((aux[i]<'A') || (aux[i]>'Z'))&&((aux[i]<'a') || (aux[i]>'z')))
                                {
                                        error=1;
                                        printf (" \nerror: %i", error);
                                }
                        }*/
			printf ("\n3.Ingrese su colonia: ");
                        scanf (" %[^\n]", usuario[i].direccion.colonia);
                        /*tam=strlen(usuario[i].direccion.colonia);
                        strcpy(aux, usuario[i].direccion.colonia);
                        for (j=0; j<tam; j++)
                        {
                                if ((aux[i]!=' ')&&((aux[i]<'0') || (aux[i]>'9'))&&((aux[i]<'A') || (aux[i]>'Z'))&&((aux[i]<'a') || (aux[i]>'z')))
                                {
                                        error=1;
                                        printf (" \nerror: %i", error);
                                }
                        }*/
			printf ("\n4.Ingrese su alcaldia: ");
                        scanf (" %[^\n]", usuario[i].direccion.alcaldia);
                        /*tam=strlen(usuario[i].direccion.alcaldia);
                        strcpy(aux, usuario[i].direccion.alcaldia);
                        for (j=0; j<tam; j++)
                        {
                                if ((aux[i]!=' ')&&((aux[i]<'0') || (aux[i]>'9'))&&((aux[i]<'A') || (aux[i]>'Z'))&&((aux[i]<'a') || (aux[i]>'z')))
                                {
                                        error=1;
                                        printf (" \nerror: %i", error);
                                }
                        }*/
			printf ("\n5.Ingrese su estado: ");
                        scanf (" %[^\n]", usuario[i].direccion.estado);
                        /*tam=strlen(usuario[i].direccion.estado);
                        strcpy(aux, usuario[i].direccion.estado);
                        for (j=0; j<tam; j++)
                        {
                                if ((aux[i]!=' ')&&((aux[i]<'A') || (aux[i]>'Z'))&&((aux[i]<'a') || (aux[i]>'z')))
                                {
                                        error=1;
                                        printf (" \nerror: %i", error);
                                }
                        }*/
			if (error==1)
                        {
                                printf ("\nIngreso mal algún dato, por favor verifique sus datos e ingréselos nuevamente.");
                        }
                }
                while (error==1);
        }
	return *datos;
}

/*
* @brief:
* @authors: Gabriel Coronado/Segio Esquivel/ Sebastian Alanis.
* @date
* @param
* @return
*/

extern void guardarDatosArchivo(struct user usuario[], char nomArch[], int *datos, int x)
{
	int i;
	char a;
	FILE *fp;
	fp=fopen(nomArch, "w");
	if (fp == NULL)
	{
		printf ("\nArchivo no disponible.\n");
		exit(1);
	}
	if (*datos==1)
	{
		for (i=x; i<(x+1); i++)
		{
			fprintf (fp, "\nUSUARIO %i", (i-1));
			fprintf (fp, "\nNombre: %s %s %s", usuario[i].nombre.nombres, usuario[i].nombre.apellidop, usuario[i].nombre.apellidom);
			fprintf (fp, "\nClave de elector: %s", usuario[i].ife);
			fprintf (fp, "\nCorreo eletrónico: %s", usuario[i].correo);
			fprintf (fp, "\nDirección: calle %s, # %s, Col. %s, Alc. %s, Estado %s\n", usuario[i].direccion.calle, usuario[i].direccion.numero, usuario[i].direccion.colonia, usuario[i].direccion.alcaldia, usuario[i].direccion.estado);
		}
	}
	return;
}

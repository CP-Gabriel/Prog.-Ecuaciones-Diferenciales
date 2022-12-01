/*
* @file: admistrador.c
* @brief: Este archico almacena las funciones que se utilizan en el menú de administrados.
* @authors: Gabriel Coronado/Segio Esquivel/ Sebastian Alanis.
* @date: 31/11/21
*/

#include "misDef.h"

/*
* @brief: Esta funcion permite iniciar sesion como administrador.
* @authors: Gabriel Coronado/Segio Esquivel/ Sebastian Alanis.
* @date 31/11/21
* @param *aceptado es un apuntador que almacena un 1 si los datos ingresados son correctos y 0 si son incorrectos.
* @return *aceptado es un apuntador que almacena un 1 si los datos ingresados son correctos y 0 si son incorrectos.
*/

extern int inicioSesion(int *aceptado)
{
	char usuario[20];
	char pass[20];
	int true, true2;
	do
	{
		system ("clear");
		printf ("\nVENTA DE BICICLETAS\n");
	        printf ("\nINICIO DE SESIÓN ADMINISTRADOR\n");
		if (*aceptado==0)
		{
			printf ("\nIngreso mal el usuario o la contraseña.\n");
		}
		printf ("\nUSUARIO: ");
		scanf (" %[^\n]", usuario);
		if (strcmp(usuario, "1") == 0)
		{
			true = 1;
		}
		else
	        {
	                true = 0;
        	}
		printf ("\nCONTRASEÑA: ");
		scanf (" %[^\n]", pass);
		if (strcmp(pass, "1") == 0)
	        {
			true2 = 1;
	        }
		else
		{
			true2 = 0;
		}
		if ((true==1)&&(true2==1))
		{
			*aceptado=1;
		}
		else
		{
			*aceptado=0;
		}
	}
	while (*aceptado==0);
	return *aceptado;
}

/*
* @brief: Esta función permite ver el informe de la ventas.
* @authors: Gabriel Coronado/Segio Esquivel/ Sebastian Alanis.
* @date: 31/11/21
* @param bicicleta[] es un struct que almacena los detalles de la ventas.
* @param x almacena el número total de usuarios registrados.
* @param *visto es un apuntador que almacena 1 si se ha utilizado la función.
* @return *visto es un apuntador que almacena 1 si se ha utilizado la función.
*/

extern int informeVentas(struct bike bicicleta[], int x, int *visto)
{
        int i;
        char salir;
	*visto=1;
        system ("clear");
        printf ("\nVENTA DE BICICLETAS\n");
        printf ("\nSESIÓN ADMINISTRADOR\n");
        printf ("\nINFORME DE VENTAS\n");
        for (i=2; i<(x+1); i++)
        {
		printf ("\nVENTA %i\n", (i-1));
		printf ("\nDETALLES:");
                printf ("\nCosto: $%.0f    Peso: %.3fkgms", bicicleta[i].costo, (bicicleta[i].peso/1000));
                printf ("\n1.Manubrio: %s", bicicleta[i].manubrio);
                printf ("\n2.Luces: %s", bicicleta[i].luces);
                printf ("\n3.Cuadro: %s", bicicleta[i].cuadro);
                printf ("\n4.Asiento: %s", bicicleta[i].asiento);
                printf ("\n5.%s", bicicleta[i].rack);
                printf ("\n6.Llantas: %s", bicicleta[i].llantas);
                printf ("\n7.%i velocidades", bicicleta[i].velocidad);
                printf ("\n8.Color: %s\n", bicicleta[i].color);
        }
	printf ("\nTECLE CUALQUIER COSA Y PRESIONE ENTER PARA SALIR\n");
        scanf (" %c", &salir);
	return *visto;
}

/*
* @brief: Esta funcíon ordena los datos de los usuarios de acuerdo a su nombre en orden alfabetico.(ascendente)
* @authors: Gabriel Coronado/Segio Esquivel/ Sebastian Alanis.
* @date: 31/11/21
* @param usuario[] es un struct que almacena los datos ingresados por los usuarios.
* @param x almacena el número total de usuarios registrados.
* @return void
*/

extern void ordenarUsuarios(struct user usuario[], int x)
{
	int i, j;
	struct user orden;
	for (i=2; i<(x+1); i++)
	{
		for (j=(i+1); j<(x+1); j++)
		{
			if (strcmp(usuario[i].nombre.nombres, usuario[j].nombre.nombres)>0)
			{
				orden=usuario[i];
				usuario[i]=usuario[j];
				usuario[j]=orden;
			}
		}
	}
	return;
}


/*
* @brief: Esta función imprime el informe de usuarios registrados.
* @authors: Gabriel Coronado/Segio Esquivel/ Sebastian Alanis.
* @date: 31/11/21
* @param usuario[] es un struct que almacena los datos ingresados por los usuarios.
* @param x almacena el número total de usuarios registrados.
* @param *visto es un apuntador que almacena 1 si se ha utilizado la función.
* @return *visto es un apuntador que almacena 1 si se ha utilizado la función.
*/

extern int informeUsuario(struct user usuario[], int x, int *visto)
{
	int i;
	char salir;
	*visto=1;
	system ("clear");
        printf ("\nVENTA DE BICICLETAS\n");
        printf ("\nSESIÓN ADMINISTRADOR\n");
	printf ("\nINFORME DE USUARIOS\n");
	for (i=2; i<(x+1); i++)
	{
		printf ("\nUSUARIO %i", (i-1));
		printf ("\nNombre: %s %s %s", usuario[i].nombre.nombres, usuario[i].nombre.apellidop, usuario[i].nombre.apellidom);
		printf ("\nClave de elector: %s", usuario[i].ife);
		printf ("\nCorreo eletrónico: %s", usuario[i].correo);
		printf ("\nDirección: calle %s, # %s, Col. %s, Alc. %s, Estado %s\n", usuario[i].direccion.calle, usuario[i].direccion.numero, usuario[i].direccion.colonia, usuario[i].direccion.alcaldia, usuario[i].direccion.estado);
		printf ("\nTECLE CUALQUIER COSA Y PRESIONE ENTER PARA SALIR\n");
	}
        scanf (" %c", &salir);
        return *visto;
}

/*
* @brief: Esta función imprime una guia de uso y funcionalidades del sistema.
* @authors: Gabriel Coronado/Segio Esquivel/ Sebastian Alanis.
* @date: 31/11/21
* @param *visto es un apuntador que almacena 1 si se ha utilizado la función.
* @return *visto es un apuntador que almacena 1 si se ha utilizado la función.
*/

extern int guiaDeayuda (int *visto)
{
	char salir;
	*visto=1;
	system ("clear");
        printf ("\nVENTA DE BICICLETAS\n");
        printf ("\nSESIÓN ADMINISTRADOR\n");
	printf ("\nGUIA DE AYUDA\n");
	printf ("Lo primero que verá al empezar el programa es el menú principal, en el aparecerán 3 tipos de opciones\n");
	printf ("enumeradas las cuales serán iniciar sesión como administrador, crear cuenta de usuario y salir, para\n");
	printf ("poder acceder a alguno de ellos se tiene que ingresar el número de la opción deseada, pero en dado caso\n");
	printf ("que se ingrese cualquier otro dato que no sea 1, 2 o 3 el programa indicará un error y volverá a pedir\n");
	printf ("que ingrese una opción correcta.\n");
	printf ("\nEn la primera opción que es iniciar sesión como administrador lo primero que hará el programa es pedir la\n");
	printf ("cuenta y contraseña de administrador, si se llegara a introducir una errónea el programa indicará el error y\n");
	printf ("volverá a pedir que ingrese los datos, una vez estén correctos los datos mostrará el menú de administrador en el\n");
	printf ("cual aparecen 4 opciones enumeradas las cuales son ver informe de ventas, ver informe de usuarios registrados, ver\n");
	printf ("guía de ayuda y salir, para poder salir de las primera 3 opciones tendrá que teclear cualquier letra o número y\n");
	printf ("presionar enter para regresar al menú de administrador, en el menú de administrador lo único que se tiene que\n");
	printf ("hacer es ingresar el número de la opción deseada, en la primera opción mostrará un informe de las ventas \n");
	printf ("registradas, en la segunda opción mostrará un informe de los usuarios registrados ordenados alfabéticamente en\n");
	printf ("orden ascendente, en la tercera opción se mostrará una guía de uso y funcionalidades del sistema, en la última\n");
	printf ("opción saldrá de la sesión de administrador para regresar al menú principal.\n");
	printf ("\nEn la segunda opción que es crear cuenta de usuario, primero le pedirá que ingrese su nombre completo, su clave\n");
	printf ("de elector y su correo electrónico, en dado caso de que ingrese algún dato mal el programa lo indicará y tendrá\n");
	printf ("que ingresar todos los datos nuevamente, posteriormente se le pedirá su dirección y de igual manera en caso de\n");
	printf ("ingresar un dato mal el programa se encargará de hacerlo saber, después del registro podrá empezar a modificar su\n");
	printf ("bicicleta, lo primero que verá será la configuración básica de una bicicleta, en ella aparecerán enumeradas las\n");
	printf ("modificaciones que se le pueden hacer, solo tendrá que ingresar el número de  la opción que desea modificar, una\n");
	printf ("vez ingresada la opción el programa mostrará el catálogo deseado nuevamente estarán numeradas las opciones a\n");
	printf ("escoger, usted solo tendrá que escoger la opción deseada y se le volverá a mostrar la bicicleta con los cambios\n");
	printf ("realizados, usted podrá repetir esta acción las veces que desee. Al final de cada modificación se le preguntará si\n");
	printf ("desea modificar algo más, usted indicará 1 como si y 0 como no, en caso de indicar que ya no quiere realizar más\n");
	printf ("cambios se le preguntará si quiere finalizar la compra de nueva cuenta usted responderá 1 como si y 0 como, en caso\n");
	printf ("de finalizar la compra se le mostrará el desglose de la venta, para salir solo tendrá que teclear cualquier letra\n");
	printf ("o número y presionar enter para regresar al menú principal y su compra estará registrada.\n");
	printf ("\nY en la última opción únicamente cerrará el programa guardando los datos que se hayan ingresado.");
	printf ("\nTECLE CUALQUIER COSA Y PRESIONE ENTER PARA SALIR\n");
        scanf (" %c", &salir);
	return *visto;
}

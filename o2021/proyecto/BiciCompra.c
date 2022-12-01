/*
* @file: BiciCompra.c
* @brief: Este programa opera como una tienda de bicicletas, el sistema da acceso a dos tipos de usuarios, el
*	  administrador que es el que configura y administra los servicios de venta y los usuarios que comprarán bicicletas.
*
*	  Al administrador se le permitirá ver un informe de ventas de bicicletas, informe de usuarios dados de alta, guía
*	  de ayuda(guía de uso y funcionalidades del programa), salida del sistema, pero antes deberá iniciar sesión como
*	  administrador para ello se debe pedir el usuario y contraseña.
*
*	  A los usuarios se les permitirá dar de alta pidiendo su nombre completo, dirección, registro IFE y un correo
*	  electrónico; permitirá configurár y armar su bicicleta para que al final de la opción comprar, en caso de
*	  confirmar, el sistema le mostrará la especificación de la venta realizada; antes de empezar a configurar su
*	  bicicleta se mostrarán las especificaciones que tiene una bicicleta básica para posteriormente preguntar al
*	  usuario que cosas quiere cambiar, una vez que el usuario realice los cambios necesarios se volverán a mostrar
*	  las especificaciones de la nueva bicicleta con su nuevo precio y peso, en caso de que el usuario desee volver
*	  a realizar algún cambio se actualizará el informe.
* @authors: Gabriel Coronado/Segio Esquivel/ Sebastian Alanis.
* @date:20/11/21
*/

#include "misDef.h"

extern int registrarDatos(struct user usuario[], int *nuevoUsuario, int x);
extern int registrarDireccion(struct user usuario[], int *nuevoUsuario, int *datos, int x);
extern void guardarDatosArchivo(struct user usuario[], char nomArch[], int *datos, int x);
extern int configurarBici(struct bike bicicleta[],  int *datos, int *confirmar, int x);
extern void guardarVentas(struct bike bicicleta[], char nomArch[], int *confirmar, int x, struct user usuario[]);

int main(void)
{
	int x;
	struct user usuario[x];
        struct bike bicicleta[1];
	int nuevoUsuario;
	int datos;
	int confirmar;
	char opcion;
	x=1;
	do//while de menu de opciones
	{
		do{
			system ("clear");
			printf ("\nVENTA DE BICICLETAS\n");
			printf ("\nINICIO\n");
			printf ("\n1.Inicar sesión como administrador.\n2.Crear cuenta usuario.\n3.Salir\n");
			printf ("\nIngresa el número de la acción deseas hacer: ");
			scanf (" %c", &opcion);
			if (opcion=='1')//Inicio de sesion(administrador)
			{
			}
			if (opcion=='2')//Crear cuenta
			{
				x++;
				registrarDatos(usuario, &nuevoUsuario, x);
				registrarDireccion(usuario, &nuevoUsuario, &datos, x);
				guardarDatosArchivo(usuario, "usuarios.txt", &datos, x);
				configurarBici(bicicleta, &datos, &confirmar, x);
		                guardarVentas(bicicleta, "ventas.txt", &confirmar, x, usuario);
			}
			if (opcion=='3')
			{
				break;
			}
			if ((opcion<'1') || (opcion>'3'))
			{
				printf ("\nOpción invalida por favor ingresa una opción valida.");
			}
		}
		while ((confirmar==0)||(confirmar==1));
	}
	while ((opcion<'1') || (opcion>'3'));
	printf ("\n");
	return 0;
}

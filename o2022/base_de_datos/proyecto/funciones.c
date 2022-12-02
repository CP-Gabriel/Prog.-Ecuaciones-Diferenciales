#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ejercutarSQL(char query[])
{
        int i = 0;
        int num_fields;

        char *server = "localhost";
        char *user = "ic21gcp";
        char *passwd = "223071";
        char *db = "ic21gcp";

        MYSQL mysql;
        MYSQL_RES *res;
        MYSQL_ROW row;
        MYSQL_FIELD *fields;

	mysql_init(&mysql);

	if (!mysql_real_connect(&mysql, server, user, passwd, db, 0, NULL, 0))
        {
                fprintf(stderr, "Error al conectarse a la BD: Error: %s\n", mysql_error(&mysql));
                return;
        }

	if (mysql_select_db(&mysql, db))
        {
                fprintf (stderr, "No existe la base de datos seleccionada: Error: %s\n", mysql_error(&mysql));
                exit(1);
        }

	if(mysql_query(&mysql, query))
        {
                fprintf(stderr, "Error al procesar el query \"%s\" Error: %s\n", query, mysql_error(&mysql));
                exit(1);
        }

	if(! (res = mysql_store_result(&mysql)))
        {
                fprintf(stderr, "Error al obtener el resultado Error: %s\n", mysql_error(&mysql));
                exit(1);
        }

	while((row = mysql_fetch_row(res)))
        {
                i = 0;
                for(i=0 ; i < mysql_num_fields(res); i++)
                {
                        if(row[i] != NULL)
                        {
                                printf("%s",row[i]);
                        }
                        else
                        {
                                printf(" \n");
                        }
                }
                fputc('\n',stdout);
        }

        mysql_free_result(res);
        mysql_close(&mysql);
	return;
}

int registrarUsuarios()
{
        char nombre[20]="", apellido[30]="", carrera[200]="", cumple[20]="", correo[100]="", contrasena[100]="", tipoUsuario[50]="", semestre[50]="", cuenta[100];
        int semester, i, num_fields;
	char query[1024] = "";
	char *db = "ic21gcp";

	MYSQL mysql;
        MYSQL_RES *res;
        MYSQL_ROW row;
        MYSQL_FIELD *fields;

	mysql_init(&mysql);

        system ("clear");
        printf ("\n\t\tBibiblioteca ibero\n\n");
        printf ("\nRegistrar Nuevo Usuario\n\n");

        printf ("\nIngresa el nombre: ");
        scanf (" %[^\n]", nombre);

        printf ("\nIngresa el apellido: ");
        scanf (" %[^\n]", apellido);

        printf ("\nIngresa el nombre carrera: ");
        scanf (" %[^\n]", carrera);

        printf ("\nLa fecha de nacimiento debe estar separada por - \nEjemplo: 2001-06-19 \nIngresa la fecha de nacimiento: ");
        scanf (" %[^\n]", cumple);

        printf ("\nIngresa el numero del semestre: ");
        scanf (" %[^\n]", semestre);
	semester = (int) strtol(semestre, NULL, 10);

        printf ("\nIngresa el correo: ");
        scanf (" %[^\n]", correo);

        printf ("\nIngresa la contraseña: ");
        scanf (" %[^\n]", contrasena);

        printf ("\nA: Administrador\tS: Solicitante \nIngresa la letra del tipo de Usuario: ");
        scanf (" %[^\n]", tipoUsuario);

        sprintf(query, "CALL pro_InsertarUsuario('%s', '%s', '%s', '%s', %i, '%s', '%s', '%s')", nombre, apellido, carrera, cumple, semester, correo, contrasena, tipoUsuario);
//        printf ("\nQUERY : %s\n", query);

	mysql_real_connect(&mysql, "localhost", "ic21gcp", "223071", "ic21gcp", 0, NULL, 0);
	mysql_select_db(&mysql, db);
	mysql_query(&mysql, query);
	res = mysql_store_result(&mysql);

	while ((row = mysql_fetch_row(res)))
        {
                for(i=0; i<mysql_num_fields(res); i++)
                {
                        if(row[i] != NULL)
                        {
				strcpy(cuenta, row[i]);
                        }
                }
        }

	printf ("\nCUENTA: %s", cuenta);
	system("read -p 'Presiona enter para continuar' var");
	mysql_free_result(res);
        mysql_close(&mysql);
//        ejercutarSQL(query);
	return 0;
}

void modificarRegistro()
{
	int cuenta, opcion;
	char query[1024] = "";

	system ("clear");
	printf ("\n\t\tBibiblioteca ibero\n\n");
	printf ("\nModificar Registro\n\n");
	printf ("\nIngresa la cuenta del usuario al cual quieres cambiar algun dato: ");
	scanf ("%i", &cuenta);
	sprintf(query, "SELECT * FROM pro_Users WHERE idUser = %i", cuenta);
	printf ("\nREGISTRO: \n");
        ejercutarSQL(query);
	printf ("\n\nMenu:");
	printf ("\n1. Nombre.");
	printf ("\n2. Apellido.");
	printf ("\n3. Carrera.");
	printf ("\n4. Fecha de nacimiento.");
	printf ("\n5. Semestre.");
	printf ("\n6. Correo.");
	printf ("\n7. Contraseña.");
	printf ("\n8. Tipo de usuario.\n");
	printf ("\nIngresa el numero de la opcion que deseas realizar: ");
	scanf ("%i", &opcion);

	printf ("\n");
	return;
}

void buscarUsuarios()
{
	int cuenta, opcion;
        char query[1024] = "";

        system ("clear");
        printf ("\n\t\tBibiblioteca ibero\n\n");
        printf ("\nBuscar Usuarios\n\n");
	printf ("\nOpciones de busqueda:");
	printf ("\n1. Nombre.");
	printf ("\n2. Apellido.");
	printf ("\n3. Cuenta.");
	printf ("\n4. Carrera.");
	printf ("\n5. Nombre del libro.");
	printf ("\n6. Id de libro.\n");
	printf ("\nIngresa la opcion del metodo de busqueda que quieres realizar: ");
	scanf ("%i", &opcion);

	printf ("\n");
	return;
}

void menuAdministrador()
{
	char opcion[255];
	int temp = 0, error = 0;
	int menu;

	do
	{
                system ("clear");
                printf ("\n\t\tBibiblioteca ibero\n\n");
                printf ("\nCesion Administrador\n\n");
		if (error == 1)
                {
                        printf ("\tDatos mal ingresados, por favor ingresa el un numero del menu.\t\n");
                        error = 0;
                }

                printf ("\nMenu:");
		printf ("\n1. Registrar Usuarios.");
		printf ("\n2. Modificar Registros de Usuarios.");
		printf ("\n3. Buscar Usuarios.");
		printf ("\n4. Cerrar Cesion.\n");
		printf ("\nIngresa el numero de la opcion que deseas realizar: ");
		scanf (" %[^\n]", opcion);
		menu = (int) strtol(opcion, NULL, 10);
/*		printf ("\nMENU: %i", menu);
		scanf (" %[^\n]", opcion);*/

		if (menu == 1)
		{
			registrarUsuarios();
			temp = 1;
		}
		else if (menu == 2)
                {
			modificarRegistro();
			temp = 1;
                }
		else if (menu == 3)
                {
			buscarUsuarios();
			temp = 1;
                }
		else
		{
			error = 1;
			temp = 1;
		}

	}
	while (temp == 1);

	printf ("\n");
        return;
}


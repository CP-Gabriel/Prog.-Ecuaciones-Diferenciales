#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern void menuAdministrador();
extern void menuSolicitante(int id);

int main(int argc, char **argv)
{
	char cuenta[100], contrasena[200], query[1024], tipoUsuario[1];
	int filtro = 0, error = 0;
	int id, i, num_fields;

	char *server = "localhost";
	char *user = "ic21gcp";
	char *passwd = "223071";
	char *db = "ic21gcp";

        MYSQL mysql;
        MYSQL_RES *res;
        MYSQL_ROW row;
        MYSQL_FIELD *fields;

	system ("clear");

	if(argc != 2)
	{
		fputs("Error: parametros incorrectos <\"query\">\n", stderr);
		return 1;
	}
	mysql_init(&mysql);

	if (!mysql_real_connect(&mysql, server, user, passwd, db, 0, NULL, 0))
        {
                fprintf(stderr, "Error al conectarse a la BD: Error: %s\n", mysql_error(&mysql));
                return 0;
        }
	if (mysql_select_db(&mysql, db))
	{
	        fprintf (stderr,"No existe la base de datos seleccionada: Error: %s\n",mysql_error(&mysql));
	        exit(1);
	}

	do
	{
		system ("clear");
		printf ("\n\t\tBibiblioteca ibero\n\n");
		printf ("\nInicio de Cesion\n\n");
		if (error == 1)
		{
			printf ("\tUsuario o contraseña incorrectos\n\tPor favor ingresalas nuevamente.\t\n");
			error = 0;
		}
		printf ("\nIngresa tu cuenta: ");
		scanf (" %[^\n]", cuenta);

		printf ("\nIngresa tu contraseña: ");
		scanf (" %[^\n]", contrasena);

		sprintf (query, "SELECT pro_IniciarSesion(%s, '%s')", cuenta, contrasena);

		if (mysql_query(&mysql, query))
	        {
			error = 1;
        	}
		else
		{
			filtro = 1;

			if (! (res = mysql_store_result(&mysql)))
		        {
		                fprintf(stderr,"Error al obtener el resultado Error: %s\n",mysql_error(&mysql));
		                exit(1);
		        }

		        while((row = mysql_fetch_row(res)))
		        {
		                i = 0;
	        	        for(i=0 ; i < mysql_num_fields(res); i++)
	        	        {
					strcpy(tipoUsuario, row[i]);
		                }
		        }

			if (strcmp(tipoUsuario, "A") == 0)
			{
				menuAdministrador();
				filtro = 0;
			}
			if (strcmp(tipoUsuario, "S") == 0)
			{
				id = (int) strtol(cuenta, NULL, 10);
				printf ("\nID : %i", id);
				printf ("\nID : %s", cuenta);
				scanf ("%i", &id);
				menuSolicitante(id);
				filtro = 0;
			}
			else
			{
				error = 1;
				filtro = 0;
				strcpy(query, "");
			}
		}
	}
	while (filtro == 0);

	printf ("\n");

	mysql_free_result(res);
        mysql_close(&mysql);
	return 0;
}

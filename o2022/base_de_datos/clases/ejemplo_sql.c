 #include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	unsigned int i = 0;
	char buffer[1024];
	unsigned int num_fields;

//	char *server = "antares.dci.uia.mx";
	char *server = "localhost";
	char *user = "ic21gcp";
	char *passwd = "223071";
	char *db = "ic21gcp";

	MYSQL mysql;
	MYSQL_RES *res;
	MYSQL_ROW row;
	MYSQL_FIELD *fields;

	if (argc != 3)
	{
		fputs("Error: parametros incorrectos <\"query\">\n", stderr);
		return 1;
	}

	mysql_init(&mysql);

	mysql_real_connect(&mysql, server, user, passwd, db, 0, NULL, 0);
	mysql_select_db(&mysql,argv[1]);
	strcpy(buffer,argv[2]);
        mysql_query(&mysql,buffer);
	res = mysql_store_result(&mysql);

/*	if (!mysql_real_connect(&mysql, server, user, passwd, db, 0, NULL, 0))
	{
		fprintf(stderr, "Error al conectarse a la BD: Error: %s\n", mysql_error(&mysql));
		return 0;
	}*/

/*	if(mysql_select_db(&mysql,argv[1]))
	{
        	fprintf(stderr,"No existe la base de datos seleccionada: Error: %s\n",mysql_error(&mysql));
	        exit(1);
	}*/

/*	strcpy(buffer,argv[2]);
	if(mysql_query(&mysql,buffer))
	{
	        fprintf(stderr,"Error al procesar el query \"%s\" Error: %s\n",buffer,mysql_error(&mysql));
	        exit(1);
	}*/

/*	if(! (res = mysql_store_result(&mysql)))
	{
	        fprintf(stderr,"Error al obtener el resultado Error: %s\n",mysql_error(&mysql));
	        exit(1);
    	}*/

	while((row = mysql_fetch_row(res)))
	{
		i = 0;
	        for(i=0 ; i < mysql_num_fields(res); i++)
		{
			if(row[i] != NULL)
			{
				printf("%s ",row[i]);
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

	return 0;
}

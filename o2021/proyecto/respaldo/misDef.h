#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct name
{
	char nombres[80];
	char apellidop[80];
	char apellidom[80];
};

struct direction
{
	char calle[50];
	char numero[10];
	char colonia[50];
	char alcaldia[50];
	char estado[30];
};

struct user
{
        struct name nombre;
	struct direction direccion;
	char ife[18];
	char correo[255];
};

struct bike
{
	float costo;
	float peso;
	char manubrio[80];
	char luces[80];
	char cuadro[80];
	char asiento[80];
	char rack[80];
	char llantas[80];
	int velocidad;
	char color[80];
};

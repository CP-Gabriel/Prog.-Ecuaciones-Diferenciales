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

extern int configurarBici(struct bike bicicleta[], int *datos, int *confirmar)
{
	int opcion, repetir, modif;
	int catamanu, cataluc, catacua, cataasie, catarack, catallan, catavel, catacol;
	bicicleta[0].costo= 900;
	bicicleta[0].peso= 11000;
	bicicleta[1].costo= 900;
        bicicleta[1].peso= 11000;
	int manubrio=0;
	int luces=0;
	int cuadro=0;
	int asiento=0;
	int rack=0;
	int llantas=0;
	int velocidad=0;
	int color=0;
	strcpy(bicicleta[0].manubrio,"estándar");
	strcpy(bicicleta[0].luces,"pilas");
	strcpy(bicicleta[0].cuadro,"acero");
	strcpy(bicicleta[0].asiento,"estándar");
	strcpy(bicicleta[0].rack,"Sin rack trasero");
	strcpy(bicicleta[0].llantas,"estándar");
	bicicleta[0].velocidad= 1;
	strcpy(bicicleta[0].color,"blanco");
	int inicio=0;
	system ("clear");
	if (inicio==0)
	{
		system ("clear");
       	        printf ("\nVENTA DE BICICLETAS\n");
        	printf ("\nCONFIGURACIÓN DE BICICLETA\n");
		if (*datos==1)
		{
			printf ("\nSus datos se regitraron correctamente.\nEstá registrado.\n");
		}
        	printf ("\nCONFIGURACIÓN BÁSICA\n");
		printf ("\nCosto: $%.0f\tPeso: %.0fkgms", bicicleta[0].costo, (bicicleta[0].peso/1000));
		printf ("\n1.Manubrio: %s", bicicleta[0].manubrio);
		printf ("\n2.Luces: %s", bicicleta[0].luces);
		printf ("\n3.Cuadro: %s", bicicleta[0].cuadro);
		printf ("\n4.Asiento: %s", bicicleta[0].asiento);
		printf ("\n5.%s", bicicleta[0].rack);
		printf ("\n6.Llantas: %s", bicicleta[0].llantas);
		printf ("\n7.%i velocidades", bicicleta[0].velocidad);
		printf ("\n8.Color: %s\n", bicicleta[0].color);
		printf ("\n1.SI         0.NO");
                printf ("\nDesea confirmar la compra: ");
                scanf (" %i", confirmar);
                if (*confirmar==1)
                {
                	printf ("\nMuchas gracias su compra.");
                }
		else
		{
			inicio=1;
			modif=0;
		}
	}
	if (inicio>0)
	{
		do
		{
			if (modif==1)
			{
				system ("clear");
		                repetir=0;
		                printf ("\nVENTA DE BICICLETAS\n");
		                printf ("\nCONFIGURACIÓN DE BICICLETA\n");
				printf ("\nCONFIGURACIÓN MODIFICADA\n");
		                printf ("\nCosto: $%.0f		Peso: %.3fkgms", bicicleta[1].costo, (bicicleta[1].peso/1000));
				if (manubrio==0)//manubrio
				{
		                	printf ("\n1.Manubrio: %s", bicicleta[0].manubrio);
				}
				if (manubrio>0)
                                {
                                        printf ("\n1.Manubrio: %s", bicicleta[1].manubrio);
                                }//manubrio
				if (luces==0)//luces
			        {
				        printf ("\n2.Luces: %s", bicicleta[0].luces);
				}
				if (luces>0)
                                {
                                        printf ("\n2.Luces: %s", bicicleta[1].luces);
                                }//luces
				if (cuadro==0)//cuadro
				{
		                	printf ("\n3.Cuadro: %s", bicicleta[0].cuadro);
				}
				if (cuadro==1)
                                {
                                        printf ("\n3.Cuadro: %s", bicicleta[1].cuadro);
                                }//cuadro
				if (asiento==0)//asiento
				{
		                	printf ("\n4.Asiento: %s", bicicleta[0].asiento);
				}
				if (asiento==1)
                                {
                                        printf ("\n4.Asiento: %s", bicicleta[1].asiento);
                                }//asiento
				if (rack==0)//rack
				{
		                	printf ("\n5.%s", bicicleta[0].rack);
				}
				if (rack==1)
                                {
                                        printf ("\n5.%s", bicicleta[1].rack);
                                }//rack
				if (llantas==0)//llantas
                                {
		                	printf ("\n6.Llantas: %s", bicicleta[0].llantas);
				}
				if (llantas==1)
                                {
                                        printf ("\n6.Llantas: %s", bicicleta[1].llantas);
                                }//llantas
				if (velocidad==0)//velocidad
                                {
		                	printf ("\n7.%i velocidades", bicicleta[0].velocidad);
				}
				if (velocidad==1)
                                {
                                        printf ("\n7.%i velocidades", bicicleta[1].velocidad);
                                }//velocidad
				if (color==0)//color
                                {
		                	printf ("\n8.Color: %s\n", bicicleta[0].color);
				}
				if (color==1)
                                {
                                        printf ("\n8.Color: %s\n", bicicleta[1].color);
                                }//color
		                printf ("\n1.SI         0.NO");
		                printf ("\nDesea confirmar la compra: ");
		                scanf (" %i", confirmar);
				if (*confirmar==1)
                		{
		                        printf ("\nMuchas gracias su compra.");
                		}
			}
			if (*confirmar==0)
			{
				printf ("\nIngrese el número de la opción que desea modificar: ");
				scanf (" %i", &opcion);
				if (opcion==1)//manubrio
				{
					//strcpy(bicicleta[1].manubrio,"estándar");
					system ("clear");
					repetir=1;
					modif=1;
					manubrio++;
					if (manubrio>1)
                                        {
                                                if (catamanu==2)
                                                {
                                                        bicicleta[1].peso= bicicleta[1].peso - 200;
							bicicleta[1].costo= bicicleta[1].costo - 150;
                                                }
						if (catamanu==3)
                                                {
							bicicleta[1].peso= bicicleta[1].peso + 100;
                                                        bicicleta[1].costo= bicicleta[1].costo - 207;
                                                }
                                        }
					printf ("\nVENTA DE BICICLETAS\n");
		        	        printf ("\nCONFIGURACIÓN DE BICICLETA\n");
					printf ("\nCONFIGURAR MANUBRIO\n");
					printf ("\nCATÁLOGO\n");
					printf ("\nMANUBRIO		PESO		PRECIO\n");
					printf ("\n1.Estándar		0		0");
					printf ("\n2.Urbano		+200grms	+$150");
					printf ("\n3.Deportivo		-100grms	+$207\n");
					printf ("\nIngrese el número de la opción que desea cambiar: ");
					scanf (" %i", &catamanu);
					if (catamanu==1)
					{
						strcpy(bicicleta[1].manubrio,"estándar");
					}
					if (catamanu==2)
                                        {
                                                strcpy(bicicleta[1].manubrio,"urbano");
                                                bicicleta[1].peso = bicicleta[1].peso + 200;
						bicicleta[1].costo = bicicleta[1].costo + 150;
                                        }
					if (catamanu==3)
                                        {
                                                strcpy(bicicleta[1].manubrio,"estándar");
						bicicleta[1].peso = bicicleta[1].peso - 100;
                                                bicicleta[1].costo = bicicleta[1].costo + 207;
                                        }
				}//manubrio
				if (opcion==2)//luces
                                {
                                        //strcpy(bicicleta[1].luces,"pilas");
                                        system ("clear");
                                        repetir=1;
                                        modif=1;
                                        luces++;
					if (luces>1)
                                        {
                                                if (cataluc==2)
                                                {
                                                        bicicleta[1].peso= bicicleta[1].peso + 50;
                                                        bicicleta[1].costo= bicicleta[1].costo - 92;
                                                }
                                                if (cataluc==3)
                                                {
                                                        bicicleta[1].peso= bicicleta[1].peso - 250;
                                                        bicicleta[1].costo= bicicleta[1].costo - 152;
                                                }
                                        }
                                        printf ("\nVENTA DE BICICLETAS\n");
                                        printf ("\nCONFIGURACIÓN DE BICICLETA\n");
                                        printf ("\nCONFIGURAR LUCES\n");
                                        printf ("\nCATÁLOGO\n");
                                        printf ("\nLUCES			PESO		PRECIO\n");
                                        printf ("\n1.Pilas			0               0");
                                        printf ("\n2.Cargables-usb		-50grms        	+$92");
                                        printf ("\n3.Dínamo		+250grms        +$152\n");
                                        printf ("\nIngrese el número de la opción que desea cambiar: ");
                                        scanf (" %i", &cataluc);
					if (cataluc==1)
                                        {
                                                strcpy(bicicleta[1].luces,"pilas");
                                        }
                                        if (cataluc==2)
                                        {
                                                strcpy(bicicleta[1].luces,"cargables-usb");
                                                bicicleta[1].peso = bicicleta[1].peso - 50;
                                                bicicleta[1].costo = bicicleta[1].costo + 92;
                                        }
					if (cataluc==3)
                                        {
                                                strcpy(bicicleta[1].manubrio,"dínamo");
                                                bicicleta[1].peso = bicicleta[1].peso + 250;
                                                bicicleta[1].costo = bicicleta[1].costo + 152;
                                        }
                                }//luces
				if (opcion==3)//cuadro
                                {
                                        //strcpy(bicicleta[1].cuadro,"acero");
                                        system ("clear");
                                        repetir=1;
                                        modif=1;
                                        cuadro++;
                                        if (cuadro>1)
                                        {
                                                if (catacua==2)
                                                {
                                                        bicicleta[1].peso= bicicleta[1].peso + 900;
                                                        bicicleta[1].costo= bicicleta[1].costo - 690;
                                                }
                                                if (catacua==3)
                                                {
                                                        bicicleta[1].peso= bicicleta[1].peso + 2345;
                                                        bicicleta[1].costo= bicicleta[1].costo - 1500;
                                                }
                                        }
					printf ("\nVENTA DE BICICLETAS\n");
                                        printf ("\nCONFIGURACIÓN DE BICICLETA\n");
                                        printf ("\nCONFIGURAR CUADRO\n");
                                        printf ("\nCATÁLOGO\n");
                                        printf ("\nCUADRO			PESO		PRECIO\n");
                                        printf ("\n1.Acero			0		0");
                                        printf ("\n2.Acero-aluminio	-900grms	+$690");
                                        printf ("\n3.Titanio		-2,345grms	+$1,500\n");
                                        printf ("\nIngrese el número de la opción que desea cambiar: ");
                                        scanf (" %i", &catacua);
                                        if (catacua==1)
                                        {
                                                strcpy(bicicleta[1].luces,"acero");
                                        }
                                        if (catacua==2)
                                        {
                                                strcpy(bicicleta[1].luces,"acero-aluminio");
                                                bicicleta[1].peso = bicicleta[1].peso - 900;
                                                bicicleta[1].costo = bicicleta[1].costo + 690;
                                        }
					if (catacua==3)
                                        {
                                                strcpy(bicicleta[1].cuadro,"titanio");
                                                bicicleta[1].peso = bicicleta[1].peso - 2345;
                                                bicicleta[1].costo = bicicleta[1].costo + 1500;
                                        }
                                }//cuadro
			}
		}
		while (repetir==1);
	}
	return *confirmar;
}

/*
* @brief:
* @authors: Gabriel Coronado/Segio Esquivel/ Sebastian Alanis.
* @date
* @param
* @return
*/

extern void guardarVentas(struct bike bicicleta[], char nomArch[], int *confirmar)
{
        int i;
        FILE *fp;
        fp=fopen(nomArch, "w");
        if (fp == NULL)
        {
                printf ("\nArchivo no disponible.\n");
                exit(1);
        }
	if (*confirmar==1)
	{
		fprintf (fp, "REPORTE DE VENTAS\n");
		//fprintf (fp, "\nVENTAS TOTALES %i\n", );
		for (i=1; i<2; i++)
		{
			fprintf (fp, "\nVENTA %i", i);
			fprintf (fp, "\nDetalles:");
			fprintf (fp, "\nCosto: $%.0f	Peso: %.3fkgms", bicicleta[i].costo, (bicicleta[i].peso/1000));
	                fprintf (fp, "\n1.Manubrio: %s", bicicleta[i].manubrio);
        	        fprintf (fp, "\n2.Luces: %s", bicicleta[i].luces);
	                fprintf (fp, "\n3.Cuadro: %s", bicicleta[i].cuadro);
       		        fprintf (fp, "\n4.Asiento: %s", bicicleta[i].asiento);
	                fprintf (fp, "\n5.%s", bicicleta[i].rack);
	                fprintf (fp, "\n6.Llantas: %s", bicicleta[i].llantas);
	                fprintf (fp, "\n7.%i velocidades", bicicleta[i].velocidad);
	                fprintf (fp, "\n8.Color: %s\n", bicicleta[i].color);
		}
	}
        return;
}

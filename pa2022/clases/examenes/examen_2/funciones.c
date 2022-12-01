/**
* @file
* @brief
* @author
* @date
*/

#include "tipos.h"

/**
* @brief
* @date
* @author
* @param
* @return
*/

//extern tipoNodo *crearListaDoble(tipoNodo *aux, tipoPaciente paciente)
extern tipoNodo *crearListaDoble(tipoNodo *aux, char name[], float weight, float height, int diag)
{
        tipoNodo *nuevo, *fin;

        nuevo = (tipoNodo *)malloc(sizeof(tipoNodo));

        if(nuevo == NULL)
        {
                printf("\nMemoria no disponible\n");
                exit(1);
        }

        strcpy(nuevo->nombre, name);
	nuevo->peso = weight;
	nuevo->altura = height;
	nuevo->trig = diag;

        if(aux == NULL)
        {
                aux = nuevo;
                nuevo->sig = aux;
                nuevo->ant = aux;
        }
	else
        {
                fin = aux->ant;
                aux->ant = nuevo;
                nuevo->sig = aux;
                nuevo->ant = fin;
                fin->sig = nuevo;
        }
        return aux;
}

/**
* @brief
* @date
* @author
* @param
* @return
*/

extern void recorrerSiguientes(tipoNodo *aux)
{
        tipoNodo *refInicio;

        refInicio = aux;
        if(aux != NULL)
        {
		do
                {
//			printf ("Nombre: %s\tPeso: %.2f Kg\tEstatura: %.2f m\tTriglicéridos: %i\n", aux->registro.nombre, aux->registro.peso, aux->registro.altura, aux->registro.trig);
			printf ("Nombre: %s\tPeso: %.2f Kg\tEstatura: %.2f m\tTriglicéridos: %i\n", aux->nombre, aux->peso, aux->altura, aux->trig);
                        aux = aux->sig;
                }
                while(aux != refInicio);
        }
        else
        {
                printf("\nLa lista esta vacía\n");
                exit(1);
        }
  return;
}

/**
* @brief
* @date
* @author
* @param
* @return
*/

extern void recorrerAnteriores(tipoNodo *aux)
{
        tipoNodo *refInicio;

        refInicio = aux;
        if(aux != NULL)
        {
                do
                {
                        aux = aux->ant;
			printf ("Nombre: %s\tPeso: %.2f Kg\tEstatura: %.2f m\tTriglicéridos: %i\n", aux->nombre, aux->peso, aux->altura, aux->trig);
                }
                while (aux != refInicio);
        }
        else
        {
                printf ("\nLista vacia.\n");
                exit(1);
        }
        return;
}

/**
* @brief
* @date
* @author
* @param
* @return
*/

extern tipoNodo *listaFinal(tipoNodo *aux)
//extern void listaFinal(tipoNodo *aux)
{
	tipoNodo *fin;
        fin = aux->ant;
        if(aux != NULL)
        {
		aux->ant->sig = NULL;
		aux->ant = NULL;
        }
        else
        {
                printf ("\nLista vacia.\n");
                exit(1);
        }
	return fin;
}

/**
* @brief
* @date
* @author
* @param
* @return
*/

extern void recorrerSiguientes2(tipoNodo *aux)
{
        if(aux != NULL)
        {
		do
                {
			printf ("Nombre: %s\tPeso: %.2f Kg\tEstatura: %.2f m\tTriglicéridos: %i\n", aux->nombre, aux->peso, aux->altura, aux->trig);
                        aux = aux->sig;
                }
                while(aux != NULL);
        }
        else
        {
                printf("\nLa lista esta vacía\n");
                exit(1);
        }
	return;
}

/**
* @brief
* @date
* @author
* @param
* @return
*/

extern void recorrerAnteriores2(tipoNodo *aux)
{
	if(aux != NULL)
        {
                do
                {
			printf ("Nombre: %s\tPeso: %.2f Kg\tEstatura: %.2f m\tTriglicéridos: %i\n", aux->nombre, aux->peso, aux->altura, aux->trig);
                        aux = aux->ant;
                }
                while (aux != NULL);
        }
        else
        {
                printf("\nLa lista esta vacía\n");
                exit(1);
        }
  return;
}

/**
* @brief
* @date
* @author
* @param
* @return
*/

extern void filtrarResultados(float filtroPeso, float filtroAltura, tipoNodo *aux)
{
	tipoNodo *refInicio;
        refInicio = aux;

	if(aux != NULL)
        {
		FILE *fp;
		fp = fopen ("filtro.txt", "w");
		fclose(fp);

		printf ("\nPacientes que miden menos de %.2f mts.\n", filtroAltura);
		fp = fopen ("filtro.txt", "a");
                if (fp == NULL)
                {
                        printf ("\nArchivo no disponible.\n");
                        exit(1);
                }
		fprintf (fp, "\nRegistros de personas que miden menos de %.2f mts.\n", filtroAltura);
                fclose(fp);

                do
                {
			if (aux->altura < filtroAltura)
			{
				printf ("Nombre: %s\tPeso: %.2f Kg\tEstatura: %.2f m\tTriglicéridos: %i\n", aux->nombre, aux->peso, aux->altura, aux->trig);
				FILE *fp;
                                fp = fopen ("filtro.txt", "a");
                                if (fp == NULL)
                                {
                                        printf ("\nArchivo no disponible.\n");
                                        exit(1);
                                }
                                fprintf (fp, "%s\t", aux->nombre);
                                fprintf (fp, "%.2f\n", aux->peso);
                                fclose(fp);
			}
                        aux = aux->sig;
                }
                while(aux != NULL);

		aux = refInicio;

		printf ("\nPacientes que pesan más de %.2f kg.\n", filtroPeso);
		fp = fopen ("filtro.txt", "a");
		if (fp == NULL)
		{
			printf ("\nArchivo no disponible.\n");
			exit(1);
		}
		fprintf (fp, "\nRegistros de personas que pesan más de %.2f kg.\n", filtroPeso);
                fclose(fp);

		do
                {
                        if (aux->peso > filtroPeso)
                        {
				printf ("Nombre: %s\tPeso: %.2f Kg\tEstatura: %.2f m\tTriglicéridos: %i\n", aux->nombre, aux->peso, aux->altura, aux->trig);

			        FILE *fp;
			        fp = fopen ("filtro.txt", "a");
			        if (fp == NULL)
			        {
			                printf ("\nArchivo no disponible.\n");
	        		        exit(1);
			        }
        			fprintf (fp, "%s\t", aux->nombre);
        			fprintf (fp, "%.2f\n", aux->peso);
			        fclose(fp);
                        }
                        aux = aux->sig;
                }
                while(aux != NULL);
        }
        else
        {
                printf("\nLa lista esta vacía\n");
                exit(1);
        }
	return;
}

/**
* @brief
* @date
* @author
* @param
* @return
*/

extern void crearTablero(tipoNodo *aux)
{
	float imc;
	int opcion;
	int i = 0;
        if(aux != NULL)
        {
                do
                {
			i++;
			printf ("\n%i\nPaciente: %s\n", i, aux->nombre);
			imc = ((aux->peso)/(aux->altura*aux->altura));
			//IMC
			printf ("IMC: %.2f kg/m²\n", imc);
			if (imc < 18.5)
			{
				printf ("Paciente con INFRAPESO\n");
			}
			if ((imc > 18.5) && (imc < 24.99))
                        {
                                printf ("Paciente con NORMAL\n");
                        }
			if ((imc > 25) && (imc < 29.99))
                        {
                                printf ("Paciente con SOBREPESO\n");
                        }
			if (imc >= 30)
                        {
                                printf ("Paciente con OBESIDAD\n");
                        }
			//FIN IMC

			//TRIGLICÉRIDOS
			printf ("Triglicéridos del paciente: %i mg/dL\n", aux->trig);
			if (aux->trig < 150)
			{
				printf ("Diagnostico de triglicéridos: NORMAL\n");
			}
			if ((aux->trig > 150) && (aux->trig < 199))
                        {
                                printf ("Diagnostico de triglicéridos: MODERADAMENTE ALTO\n");
                        }
			if ((aux->trig > 200) && (aux->trig < 499))
                        {
                                printf ("Diagnostico de triglicéridos: ALTO\n");
                        }
			if (aux->trig >= 500)
                        {
                                printf ("Diagnostico de triglicéridos: MUY ALTO\n");
                        }
			printf ("\t1.SI   0.NO\nDesea pasar al siguiente registro: ");
			scanf (" %i", &opcion);
                        aux = aux->sig;
                }
		while ((aux != NULL)&&(opcion != 0));
		if (aux == NULL)
		{
			printf ("\nLlego al final de la lista.");
		}
//		while ((opcion == 0)&&(aux != NULL));
        }
        else
        {
                printf("\nLa lista esta vacía\n");
                exit(1);
        }
        return;
}


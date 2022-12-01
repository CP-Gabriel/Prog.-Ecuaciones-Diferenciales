#include "tipos.h"

tipoAlumno *insertarFIFO(char nom[], int cta, float prom, tipoAlumno *pt)
{
        tipoAlumno *new, *fin;
        fin = pt;
        new = (tipoAlumno *)malloc(sizeof(tipoAlumno));
        if (new == NULL)
        {
                printf ("\nMemoria no disponible.\n");
                exit(1);
        }
        strcpy(new->nombre, nom);
        new->cuenta = cta;
        new->promedio = prom;
        if (pt == NULL)
        {
                pt = new;
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
        return pt;
}

//void recorrerListaAlumnos(tipoAlumno *pt)
void recorrerListaAlumnos(tipoAlumno *aux, gpointer estructura)
{
	char name[50];
	char prom[50];
	char account[50];
//	float prom;
//	int account;

	ref *pt = (ref *)estructura;
        if (aux == NULL)
        {
                printf ("No disponible");
        }
        else
        {
//               while (aux != NULL)
//               {
                        aux = aux->next;
			strcpy(name, aux->nombre);
//			account = aux->cuenta;
//			prom = aux->prom;
			sprintf (account, "%i", aux->cuenta);
			sprintf (prom, "%f", aux->promedio);
			strcat (account, name);
			strcat (account, prom);
//                        printf ("\nNombre: %s\tCuenta: %i\t Promedio: %f\n", pt->nombre, pt->cuenta, pt->promedio);
//		        gtk_label_set_text(GTK_LABEL(pt->label2), "\nNombre: %s\tCuenta: %i\t Promedio: %f\n", aux->nombre, aux->cuenta, aux->promedio);
//			gtk_label_set_text(GTK_LABEL(pt->label2), datos);
//			gtk_entry_set_text(GTK_ENTRY(pt->entrada),"\nNombre: %s\tCuenta: %i\t Promedio: %f\n", aux->nombre, aux->cuenta, aux->promedio);
//			gtk_entry_set_text(GTK_ENTRY(pt->entrada), aux->nombre aux->cuenta aux->promedio);
			gtk_entry_set_text(GTK_ENTRY(pt->entrada), account);
//                }
        }
  	return;
}

/*void promedioAlumnos(tipoAlumno *pt)
{
        float promedio;
        float tot;
        int i=1;
        if (pt == NULL)
        {
                printf ("No disponible");
        }
        else
        {
                while (pt != NULL)
                {
                        i++;
                        tot = tot + pt->promedio;
                        pt = pt->next;
                }
                promedio = tot/(i-1);
                printf ("\nEl promedio es: %f", promedio);
        }
        return;
}

void mayorPromedio(tipoAlumno *pt)
{
        float may;
        if (pt == NULL)
        {
                printf ("No disponible");
        }
        else
	{
                while (pt != NULL)
                {
                        may = pt->promedio;
                        if (may < pt->promedio)
                        {
                                may = pt->promedio;
                        }
                        pt = pt->next;
                }
                printf ("\nEl mejor promedio es: %f", may);
        }
        return;
}*/

extern void closeTheApp(GtkWidget *window, gpointer estructura)
{
//        ref *pt = (ref *)estructura;
//        recorreLista(pt->inicio);
//        g_print("\nSe hicieron %i pushes y %i popes\n", pt->contPush, pt->contPop);
        gtk_main_quit();

        return;
}

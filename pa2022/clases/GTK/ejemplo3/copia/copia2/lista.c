/**
 * @file listaALumnos.c
 * @brief Este programa permite leer los datos de alumnos de un
 *        archivo de texto desde la linea de comandos.
 *        Los datos de los alumnos nos darán la sinformación de entrada
 *        para crear una lista simple que será una Cola FIFO.
 *        Una vez creada la lista, haremos reportes de los datos contenidos
 */
#include "tipos.h"

tipoAlumno *insertarFIFO(char nom[], int cta, float prom, tipoAlumno *pt);
void recorrerListaAlumnos(tipoAlumno *aux, gpointer estructura);
//void recorrerListaAlumnos(tipoAlumno *aux, gpointer *estructura);
//void promedioAlumnos(tipoAlumno *pt);
//void mayorPromedio(tipoAlumno *pt);

void closeTheApp(GtkWidget *window, gpointer estructura);

int main(int argc, char *argv[])
{
	ref base;
//        base.inicio = NULL;

        tipoAlumno *inicio;
        /*0. Declaración de variables */
//        GtkWidget *window, *vbox, *hbox, *question, *label, *boton;
//        GtkWidget *botonLimpia;
	GtkWidget *window, *label, *hbox;

        /*1. Inicializar el ambiente*/
        gtk_init(&argc, &argv);


        /*2. Creación de los objetos y modificación de atributos */
        window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title (GTK_WINDOW(window), "Ejemplo LISTA");
        gtk_container_set_border_width(GTK_CONTAINER(window), 10);
	//VENTANA
//        question = gtk_label_new("");
        label = gtk_label_new("Lista: ");
//        boton = gtk_button_new_with_label("Push");
//        botonLimpia = gtk_button_new_with_label("Pop");
	base.entrada = gtk_entry_new();
//        base.label2 = gtk_label_new("");
//        base.estatus = gtk_label_new("");

        FILE *fp;
        char nom[80];
        int cta;
        float prom;
        inicio = NULL;

        fp = fopen(argv[1],"r");
        if (fp == NULL)
        {
                printf ("\nArchivo no disponible.\n");
                exit(1);
        }
        while (fscanf (fp, "%[^\t]", nom) == 1)
        {
                fscanf (fp, "%i\t", &cta);
                fscanf (fp, "%f\n", &prom);
                inicio = insertarFIFO(nom, cta, prom, inicio);
        }
        fclose(fp);
        recorrerListaAlumnos(inicio, &base);

        /*3. Registro de los Callbacks */
        g_signal_connect(GTK_OBJECT(window), "destroy", GTK_SIGNAL_FUNC(closeTheApp), &base);
//        g_signal_connect(GTK_OBJECT(window), "destroy", GTK_SIGNAL_FUNC(closeTheApp), base);
//        g_signal_connect(GTK_OBJECT(boton), "clicked", GTK_SIGNAL_FUNC(pushTexto), &base);
//        g_signal_connect(GTK_OBJECT(botonLimpia), "clicked", GTK_SIGNAL_FUNC(popTexto), &base);
        /* Comando para insertar texto en el campo de entrada (Entry) */
//        gtk_entry_set_text(GTK_ENTRY(base.entrada), "Escribe un dato...");

        /* 4. Define jerarquía de instancias (pack the widgets)*/
        hbox = gtk_hbox_new(FALSE, 5);
        gtk_box_pack_start_defaults(GTK_BOX(hbox), label);
//        gtk_box_pack_start_defaults(GTK_BOX(hbox), base->label2);
//        gtk_box_pack_start_defaults(GTK_BOX(hbox), base.label2);
        gtk_box_pack_start_defaults(GTK_BOX(hbox), base.entrada);
/*        vbox = gtk_vbox_new(FALSE, 5);
        gtk_box_pack_start_defaults(GTK_BOX(vbox), question);
        gtk_box_pack_start_defaults(GTK_BOX(vbox), hbox);
        gtk_box_pack_start_defaults(GTK_BOX(vbox), boton);
        gtk_box_pack_start_defaults(GTK_BOX(vbox), botonLimpia);
        gtk_box_pack_start_defaults(GTK_BOX(vbox), base.label2);
        gtk_box_pack_start_defaults(GTK_BOX(vbox), base.estatus);*/
        gtk_container_add(GTK_CONTAINER(window),hbox);

        /* 5. Mostrar los widgets */
        gtk_widget_show_all(window);

        /* 6. El programa se queda en loop */
        gtk_main();

//        recorrerListaAlumnos(inicio, &base);
/*        promedioAlumnos(inicio);
        mayorPromedio(inicio);*/
        printf ("\n\n");
        return 0;
}

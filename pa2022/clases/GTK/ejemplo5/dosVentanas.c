#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>

void pushTexto(GtkWidget *boton, gpointer estructura);
void closeTheApp(GtkWidget *window, gpointer estructura);
void popTexto(GtkWidget *boton, gpointer estructura);

struct elemento{
 char texto[20];
 int edad;
 struct elemento *next;
};
typedef struct elemento nodo;

nodo *push(char text[], nodo *p);
nodo *pop(nodo *p);
void recorreLista(nodo *p);

struct referencia{
 GtkWidget *entrada;//Este es el entry 1
 GtkWidget *edad;//Este será el entry 2
 GtkWidget *label2;
 nodo *inicio;
};
typedef struct referencia ref;
//nodo *inicio;

int main(int argc, char *argv[])
{
	/*0. Declaración de variables */
	ref base;
 	base.inicio = NULL;

 	GtkWidget *window, *vbox, *hbox, *hbox3, *question, *label, *boton;
 	GtkWidget *botonLimpia, *label2;
 	GtkWidget *window2, *hbox2;

 	/*1. Inicializar el ambiente*/
	gtk_init(&argc,&argv);

	/*2. Creación de los objetos y modificación de atributos */
 	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 	gtk_window_set_title (GTK_WINDOW(window), "Ejemplo Push/Pop");
 	gtk_container_set_border_width(GTK_CONTAINER(window),10);

	question = gtk_label_new("¿Deseas ingresar datos?");
 	label = gtk_label_new("Nombre:");
 	label2 = gtk_label_new("Edad:");
 	boton = gtk_button_new_with_label("Push");
 	botonLimpia = gtk_button_new_with_label("Pop");
 	base.entrada = gtk_entry_new();
 	base.edad = gtk_entry_new();
 	gtk_entry_set_text(GTK_ENTRY(base.entrada),"Escribe un nombre" );
 	gtk_entry_set_text(GTK_ENTRY(base.edad),"Escribe la edad" );

 	window2 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 	gtk_window_set_title(GTK_WINDOW(window2), "Otra ventana");

 	base.label2 = gtk_label_new("Etiqueta en ventana dos");
 	gtk_window_set_position(GTK_WINDOW(window2), GTK_WIN_POS_CENTER);
 	gtk_window_set_default_size(GTK_WINDOW(window2), 300, 300);

 	/*3. Registro de los Callbacks */
 	g_signal_connect(GTK_OBJECT(window), "destroy", GTK_SIGNAL_FUNC(closeTheApp), &base);
 	g_signal_connect(GTK_OBJECT(window2), "destroy", GTK_SIGNAL_FUNC(closeTheApp), &base);
 	g_signal_connect(GTK_OBJECT(boton), "clicked", GTK_SIGNAL_FUNC(pushTexto), &base);
 	g_signal_connect(GTK_OBJECT(botonLimpia), "clicked", GTK_SIGNAL_FUNC(popTexto), &base);

 	/* 4. Define jerarquía de instancias (pack the widgets)*/
 	hbox = gtk_hbox_new(FALSE, 5);
 	gtk_box_pack_start_defaults(GTK_BOX(hbox), label);
 	gtk_box_pack_start_defaults(GTK_BOX(hbox), base.entrada);
 	hbox3 = gtk_hbox_new(FALSE, 5);
 	gtk_box_pack_start_defaults(GTK_BOX(hbox3), label2);
 	gtk_box_pack_start_defaults(GTK_BOX(hbox3), base.edad);
 	vbox = gtk_vbox_new(FALSE, 5);
 	gtk_box_pack_start_defaults(GTK_BOX(vbox), question);
 	gtk_box_pack_start_defaults(GTK_BOX(vbox), hbox);
 	gtk_box_pack_start_defaults(GTK_BOX(vbox), hbox3);
 	gtk_box_pack_start_defaults(GTK_BOX(vbox), boton);
 	gtk_box_pack_start_defaults(GTK_BOX(vbox), botonLimpia);
 	gtk_container_add(GTK_CONTAINER(window),vbox);

 	hbox2 = gtk_hbox_new(FALSE, 5);
	gtk_box_pack_start_defaults(GTK_BOX(hbox2), base.label2);
	gtk_container_add(GTK_CONTAINER(window2),hbox2);

	/* 5. Mostrar los widgets */
 	gtk_widget_show_all(window2);
 	gtk_widget_show_all(window);

 	/* 6. El programa se queda en loop */
 	gtk_main();

	return 0;
}

void pushTexto(GtkWidget *boton, gpointer estructura)
{
 	char datos[20];
 	char edadEntry[20];
 	char letrero[80];
 	ref *pt = (ref *)estructura;

	strcpy(datos, gtk_entry_get_text(GTK_ENTRY(pt->entrada)));
 	strcpy(edadEntry, gtk_entry_get_text(GTK_ENTRY(pt->edad)));
 	sprintf(letrero,"Su nombre es %s\n y su edad es %s", datos, edadEntry);
 	pt->inicio = push(datos, pt->inicio);
 	gtk_label_set_text(GTK_LABEL(pt->label2), letrero);

 	return;
}

void popTexto(GtkWidget *boton, gpointer estructura)
{
 	ref *pt = (ref *)estructura;
 	gtk_entry_set_text(GTK_ENTRY(pt->entrada),"" );
	pt->inicio = pop(pt->inicio);
 	gtk_label_set_text(GTK_LABEL(pt->label2),"Pop :(");

 	return;
}

void closeTheApp(GtkWidget *window, gpointer estructura)
{
 	ref *pt = (ref *)estructura;
 	recorreLista(pt->inicio);
 	gtk_main_quit();
 	return;
}

nodo *push(char text[], nodo *p)
{
 	nodo *aux;

 	aux = (nodo *)malloc(sizeof(nodo));
 	if (aux == NULL)
 	{
	 	g_print("error, Stack overflow");
	 	exit(1);
	}

	g_print("Le dimos push a: %s\n", text);
 	aux->next = p;
 	strcpy(aux->texto,text);
 	p = aux;

 	return p;
}

nodo *pop(nodo *p)
{
 	char text[20];
 	nodo *aux;

 	aux = p;
 	if (p == NULL)
 	{
 		g_print("Stack vacío\n");
 		exit(1);
 	}
 	strcpy(text, p->texto);
 	p = p->next;
 	free(aux);
 	g_print("Le dimos pop a: %s\n", text);

 	return p;
}

void recorreLista(nodo *p)
{
	while(p != NULL)
 	{
 		g_print("\n Este es: %s", p->texto);
 		p = p->next;
 	}

 	return;
}

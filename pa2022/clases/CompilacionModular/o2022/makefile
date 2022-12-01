#Este es el makefile del programa controlado por principal.c.
#Los modulos externos que controla principal.c están son funciones.c y raiz.c

principal.exe: principal.o funciones.o raiz.o
	gcc principal funciones.o raiz.o -o principal.exe -lm

principal.o: principal.c
	gcc -c principal.c

funciones.o: funciones.c
	gcc -c funciones.c

#Este archivo fuente ustedes, alumnos, no lo tienen. No pueden ejecutarlo.
raiz.o: raiz.c
	gcc -c raiz.c



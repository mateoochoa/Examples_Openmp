###############################################################################
#              Archivo: Makefile
#                Autor: Miguel Angel <miguelan.ruiz@correo.usa.edu.co>
#  Última Modificación: Octubre 14, 2020
#  ----------------------------------------------------------------
#
# RESUMEN:
# =========
# Este programa realiza una multiplicacion de matrices clasica
# donde el usuario debe especificar el tamaño de la matriz y el nu- 
# mero de hilos a implementar. 
# El proposito de la aplicacion es desarrollar los conceptos de las
# directivas de programacion OpenMP para realizar tomas de rendimiento.
# A su vez se utiliza la programacion modular, para la compilacion del
# codigo.
###############################################################################

CC = gcc
CFLAGS = -Wall -fopenmp

PROGS = algoritmo_1 algoritmo_2 algoritmo_3
all: $(PROGS)

$(PROGS): $(PROGS).c
	$(CC) $(CFLAGS) -o $@ $@.c utilsMP.c

utilsMP.o: utilsMP.c utilsMP.h
	$(CC) $(CFLAGS) -c utilsMP.c

clean:
	$(RM) *.o
	$(RM) $(PROGS)

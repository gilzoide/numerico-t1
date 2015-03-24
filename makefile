# Makefile do T1 de Cálculo Numérico

CFLAGS = -g -Wall -lm
CC = gcc

#all : comum bisseccao newton

bisseccao : bisseccao.o comum.o
	$(CC) $^ -o $@ $(CFLAGS)

newton : newton.o comum.o
	$(CC) $^ -o $@ $(CFLAGS)

secantes : secantes.o comum.o
	$(CC) $^ -o $@ $(CFLAGS)

clean :
	$(RM) *.o *~ comum bisseccao newton secantes *.dat

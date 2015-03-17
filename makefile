# Makefile do T1 de Cálculo Numérico

CFLAGS = -g -Wall -lm
CC = gcc

#all : comum bisseccao newton

comum : comum.o
	$(CC) $< -o $@ $(CFLAGS)

bisseccao : bisseccao.o
	$(CC) $< -o $@ $(CFLAGS)

newton : newton.o
	$(CC) $< -o $@ $(CFLAGS)

secantes : secantes.o
	$(CC) $< -o $@ $(CFLAGS)

clean :
	$(RM) *.o *~ comum bisseccao newton secantes

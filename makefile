# Makefile do T1 de Cálculo Numérico

CFLAGS = -g -Wall -lm
CC = gcc

#all : comum bisseccao newton

comum : comum.o
	$(CC) $(CFLAGS) $< -o $@

bisseccao : bisseccao.o
	$(CC) $(CFLAGS) $< -o $@

newton : newton.o
	$(CC) $(CFLAGS) $< -o $@


clean :
	$(RM) *.o *~ comum bisseccao newton

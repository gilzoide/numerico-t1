# Makefile do T1 de Cálculo Numérico
#
# Gil Barbosa Reis - 8532248
# Lucas Peres Nunes Matias - 8531633

CFLAGS = -g -Wall -lm
CC = gcc

all : comum.o bisseccao newton secantes

bisseccao : bisseccao.o comum.o
	$(CC) $^ -o $@ $(CFLAGS)

newton : newton.o comum.o
	$(CC) $^ -o $@ $(CFLAGS)

secantes : secantes.o comum.o
	$(CC) $^ -o $@ $(CFLAGS)

checa_convergencia :
	@wc -l *.dat | head -n -1

clean :
	$(RM) *.o *~ comum bisseccao newton secantes *.dat

#include "comum.h"

// Calcula a raiz de `f'
double bisseccao (double a, double b, FILE *arquivo) {
	int i;
	double x = a, x_anterior, erro;

	// testa limites do intervalo, vai que tem raiz lá
	if (f (a) == 0) {
		return a;
	}
	else if (f (b) == 0) {
		return b;
	}
	// se f(a) tem mesmo sinal de f(b), possivelmente não há raiz no intervalo
	else if (f (a) * f (b) > 0) {
		return FALHOU;
	}

	for (i = 0; i < MAXITER; i++) {
		// atualiza x: meio do intervalo
		x_anterior = x;
		x = (a + b) / 2;
		erro = fabs (x - x_anterior);

		fprintf (arquivo, "%.8lf %.8lf %.8lf %.8lf %.8lf\n", a, b, x_anterior, f (x_anterior), erro);

		// verifica se x é raiz
		if (f (x) == 0 || erro < getErro(x)) {
			break;
		}
		else if (f (x) * f (a) > 0) {
			// segunda metade é onde há a raiz
			a = x;
		}
		else { // f (x) * f(b) > 0
			b = x;
		}
	}

	return x;
}

int main () {
	// arquivo de saída
	FILE *arquivo = fopen ("bisseccao.dat", "w+");
	if (arquivo == NULL) {
		fputs ("Erro na abertura do arquivo de saída =S", stderr);
		return -1;
	}

	printf ("Raiz da f no intervalo [-1, 0]: %lf\n", bisseccao (-1, 0, arquivo));
	printf ("Raiz da f no intervalo [0, 1]: %lf\n", bisseccao (0, 1, arquivo));

	fclose (arquivo);

	return 0;
}

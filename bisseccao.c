#include "comum.h"

// Calcula a raiz de `f'
double bisseccao (double a, double b, char p) {
	int i;
	double x = a, x_anterior, x_dop, erro;
	double raiz = FALHOU;

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

	for (i = 0; i < MAXITER && (raiz == FALHOU && !p); i++) {
		// atualiza x: meio do intervalo
		x_dop = x_anterior;
		x_anterior = x;
		x = (a + b) / 2;
		erro = fabs (x - x_anterior);

		if (raiz == FALHOU) {
			printf ("%.8lf %.8lf %.8lf %.8lf %.8lf\n", a, b, x_anterior, f (x_anterior), erro);
		}

		// verifica se x é raiz
		if (raiz == FALHOU && (f (x) == 0 || erro < getErro(x))) {
			raiz = x;
		}
		else if (f (x) * f (a) > 0) {
			// segunda metade é onde há a raiz
			a = x;
		}
		else { // f (x) * f(b) > 0
			b = x;
		}
	}

	if (!p) {
		return raiz;
	}
	else {
		printf ("%lf %e %lf %lf %lf %d\n", raiz, x, x - raiz, x_anterior - raiz, x_dop - raiz, MAXITER);
		return ((log (fabs ((x - raiz) / (x_anterior - raiz)))) / (log (fabs ((x_anterior - raiz) / (x_dop - raiz)))));
	}
}

int main () {
	printf ("Raiz da f entre [-1, 0]: %lf\n", bisseccao (-1, 0, 0));
	printf ("Raiz da f entre [0, 1]: %lf\n", bisseccao (0, 1, 0));
	printf("P: %lf\n", bisseccao (0, 1, 1));

	return 0;
}

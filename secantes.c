/* secantes.c
 *
 * Gil Barbosa Reis - 8532248
 * Lucas Peres Nunes Matias - 8531633
 */
#include "comum.h"

double secantes (double a, double b, double raiz, FILE *arquivo) {
	int i;
	double x = a, x_anterior = b, x_antes_ainda, erro, buffer;

	if (f(a) * f(b) > 0) {
		return FALHOU;
	}

	for(i = 0; i < MAXITER; i++){
		buffer = x;

		x = (f (x) * x_anterior - f (x_anterior) * x) / (f (x) - f (x_anterior));
		x_antes_ainda = x_anterior;
		x_anterior = buffer;

		erro = fabs (x - x_anterior);

		fprintf (arquivo, "%.8lf %.8lf %.8lf\n", x, f (x), erro);

		if (erro < getErro (x)) {
			break;
		}
	}

	double p = ( log( fabs( (x - raiz) / (x_anterior - raiz) ) ) ) / ( log( fabs( (x_anterior - raiz) / (x_antes_ainda - raiz) ) ) );
	printf ("Ordem de Convergencia do Metodo das Secantes: %lf\n", p);

	return x;
}

int main () {
	// arquivo de saída
	FILE *arquivo = fopen ("secantes_saida1.dat", "w+");
	assert (arquivo != NULL);
	printf ("Raiz da f entre [-1, 0]: %.8lf\n", secantes (-1, 0, X1, arquivo));
	fclose (arquivo);

	arquivo = fopen ("secantes_saida2.dat", "w+");
	assert (arquivo != NULL);
	printf ("Raiz da f entre [0.4, 1]: %.8lf\n", secantes (0.4, 1, X2, arquivo));
	fclose (arquivo);

	return 0;
}

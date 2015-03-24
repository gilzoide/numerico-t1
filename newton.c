#include "comum.h"

double newton (double a, double b, FILE *arquivo) {
	int i, j;
	double x = a, x_anterior, erro, p = 0, xizes[MAXITER];
	if (f (a) * f (b) > 0) {
		return FALHOU;
	}

	for(i = 0; i < MAXITER; i++) {
		x_anterior = x;
		x = x_anterior - (f (x_anterior) / df (x_anterior));
		erro = fabs (x - x_anterior);

		fprintf (arquivo, "%.8lf %.8lf %.8lf %.8lf\n", x, f (x), df (x), erro);

		xizes[i] = x;

		if (erro < getErro (x)){
			break;
		}

	}

	for(j = 1; j < i-1; ++j){
		p = ( log( fabs( (xizes[j+1] - x) / (xizes[j] - x) ) ) ) / ( log( fabs( (xizes[j] - x) / (xizes[j-1] - x) ) ) );
	}

	p = p/(i - 2);

	printf ("Ordem de Convergencia do Metodo de Newton: %lf\n", p);

	return x;
}

int main () {
	// arquivo de saída
	FILE *arquivo = fopen ("newton_saida1.dat", "w+");
	assert (arquivo != NULL);
	printf ("Raiz da f entre [-1, 0]: %lf\n", newton (-1, 0, arquivo));
	fclose (arquivo);

	arquivo = fopen ("newton_saida2.dat", "w+");
	assert (arquivo != NULL);
	printf ("Raiz da f entre [0.4, 1]: %lf\n", newton (0.4, 1, arquivo));
	fclose (arquivo);

	return 0;
}

/* newton.c
 *
 * Gil Barbosa Reis - 8532248
 * Lucas Peres Nunes Matias - 8531633
 */
#include "comum.h"

double newton (double a, double b, double raiz, FILE *arquivo) {
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

		if (erro < getErro (x)){
			break;
		}

		xizes[i] = x;
	}

	for(j = 1; j < i-1; ++j){
		p = ( log( fabs( (xizes[j+1] - raiz) / (xizes[j] - raiz) ) ) ) / ( log( fabs( (xizes[j] - raiz) / (xizes[j-1] - raiz) ) ) );
	}

	p = p/(i - 2);

	printf ("Ordem de Convergencia do Metodo de Newton: %lf\n", p);

	return x;
}

int main () {
	// arquivo de saída
	FILE *arquivo = fopen ("newton_saida1.dat", "w+");
	assert (arquivo != NULL);
	printf ("Raiz da f entre [-1, 0]: %lf\n", newton (-1, 0, X1, arquivo));
	fclose (arquivo);

	arquivo = fopen ("newton_saida2.dat", "w+");
	assert (arquivo != NULL);
	printf ("Raiz da f entre [0.4, 1]: %lf\n", newton (0.4, 1, X2, arquivo));
	fclose (arquivo);

	return 0;
}

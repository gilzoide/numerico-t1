#include "comum.h"

double newton (double a, double b){
	int i;
	double x = a, x_anterior, erro;

	if(f(a) * f(b) > 0){
		return FALHOU;
	}

	for(i = 0; i < MAXITER; i++){
		x_anterior = x;
		x = x_anterior - (f(x_anterior) / df(x_anterior));
		erro = fabs (x - x_anterior);

		printf ("%.8lf %.8lf %.8lf %.8lf\n", x, f (x), df (x), erro);

		if(erro < getError(x)){ break; }
	}

	return x;
}

int main(){
	printf ("Raiz da f entre [-1, 0]: %lf\n", newton (-1, 0));
	printf ("Raiz da f entre [0.4, 1]: %lf\n", newton (0.4, 1));

	return 0;
}
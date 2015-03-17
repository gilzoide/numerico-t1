#include "comum.h"

double secantes(double a, double b){
	int i;
	double x = a, x_anterior = b, erro;

	if(f(a) * f(b) > 0){
		return FALHOU;
	}

	for(i = 0; i < MAXITER; i++){
		double buffer = x;

		x = (f(x)*x_anterior - f(x_anterior)*x)/(f(x) - f(x_anterior));
		x_anterior = buffer;

		erro = fabs (x - x_anterior);

		printf ("%.8lf %.8lf %.8lf\n", x, f (x), erro);

		if(erro < getError(x)){ break; }
	}

	return x;
}

int main(){
	printf ("Raiz da f entre [-1, 0]: %lf\n", secantes (-1, 0));
	printf ("Raiz da f entre [0.4, 1]: %lf\n", secantes (0.4, 1));

	return 0;
}

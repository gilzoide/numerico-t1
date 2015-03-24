/* comum.c
 *
 * Gil Barbosa Reis - 8532248
 * Lucas Peres Nunes Matias - 8531633
 */
#include "comum.h"

double max (double a, double b) {
	return a > b ? a : b;
}

double getErro (double x) {
	return (ERRO * max (1, fabs (x)));
}

/// A função usada para os cálculos:
// f(x) = 63*x^4 - 26*x^3 + 39*x^2 - 26*x - 24
double f (double x) {
	return (
		63 * pow (x, 4)
		- 26 * pow (x, 3)
		+ 39 * pow (x, 2)
		- 26 * x
		- 24
	);
}
// Só pra constar, aqui estão as raízes da `f' nos intervalos pedidos:
// [-1, 0] = -0.4444444444444445
// [0, 1] = 0.8571428571428571

/// Derivada da função `f':
// f' (x) = 252*x^3 - 78*x^2 + 78*x - 26
double df (double x) {
	return (
		252 * pow (x, 3)
		- 78 * pow (x, 2)
		+ 78 * x
		- 26
	);
}

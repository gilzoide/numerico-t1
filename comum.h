#pragma once

#include <math.h>
#include <stdio.h>

// limite do erro, pra parada do cálculo
#define ERRO 0.000001

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

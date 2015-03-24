#pragma once

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// Limite do erro, pra parada do cálculo
#define ERRO 0.000001
// Máximo número de iterações
#define MAXITER 10000
// Valor de retorno pra uma falha
#define FALHOU HUGE_VAL

// Retorna máximo
double max (double a, double b);

// Pega erro, vendo que todos são iguais
double getErro (double x);

/// A função usada para os cálculos:
// f(x) = 63*x^4 - 26*x^3 + 39*x^2 - 26*x - 24
double f (double x);
// Só pra constar, aqui estão as raízes da `f' nos intervalos pedidos:
// [-1, 0] = -0.4444444444444445
// [0, 1] = 0.8571428571428571

/// Derivada da função `f':
// f' (x) = 252*x^3 - 78*x^2 + 78*x - 26
double df (double x);


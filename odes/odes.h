#ifndef __ODES_H__
#define __ODES_H__

#include <stdio.h>
#include <stdlib.h>

#include "../constants.h"
/// @brief Euler method for solving initial value problems of the form x' = f(x, t), x(t0) = x0
/// @param f The function that defines the ode x' = f(x, t).
/// @param t0 Initial time of integration
/// @param t1 Final time of integration
/// @param x0 Initial condition of the ivp
/// @param N Number of steps of integration
/// @return An array 2 * (N + 1) containing the list of pairs (t, phi(t)), where t are the steps of integration and phi(t) is the solution of the ode
double** euler(double f(double, double), double t0, double t1, double x0, int N);

/// @brief Taylor method of order 2 for solving initial value problems of the form x' = f(x, t), x(t0) = x0
/// @param f The function that defines the ode x' = f(x, t).
/// @param dfdt Time derivative of f (remember to apply the chain rule, e.g. dfdt = diff(f,x)*f + diff(f, t)). Note: I programmed this in this way in order to avoid NAN values due to cancellations.
/// @param t0 Initial time of integration
/// @param t1 Final time of integration
/// @param x0 Initial condition of the ivp
/// @param N Number of steps of integration
/// @return An array 2 * (N + 1) containing the list of pairs (t, phi(t)), where t are the steps of integration and phi(t) is the solution of the ode
double** taylor2(double f(double, double), double dfdt(double, double), double t0, double t1, double x0, int N);

#endif

#include <math.h>
#include <stdio.h>

#include "odes/odes.h"

double f(double x, double t);
double dfdt(double x, double t);

int main(void) {
  int N = 10;
  double **A = taylor2(f, dfdt, 0, 1, 0, N);
  for (int i = 0; i <= N; i++)
    printf("%g\t%g\n", A[i][0], A[i][1]);
  return 0;
}

double f(double x, double t) {
  return sqrt(x);
}

double dfdt(double x, double t) {
  return 0.5;
}

#include <stdio.h>

#include "odes/odes.h"

double f(double x, double t);

int main(void) {
  int N = 10;
  double **A = euler(f, 0, 3, 0.1, N);
  for (int i = 0; i <= N; i++)
    printf("%i- (%g, %g)\n", i, A[i][0], A[i][1]);
  return 0;
}

double f(double x, double t) {
  return x;
}

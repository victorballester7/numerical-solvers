#include "odes.h"

double** euler(double f(double, double), double t0, double t1, double x0, int N) {
  double step = (t1 - t0) / N;
  double** A = malloc((N + 1) * sizeof(double*));
  for (int i = 0; i <= N; i++) {
    A[i] = malloc(2 * sizeof(double));
    A[i][0] = t0 + i * step;
    if (i == 0)
      A[i][1] = x0;
    else
      A[i][1] = A[i - 1][1] + step * f(A[i - 1][1], A[i - 1][0]);
  }
  return A;
}

#include <math.h>
#include "utils.h"

void linspace(double* x, int n, double start, double end) {
    double step = (end - start) / (n - 1);
    for (int i = 0; i < n; i++) {
        x[i] = start + i * step;
    }
}

double f(double x) {
    return sin(2.0 * PI * x);
}


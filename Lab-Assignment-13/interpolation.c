#include <math.h>
#include "utils.h"

double lagrange_interpolation(double x, double* X, double* Y, int n) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        double term = Y[i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                term *= (x - X[j]) / (X[i] - X[j]);
            }
        }
        result += term;
    }
    return result;
}


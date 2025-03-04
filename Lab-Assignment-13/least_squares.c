#include <math.h>
#include "utils.h"

void least_squares_fit(double* X, double* Y, int n, int m, double* coeffs) {
    double A[M+1][M+1] = {0};
    double B[M+1] = {0};

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            A[i][j] = 0.0;
            for (int k = 0; k < n; k++) {
                A[i][j] += pow(X[k], i + j);
            }
        }

        B[i] = 0.0;
        for (int k = 0; k < n; k++) {
            B[i] += Y[k] * pow(X[k], i);
        }
    }

    // Solve system Ax = B (Gaussian Elimination - simplified)
    for (int i = 0; i <= m; i++) {
        for (int j = i+1; j <= m; j++) {
            double factor = A[j][i] / A[i][i];
            for (int k = i; k <= m; k++) {
                A[j][k] -= factor * A[i][k];
            }
            B[j] -= factor * B[i];
        }
    }

    for (int i = m; i >= 0; i--) {
        coeffs[i] = B[i];
        for (int j = i+1; j <= m; j++) {
            coeffs[i] -= A[i][j] * coeffs[j];
        }
        coeffs[i] /= A[i][i];
    }
}


/*
 * Lab 13 - Polynomial Interpolation & Least Squares Fitting
 * Written by Anwar Hossain Zahid
 * Department of Computer Science, Iowa State University
 */

#include <stdio.h>
#include <math.h>
#include "utils.h"

int main() {
    double X[N], Y[N];

    // Generate x values and f(x)
    linspace(X, N, 0.0, 1.0);
    for (int i = 0; i < N; i++) {
        Y[i] = f(X[i]);
    }

    // Write data to file for plotting
    FILE *file = fopen("data.txt", "w");
    if (!file) {
        perror("Error opening data file");
        return 1;
    }

    for (double x = 0; x <= 1.0; x += 0.01) {
        double pn = lagrange_interpolation(x, X, Y, N);

        double coeffs[M+1];
        least_squares_fit(X, Y, N, M, coeffs);

        double pm = 0.0;
        for (int j = 0; j <= M; j++) {
            pm += coeffs[j] * pow(x, j);
        }

        fprintf(file, "%lf %lf %lf %lf\n", x, f(x), pn, pm);
    }
    fclose(file);

    // Plot using Python
    system("python3 plot.py");

    return 0;
}


#include <math.h>
#include <stdio.h>
#include "matrix_utils.h"

double rayleigh_quotient_iteration(double A[SIZE][SIZE], double eigenvector[SIZE]) {
    random_vector(eigenvector);
    normalize(eigenvector);

    double Ax[SIZE];
    matrix_vector_multiply(Ax, A, eigenvector);
    double mu = dot_product(eigenvector, Ax);

    for (int iter = 0; iter < MAX_ITER; iter++) {
        double shifted[SIZE][SIZE];
        subtract_shift(A, shifted, mu);

        solve_linear_system(shifted, eigenvector, eigenvector);
        
        double norm = sqrt(dot_product(eigenvector, eigenvector));
        if (norm < 1e-10) {
            printf("Rayleigh Iteration - Vector collapsed to zero at iteration %d. Stopping.\n", iter);
            return NAN;
        }

        normalize(eigenvector);
        matrix_vector_multiply(Ax, A, eigenvector);
        mu = dot_product(eigenvector, Ax);
    }
    return mu;
}


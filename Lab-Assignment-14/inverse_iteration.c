#include <math.h>
#include "matrix_utils.h"

double inverse_iteration(double A[SIZE][SIZE], double mu, double eigenvector[SIZE]) {
    double shifted[SIZE][SIZE];
    subtract_shift(A, shifted, mu);

    random_vector(eigenvector);
    normalize(eigenvector);

    double Ax[SIZE];
    for (int iter = 0; iter < MAX_ITER; iter++) {
        solve_linear_system(shifted, eigenvector, eigenvector);
        normalize(eigenvector);
        matrix_vector_multiply(Ax, A, eigenvector);
    }

    return dot_product(eigenvector, Ax);
}


#include <math.h>
#include "matrix_utils.h"

double power_iteration(double A[SIZE][SIZE], double eigenvector[SIZE]) {
    random_vector(eigenvector);
    normalize(eigenvector);

    double Ax[SIZE], lambda_old = 0, lambda = 0;

    for (int iter = 0; iter < MAX_ITER; iter++) {
        matrix_vector_multiply(Ax, A, eigenvector);
        lambda = dot_product(eigenvector, Ax);
        normalize(Ax);
        for (int i = 0; i < SIZE; i++)
            eigenvector[i] = Ax[i];

        if (fabs(lambda - lambda_old) < TOL)
            break;

        lambda_old = lambda;
    }
    return lambda;
}


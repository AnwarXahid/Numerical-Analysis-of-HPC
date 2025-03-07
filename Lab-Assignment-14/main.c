#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix_utils.h"

int main() {
    srand(time(NULL));

    double L[SIZE][SIZE], A[SIZE][SIZE];
    generate_lower_triangular(L);
    compute_A(L, A);

    print_matrix("Matrix A", A);

    double eigenvector[SIZE];

    double lambda_power = power_iteration(A, eigenvector);
    printf("Power Iteration Eigenvalue: %.6f\n", lambda_power);

    double lambda_inverse = inverse_iteration(A, lambda_power - 1, eigenvector);
    printf("Inverse Iteration Eigenvalue: %.6f\n", lambda_inverse);

    double lambda_rayleigh = rayleigh_quotient_iteration(A, eigenvector);
    printf("Rayleigh Quotient Iteration Eigenvalue: %.6f\n", lambda_rayleigh);

    return 0;
}


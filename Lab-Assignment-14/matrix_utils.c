#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix_utils.h"

void generate_lower_triangular(double L[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j <= i; j++)
            L[i][j] = rand() % 10 + 1;
}

void compute_A(double L[SIZE][SIZE], double A[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++) {
            A[i][j] = 0;
            for (int k = 0; k <= i && k <= j; k++)
                A[i][j] += L[i][k] * L[j][k];
        }
}

void print_matrix(const char* name, double mat[SIZE][SIZE]) {
    printf("%s:\n", name);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%8.3f ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void random_vector(double v[SIZE]) {
    for (int i = 0; i < SIZE; i++)
        v[i] = (double)(rand() % 10 + 1);
}

void normalize(double v[SIZE]) {
    double norm = sqrt(dot_product(v, v));
    for (int i = 0; i < SIZE; i++)
        v[i] /= norm;
}

double dot_product(const double a[SIZE], const double b[SIZE]) {
    double sum = 0;
    for (int i = 0; i < SIZE; i++)
        sum += a[i] * b[i];
    return sum;
}

void matrix_vector_multiply(double result[SIZE], double mat[SIZE][SIZE], double vec[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        result[i] = 0;
        for (int j = 0; j < SIZE; j++) {
            result[i] += mat[i][j] * vec[j];
        }
    }
}

void subtract_shift(double mat[SIZE][SIZE], double shifted_mat[SIZE][SIZE], double mu) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            shifted_mat[i][j] = mat[i][j] - (i == j ? mu : 0);
}

void solve_linear_system(double A[SIZE][SIZE], double x[SIZE], double b[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        x[i] = b[i] / A[i][i];
        for (int j = 0; j < i; j++)
            x[i] -= A[i][j] * x[j] / A[i][i];
    }
}


#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

#define SIZE 6
#define TOL 1e-6
#define MAX_ITER 1000

void generate_lower_triangular(double L[SIZE][SIZE]);
void compute_A(double L[SIZE][SIZE], double A[SIZE][SIZE]);
void print_matrix(const char* name, double mat[SIZE][SIZE]);
void random_vector(double v[SIZE]);
void normalize(double v[SIZE]);

double dot_product(const double a[SIZE], const double b[SIZE]);
void matrix_vector_multiply(double result[SIZE], double mat[SIZE][SIZE], double vec[SIZE]);
void subtract_shift(double mat[SIZE][SIZE], double shifted_mat[SIZE][SIZE], double mu);
void solve_linear_system(double A[SIZE][SIZE], double x[SIZE], double b[SIZE]);

double power_iteration(double A[SIZE][SIZE], double eigenvector[SIZE]);
double inverse_iteration(double A[SIZE][SIZE], double mu, double eigenvector[SIZE]);
double rayleigh_quotient_iteration(double A[SIZE][SIZE], double eigenvector[SIZE]);

#endif


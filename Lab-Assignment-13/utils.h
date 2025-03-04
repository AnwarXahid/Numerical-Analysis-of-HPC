#ifndef UTILS_H
#define UTILS_H

#define N 20
#define M 5
#define PI 3.141592653589793

void linspace(double* x, int n, double start, double end);
double f(double x);
double lagrange_interpolation(double x, double* X, double* Y, int n);
void least_squares_fit(double* X, double* Y, int n, int m, double* coeffs);

#endif


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

double f(double x) {
    return exp(-100 * x * x) + sin(x);
}

double Simpson(double fa, double fm, double fb, double a, double b) {
    return (b - a) * (fa + 4 * fm + fb) / 6.0;
}

double AdaptiveInt(double a, double b, double TOL, double fa, double fb, double fm, int depth) {
    double h = (b - a) / 2.0;
    double c = (a + b) / 2.0;
    double x1 = (a + c) / 2.0;
    double x2 = (c + b) / 2.0;
    double f1 = f(x1);
    double f2 = f(x2);
    double left = Simpson(fa, f1, fm, a, c);
    double right = Simpson(fm, f2, fb, c, b);
    double whole = Simpson(fa, fm, fb, a, b);

    if (fabs((left + right) - whole) < 15 * TOL || depth > 20) {
        return left + right;
    } else {
        double result_left = 0.0, result_right = 0.0;

        #pragma omp parallel sections if(depth < 6)
        {
            #pragma omp section
            result_left = AdaptiveInt(a, c, TOL / 2.0, fa, fm, f1, depth + 1);
            #pragma omp section
            result_right = AdaptiveInt(c, b, TOL / 2.0, fm, fb, f2, depth + 1);
        }

        return result_left + result_right;
    }
}

int main(int argc, char *argv[]) {
    int threads = (argc > 1) ? atoi(argv[1]) : 1;

    omp_set_num_threads(threads);
    omp_set_nested(1);

    double a = -2.0, b = 4.0;
    double fa = f(a), fb = f(b), fm = f((a + b) / 2.0);
    double tol = 1e-6;

    double result;

    double start_time = omp_get_wtime();

    #pragma omp parallel
    {
        #pragma omp single nowait
        {
            result = AdaptiveInt(a, b, tol, fa, fb, fm, 0);
        }
    }

    double end_time = omp_get_wtime();

    printf("Threads: %d | Integral ≈ %.10f | Time = %.6fs\n", threads, result, end_time - start_time);
    return 0;
}


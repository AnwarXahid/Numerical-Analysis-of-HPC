/*
Anwar Hossain Zahid
PhD Student
Department of Computer Science
Iowa State University
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define N 1000000

void generate_vector_ones(double *x) {
    for (int i = 0; i < N; i++) x[i] = 1.0;
}

void generate_vector_range(double *x) {
    for (int i = 0; i < N; i++) x[i] = i + 1;
}

void serial_2norm(double *x) {
    double norm = 0.0;
    for (int i = 0; i < N; i++) {
        norm += x[i] * x[i];
    }
    norm = sqrt(norm);
    printf("Serial 2-norm: %.6f\n", norm);
}

void serial_maxnorm(double *x) {
    double max = fabs(x[0]);
    for (int i = 1; i < N; i++) {
        if (fabs(x[i]) > max) max = fabs(x[i]);
    }
    printf("Serial max-norm: %.6f\n", max);
}

void parallel_2norm_fine(double *x) {
    double norm = 0.0;
    #pragma omp parallel for reduction(+:norm)
    for (int i = 0; i < N; i++) {
        norm += x[i] * x[i];
    }
    norm = sqrt(norm);
    printf("Parallel (fine) 2-norm: %.6f\n", norm);
}

void parallel_maxnorm_fine(double *x) {
    double max = 0.0;
    #pragma omp parallel for reduction(max:max)
    for (int i = 0; i < N; i++) {
        if (fabs(x[i]) > max) max = fabs(x[i]);
    }
    printf("Parallel (fine) max-norm: %.6f\n", max);
}

void parallel_2norm_coarse(double *x) {
    double norm = 0.0;
    int num_threads = omp_get_max_threads();
    double partial_sums[num_threads];

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        partial_sums[tid] = 0.0;
        int chunk = N / num_threads;
        int start = tid * chunk;
        int end = (tid == num_threads - 1) ? N : start + chunk;

        for (int i = start; i < end; i++) {
            partial_sums[tid] += x[i] * x[i];
        }
    }

    for (int i = 0; i < num_threads; i++) norm += partial_sums[i];
    printf("Parallel (coarse) 2-norm: %.6f\n", sqrt(norm));
}

void parallel_maxnorm_coarse(double *x) {
    double max = 0.0;
    int num_threads = omp_get_max_threads();
    double partial_max[num_threads];

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        partial_max[tid] = 0.0;
        int chunk = N / num_threads;
        int start = tid * chunk;
        int end = (tid == num_threads - 1) ? N : start + chunk;

        for (int i = start; i < end; i++) {
            if (fabs(x[i]) > partial_max[tid])
                partial_max[tid] = fabs(x[i]);
        }
    }

    for (int i = 0; i < num_threads; i++)
        if (partial_max[i] > max) max = partial_max[i];

    printf("Parallel (coarse) max-norm: %.6f\n", max);
}

int main() {
    double *x = malloc(N * sizeof(double));

    printf("\n--- 2-NORM TEST (vector of 1s) ---\n");
    generate_vector_ones(x);
    serial_2norm(x);
    parallel_2norm_fine(x);
    parallel_2norm_coarse(x);

    printf("\n--- MAX-NORM TEST (vector 1 to N) ---\n");
    generate_vector_range(x);
    serial_maxnorm(x);
    parallel_maxnorm_fine(x);
    parallel_maxnorm_coarse(x);

    free(x);
    return 0;
}


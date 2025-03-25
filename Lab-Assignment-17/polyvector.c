#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    // Get the total number of processors available
    int num_procs = omp_get_num_procs();
    printf("Running on %d processor(s)\n", num_procs);

    // Set the number of threads to the number of processors
    omp_set_num_threads(num_procs);

    // Parallel region
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        printf("Thread %d is executing\n", thread_id);
    }

    return 0;
}


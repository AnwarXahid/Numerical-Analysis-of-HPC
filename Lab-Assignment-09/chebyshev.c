/**
* Anwar Hossain Zahid
 * Iowa State University
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OUTPUT_FILE "chebyshev_data.txt"
#define NUM_POINTS 100

/**
 * Evaluates the Chebyshev polynomial φ_i(x) using a switch statement.
 * @param i The polynomial index (0 ≤ i ≤ 5).
 * @param x The input value.
 * @return The evaluated value of φ_i(x).
 */
double chebyshev(int i, double x) {
    switch (i) {
        case 0: return 1;
        case 1: return x;
        case 2: return 2 * x * x - 1;
        case 3: return 4 * x * x * x - 3 * x;
        case 4: return 8 * x * x * x * x - 8 * x * x + 1;
        case 5: return 16 * x * x * x * x * x - 20 * x * x * x + 5 * x;
        default:
            fprintf(stderr, "Error: Polynomial degree out of range.\n");
            exit(1);
    }
}

/**
 * Computes the polynomial expansion pN(x) = Σ b_i * φ_i(x).
 */
double compute_pN(int N, double b[], double x) {
    double result = 0.0;
    for (int i = 0; i <= N; i++) {
        result += b[i] * chebyshev(i, x);
    }
    return result;
}

int main() {
    int N;
    double b[6];  // Coefficients for polynomials up to degree 5

    printf("\nEnter the polynomial degree (0-5): ");
    scanf("%d", &N);
    if (N < 0 || N > 5) {
        fprintf(stderr, "Invalid input! Degree must be between 0 and 5.\n");
        return 1;
    }

    // Read coefficients
    printf("Enter %d coefficient(s):\n", N + 1);
    for (int i = 0; i <= N; i++) {
        printf("b[%d]: ", i);
        scanf("%lf", &b[i]);
    }

    // Write data to file for plotting
    FILE *outfile = fopen(OUTPUT_FILE, "w");
    if (!outfile) {
        fprintf(stderr, "Error: Cannot create output file.\n");
        return 1;
    }

    for (int i = 0; i < NUM_POINTS; i++) {
        double x = -1.0 + 2.0 * i / (NUM_POINTS - 1);
        double y = compute_pN(N, b, x);
        fprintf(outfile, "%lf %lf\n", x, y);
    }

    fclose(outfile);
    printf("Results saved to %s\n", OUTPUT_FILE);

    // Call Python script to plot results
    system("python3 plot_chebyshev.py");

    return 0;
}

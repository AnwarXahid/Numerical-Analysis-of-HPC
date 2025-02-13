/**
 * Anwar Hossain Zahid
 * COM S 5250
 * Iowa State University
 */

#include <stdio.h>
#include <math.h>

#define E 2.718281828459  // Euler's constant
#define MAX_TERMS 20      // Number of terms in Taylor series expansion
#define OUTPUT_FILE "output.txt"

/**
 * Computes the factorial of a given integer n using recursion.
 * @param n The integer for which factorial is computed.
 * @return Factorial of n.
 */
long long factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

/**
 * Computes the exponential function e^x using the Taylor series expansion.
 * @param x The input value for which exp(x) is computed.
 * @return The approximate value of exp(x).
 */
double compute_exp(double x) {
    double sum = 1.0; // Start with the first term (1)
    for (int n = 1; n < MAX_TERMS; n++) {
        sum += pow(x, n) / factorial(n);
    }
    return sum;
}

int main() {
    FILE *outfile = fopen(OUTPUT_FILE, "w");

    if (outfile == NULL) {
        fprintf(stderr, "Error: Unable to create output file.\n");
        return 1;
    }

    printf("Computing exp(x) using Taylor series expansion...\n");
    printf("x\t\texp(x)\n");
    printf("---------------------------\n");

    // Compute exp(x) for x in [0, 1] with step size 0.02
    for (double x = 0.0; x <= 1.0; x += 0.02) {
        double exp_x = compute_exp(x);
//        printf("%0.2lf\t%0.6lf\n", x, exp_x);
        fprintf(outfile, "%0.2lf %0.6lf\n", x, exp_x);
    }

    fclose(outfile);
    printf("Results saved to %s\n", OUTPUT_FILE);

    return 0;
}

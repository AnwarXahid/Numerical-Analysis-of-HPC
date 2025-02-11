/*
 * Anwar Hossain Zahid
 * GTA, Iowa State University
 * COM S 525
 */

#include <stdio.h>
#include <math.h>

// Function to compute the factorial of an integer n
int compute_factorial(int n) {
    if (n < 0) {
        printf("Error: Factorial of a negative number doesn't exist.\n");
        return -1;
    }
    if (n == 0) {
        return 1;
    }
    return n * compute_factorial(n - 1);
}

// Function to compute the exponential of x using a series expansion
double compute_exponential(double x, int terms) {
    double sum = 1.0; // Initialize sum of series
    double term = 1.0; // Initialize first term
    for (int i = 1; i < terms; i++) {
        term *= x / i; // Compute next term
        sum += term; // Add next term to sum
    }
    return sum;
}

// Function to compute the natural logarithm of y using an iterative method
double compute_logarithm(double y, int max_iterations, double tolerance) {
    // Input validation
    if (max_iterations <= 0 || tolerance <= 0.0) {
        printf("Error: Invalid parameters (iterations or tolerance)\n");
        return -INFINITY;
    }
    
    if (y <= 0.0) {
        printf("Error: Logarithm of non-positive number is undefined\n");
        return -INFINITY;
    }
    
    // Handle special cases
    if (y == 1.0) return 0.0;                    // ln(1) = 0
    if (isnan(y)) return NAN;                    // ln(NaN) = NaN
    if (isinf(y) && y > 0) return INFINITY;      // ln(+∞) = +∞
    
    // Constants
    const double MIN_TOLERANCE = 1e-15;
    const double MAX_ITERATIONS_GUARD = 1000;
    const double LN2 = 0.693147180559945;  // ln(2)
    
    // Adjust parameters if needed
    tolerance = fmax(tolerance, MIN_TOLERANCE);
    max_iterations = (int)fmin(max_iterations, MAX_ITERATIONS_GUARD);
    
    // Initial guess computation
    double x;
    if (y > 2.0) {
        // For large numbers: use log2 approximation
        x = 0.0;
        double temp = y;
        while (temp >= 2.0) {
            temp *= 0.5;
            x += LN2;
        }
        x += (temp - 1.0); // Final adjustment
    } else if (y < 0.5) {
        // For small numbers: use negative log2 approximation
        x = 0.0;
        double temp = y;
        while (temp <= 0.5) {
            temp *= 2.0;
            x -= LN2;
        }
        x += (temp - 1.0); // Final adjustment
    } else {
        // For numbers close to 1: use y-1 approximation
        x = y - 1.0;
    }
    
    // Newton's method iteration
    double prev_x;
    int iterations = 0;
    
    do {
        prev_x = x;
        double exp_x = compute_exponential(x, 20);
        
        // Check for overflow in exp calculation
        if (isinf(exp_x) || isnan(exp_x)) {
            printf("Error: Numerical overflow in computation\n");
            return -INFINITY;
        }
        
        // Newton iteration: x = x - (e^x - y)/e^x = x - 1 + y/e^x
        x = x - 1.0 + y/exp_x;
        
        // Prevent infinite loops
        if (++iterations >= max_iterations) {
            printf("Warning: Maximum iterations reached\n");
            return x; // Return best approximation
        }
        
    } while (fabs(x - prev_x) >= tolerance);
    
    // Final validation
    if (isnan(x) || isinf(x)) {
        printf("Error: Numerical error in computation\n");
        return -INFINITY;
    }
    
    return x;
}


int main() {
    int n;
    double x, y;

    // Input values
    printf("Enter an integer n for factorial computation: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input for n.\n");
        return 1;
    }

    printf("Enter a real number x for exponential computation: ");
    if (scanf("%lf", &x) != 1) {
        printf("Invalid input for x.\n");
        return 1;
    }

    printf("Enter a real number y for logarithm computation: ");
    if (scanf("%lf", &y) != 1) {
        printf("Invalid input for y.\n");
        return 1;
    }

    // Compute factorial of n
    int fac_result = compute_factorial(n);
    if (fac_result != -1) {
        printf("Factorial of %d is %d\n", n, fac_result);
    }

    // Compute exponential of x
    double result = compute_exponential(x, 20);
    printf("Exponential of %.2f is %.2f\n", x, result);

    // Compute logarithm of y
    result = compute_logarithm(y, 100, 1e-10);
    if (result != -1) {
        printf("Logarithm of %.2f is %.2f\n", y, result);
    }

    return 0;
}

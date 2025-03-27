#include <stdio.h>
#include <math.h>

#define N 1000000  // Must be even
#define A 0.0
#define B M_PI

double f(double x) {
    return sin(x);  // Change as needed
}

int main() {
    if (N % 2 != 0) {
        printf("N must be even!\n");
        return 1;
    }

    double h = (B - A) / N;
    double sum = f(A) + f(B);

    for (int i = 1; i < N; i++) {
        double x = A + i * h;
        if (i % 2 == 0)
            sum += 2 * f(x);
        else
            sum += 4 * f(x);
    }

    double result = (h / 3) * sum;
    printf("Integral result (Serial Simpson): %.12f\n", result);
    return 0;
}


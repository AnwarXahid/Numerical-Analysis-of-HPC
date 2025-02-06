import numpy as np
import matplotlib.pyplot as plt


def gauss_elimination(A, b):
    n = len(b)
    A = np.array(A, float)
    b = np.array(b, float)

    # Forward elimination
    for i in range(n):
        # Pivoting
        max_row = np.argmax(np.abs(A[i:, i])) + i
        if i != max_row:
            A[[i, max_row]] = A[[max_row, i]]
            b[[i, max_row]] = b[[max_row, i]]

        # Eliminate
        for k in range(i + 1, n):
            factor = A[k, i] / A[i, i]
            A[k, i:] -= factor * A[i, i:]
            b[k] -= factor * b[i]

    # Back substitution
    x = np.zeros(n)
    for i in range(n - 1, -1, -1):
        x[i] = (b[i] - np.dot(A[i, i + 1:], x[i + 1:])) / A[i, i]

    return x


def least_square_approx(x, f, n):
    # Construct the Vandermonde matrix
    A = np.vander(x, n + 1)
    # Solve the normal equations A.T * A * c = A.T * f
    ATA = np.dot(A.T, A)
    ATf = np.dot(A.T, f)
    coefficients = gauss_elimination(ATA, ATf)
    return coefficients


if __name__ == "__main__":
    # Define the nodes and function values
    x = np.linspace(-np.pi, np.pi, 51)
    f = np.cos(x)
    n = 5

    # Find the least square approximation coefficients
    coefficients = least_square_approx(x, f, n)


    # Define the polynomial function p(x)
    def p(x):
        return np.polyval(coefficients, x)


    # Plot the results
    plt.plot(x, f, 'b-', label='cos(x)')
    plt.plot(x, p(x), 'r--', label='Least Squares Approximation')
    plt.legend()
    plt.xlabel('x')
    plt.ylabel('y')
    plt.title('Least Squares Approximation of cos(x)')

    # Save the figure to a file instead of showing it
    plt.savefig('least_squares_approximation.png')

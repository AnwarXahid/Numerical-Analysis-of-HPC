'''
Anwar Hossain Zahid
PhD Student
Department of Computer Science
Iowa State University
'''

import numpy as np
from math import cos


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


# Points and their corresponding cos values
points = [-0.1, -0.02, 0.02, 0.1]
values = [cos(x) for x in points]

# Set up the linear system to solve for coefficients a, b, c, d
A = [[x ** 3, x ** 2, x, 1] for x in points]
b = values

# Solve the linear system using gauss_elimination
coefficients = gauss_elimination(A, b)


# Define the polynomial function p(x)
def p(x):
    a, b, c, d = coefficients
    return a * x ** 3 + b * x ** 2 + c * x + d


# Measure the maximum error between f(x) and p(x) at the given points
errors = [abs(cos(x) - p(x)) for x in points]
max_error = max(errors)

# Print the results
print(f"Coefficients of the polynomial: {coefficients}")
print(f"Maximum error between f(x) and p(x) at the given points: {max_error}")
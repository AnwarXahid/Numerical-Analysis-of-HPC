'''
Anwar Hossain Zahid
PhD Student
Department of Computer Science
Iowa State University
'''

import math
import numpy as np


def sqrt(x, kmax=100, tol=1e-10):
    """
    Compute the square root of x using the Newton-Raphson method.

    Parameters:
    x (float): The number to compute the square root of.
    kmax (int): Maximum number of iterations.
    tol (float): Tolerance for convergence.

    Returns:
    float: The computed square root of x.
    """
    s = 1.0
    for k in range(kmax):
        s_old = s
        s = 0.5 * (s + x / s)
        if abs(s - s_old) < tol:
            break
    return s


def factorial(n):
    """
    Compute the factorial of n using recursion.

    Parameters:
    n (int): The number to compute the factorial of.

    Returns:
    int: The factorial of n.
    """
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial(n - 1)


def exponential(x, terms=20):
    """
    Compute the exponential of x using a series expansion.

    Parameters:
    x (float): The exponent.
    terms (int): Number of terms in the series expansion.

    Returns:
    float: The computed exponential of x.
    """
    e = 2.7182818284590451
    x0 = int(round(x))
    z = x - x0

    exp_x0 = e ** x0
    exp_x = exp_x0 * sum((z ** n) / factorial(n) for n in range(terms))

    return exp_x


def logn(x, kmax=100, tol=1e-10):
    """
    Compute the natural logarithm of x using an iterative method.

    Parameters:
    x (float): The number to compute the natural logarithm of.
    kmax (int): Maximum number of iterations.
    tol (float): Tolerance for convergence.

    Returns:
    float: The computed natural logarithm of x.
    """
    s = x  # initial guess
    for k in range(kmax):
        s_old = s
        s = s - 1 + x * exponential(-s)
        if abs(s - s_old) < tol:
            break
    return s


# Example usage of sqrt function
x = 24
result = sqrt(x)
print(f"The square root of {x} is approximately {result}.")
print(f"Comparison with math.sqrt: {math.sqrt(x)}")

# Example usage of factorial function
n = 5
result = factorial(n)
print(f"The factorial of {n} is {result}.")
print(f"Comparison with math.factorial: {math.factorial(n)}")

# Example usage of exponential function
x = 2.5
result = exponential(x)
print(f"The exponential of {x} is approximately {result}.")
print(f"Comparison with numpy.exp: {np.exp(x)}")

# Example usage of natural log function
x = 10
result = logn(x)
print(f"The natural logarithm of {x} is approximately {result}.")
print(f"Comparison with math.log: {math.log(x)}")

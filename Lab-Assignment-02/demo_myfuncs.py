'''
Anwar Hossain Zahid
PhD Student
Department of Computer Science
Iowa State University
'''


def sqrt(x, kmax=100, tol=1e-10):
    s = 1.0
    for k in range(kmax):
        s_old = s
        s = 0.5 * (s + x / s)
        if abs(s - s_old) < tol:
            break
    return s


def factorial(n):
    s = 1
    for k in range(1, n):
        s = s * (k + 1)
    return s


def exponential(x, terms=20):
    e = 2.7182818284590451
    x0 = int(round(x))
    z = x - x0

    exp_x0 = e ** x0
    exp_x = exp_x0 * sum((z ** n) / factorial(n) for n in range(terms))

    return exp_x


def logn(x, kmax=100, tol=1e-10):
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

# Example usage of factorial function
n = 5
result = factorial(n)
print(f"The factorial of {n} is {result}.")

# Example usage of exponential function
x = 2.5
result = exponential(x)
print(f"The exponential of {x} is approximately {result}.")

# Example usage of natural log function
x = 10
result = logn(x)
print(f"The natural logarithm of {x} is approximately {result}.")

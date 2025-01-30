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



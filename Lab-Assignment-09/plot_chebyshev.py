 #
 # Anwar Hossain Zahid
 # Iowa State University
 #

import numpy as np
import matplotlib.pyplot as plt

# Load computed data
data = np.loadtxt("chebyshev_data.txt")
x_values, y_values = data[:, 0], data[:, 1]

# Plot the polynomial
plt.figure(figsize=(8, 5))
plt.plot(x_values, y_values, linestyle='-', marker='o', color='b', label="Chebyshev Approximation")
plt.xlabel("x", fontsize=12)
plt.ylabel("pN(x)", fontsize=12)
plt.title("Chebyshev Polynomial Approximation", fontsize=14)
plt.legend()
plt.grid(True, linestyle='--', alpha=0.6)

# Save instead of displaying
plt.savefig("chebyshev_plot.png", dpi=300, bbox_inches="tight")
print("Plot saved as chebyshev_plot.png")

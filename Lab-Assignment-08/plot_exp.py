import matplotlib

matplotlib.use("Agg")  # Use a non-GUI backend to avoid display issues

import matplotlib.pyplot as plt
import numpy as np

# Load computed data from file
data = np.loadtxt("output.txt")

x_values, y_values = data[:, 0], data[:, 1]

# Plot the computed exponential function
plt.figure(figsize=(8, 5))
plt.plot(x_values, y_values, marker='o', linestyle='-', color='b', label="Computed exp(x)")
plt.xlabel("x", fontsize=12)
plt.ylabel("exp(x)", fontsize=12)
plt.title("Exponential Function Approximation using Taylor Series", fontsize=14)
plt.legend()
plt.grid(True, linestyle='--', alpha=0.6)

# Save the figure instead of displaying it
plot_filename = "exp_plot.png"
plt.savefig(plot_filename, dpi=300, bbox_inches="tight")

print(f"Plot saved as {plot_filename}")

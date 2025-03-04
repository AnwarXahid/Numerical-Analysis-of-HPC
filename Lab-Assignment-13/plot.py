import numpy as np
import matplotlib.pyplot as plt

# Load data from file
data = np.loadtxt("data.txt")
x, fx, pn, pm = data.T

# Create plot
plt.figure(figsize=(10, 6))
plt.plot(x, fx, label="f(x) = sin(2πx)", color='black', linewidth=2)
plt.plot(x, pn, label="Interpolation p19(x)", linestyle='--')
plt.plot(x, pm, label="Least Squares p5(x)", linestyle=':')
plt.legend()
plt.xlabel("x")
plt.ylabel("y")
plt.grid(True, linestyle='--', alpha=0.5)

# Save directly to file (no display)
plt.savefig("interpolation_plot.png", dpi=300, bbox_inches="tight")

print("Plot saved as interpolation_plot.png")


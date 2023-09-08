import numpy as np
import matplotlib.pyplot as plt

# Load data
data = np.loadtxt("test_output.txt")

# Plot data
plt.plot(data[:,0], data[:,1])
plt.title("u(x)")
plt.xlabel("x")
plt.ylabel("u(x)")
plt.savefig("u(x).png")
plt.show()
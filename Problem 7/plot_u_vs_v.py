import numpy as np
import matplotlib.pyplot as plt

u_data = np.loadtxt("u_data.txt")
plt.plot(u_data[:,0], u_data[:,1], label="u(x)",linewidth=4)

# Generate exponential list from 10 to 1 000 000
ns = [10**i for i in range(1, 7)]
for n in ns:
    data = np.loadtxt(f"general_algorithm_{n}steps.txt")

    # Plot data
    plt.plot(data[:,0], data[:,1], "--", label=f"n = {n}")

plt.title(r"u(x) $\approx$ v(x;n)")
plt.xlabel("x")
plt.ylabel(r"u $\approx$ v")
plt.legend()
plt.savefig("u_vs_v.pdf")
plt.show()
import os
import numpy as np
import matplotlib.pyplot as plt

plt.figure(figsize=(10,5))

data = np.loadtxt("1.dat")

plt.plot(data[0:len(data)],data[2:len(data)])

plt.title("Solución")
plt.xlabel('X')
plt.ylabel('Y')

plt.savefig("img.png")

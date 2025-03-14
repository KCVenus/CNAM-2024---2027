import numpy as np
import matplotlib.pyplot as plt
f = 2
phi = np.pi/3
A = 3 # hauteur de la porte
m = 4 # centre de la porte
N = 5 # largeur de la porte
n = np.arange(0, 10, 1)

z = A*(np.abs((n-m)/N ) < 0.5)
 
plt.figure(figsize=(8,4))
plt.plot(n, z, label="sinusoïde")
plt.legend()
plt.xlabel("$t$")
plt.ylabel("$y(t)$")
plt.title("Une belle sinusoïde")
plt.show()
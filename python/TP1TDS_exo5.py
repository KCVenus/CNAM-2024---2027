import numpy as np
import matplotlib.pyplot as plt

n = np.arange(-10, 10, 0.001)
sinc = np.sinc(n/np.pi)

plt.plot(sinc)
plt.show()
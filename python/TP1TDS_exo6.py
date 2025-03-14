import numpy as np
import matplotlib.pyplot as plt
    
n = np.arange(-10, 10, 0.1)
sin = np.sin(n)
cos = np.cos(n)
    
axes = plt.axes(projection="3d")
axes.plot(n, sin, cos)
plt.show()

# Une ligne qui commence par le symbole # est un commentaire et n'est donc pas exécutée
# Import du module 'numpy', que l'on utilisera dans la suite du code 'np' pour faire plus court
import numpy as np
# Import du sous-module 'pyplot' du module 'matplotlib', et renommage en 'plt'
import matplotlib.pyplot as plt


plt.show()


def dessinerSignal(t):
    x = signal(t)
    plt.xlabel("$t$")
    plt.ylabel("$x(t)$")
    plt.plot(t, x, label="sinusoïde")

    
def signal(t):
    f = 4
    A = 1
    return A*np.sin(2*np.pi*f*t)

    
def echantillonnage(fe):
    t = np.arange(0, 1.5, 1/fe)
    x = signal(t)
    plt.plot(t, x, "ro--")
    
def main():
    t = np.arange(0, 1.5, 0.01)
    dessinerSignal(t)
    echantillonnage(12)
    echantillonnage(6)
    echantillonnage(3)
    
    
if __name__ == "__main__":
    main()    
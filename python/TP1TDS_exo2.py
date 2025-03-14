# Une ligne qui commence par le symbole # est un commentaire et n'est donc pas exécutée
# Import du module 'numpy', que l'on utilisera dans la suite du code 'np' pour faire plus court
import numpy as np
# Import du sous-module 'pyplot' du module 'matplotlib', et renommage en 'plt'
import matplotlib.pyplot as plt
# Abscisses sur lesquelles sera calculée la sinusoïde : un point tous les 0,1 s entre 0 et 10 s
t = np.arange(0, 10, 0.001)
# Fréquence de la sinuoïde
f = 2
phi = np.pi/3
A = 2
a = 0.5
# Sinusoïde : c'est tout simple, il suffit d'écrire l'expression mathématique
y = A*np.e**(-a*t)*np.sin(2*np.pi*f*t)
# Création d'une figure, dont on définit la taille
plt.figure(figsize=(8,4))
# Affichage de la sinusoïde (dans la figure créée)
plt.plot(t, y, label="sinusoïde")
# Légende
plt.legend()
# Axes
plt.xlabel("$t$")
plt.ylabel("$y(t)$")
# Titre
plt.title("Une belle sinusoïde")
# Affichage (pas toujours nécessaire, mais parfois c'est indispensable)
plt.show()
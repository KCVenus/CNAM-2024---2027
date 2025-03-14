import numpy as np
import matplotlib.pyplot as plt
import scipy.io.wavfile as wav

pluie = wav.read("./pluie.wav")
print(pluie)

piste = [echantillon[0] for echantillon in pluie[1]]


# print(piste)
plt.plot(piste)
plt.show()
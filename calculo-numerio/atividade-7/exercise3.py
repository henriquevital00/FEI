import numpy as np
from scipy.integrate import quad

x = np.linspace(1, 2, 5)
y = 1 / (1 + np.e**x)
l = np.trapz(y, x)
f = lambda x: 1 / (1 + np.exp(x))
var = quad(f, 1, 2)
erro = np.abs(l - var[0])
print("Trapezio: " + str(l))
print("Result: " + str(var[0]))
print("Erro: " + str(erro))

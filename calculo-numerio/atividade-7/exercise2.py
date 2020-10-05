#!/usr/bin/env python3

import sympy as sy
import numpy as np
from scipy.interpolate import lagrange
from numpy.polynomial.polynomial import Polynomial
from scipy.interpolate import lagrange

n = 3
x = [1, 7, 14]
y = [10.5, 17.7, 35.2]
x = np.array(x)
y = np.array(y)
poly = lagrange(x, y)
Polynomial(poly).coef
print(poly)

var = Polynomial(poly).coef

print("For x = 4 " + str(poly(4)))

a = np.poly1d(np.polyfit(x, y, 2))
distance = np.roots(a - 24)

print("Para R$24,00 o passageiro percorrerá a distancia de " +
      str(distance[1]) + " km")

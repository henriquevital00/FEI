#!/usr/bin/env python

import matplotlib as mpl
import numpy as np
import matplotlib.pyplot as plt
import sympy as sp
from scipy.optimize import fsolve
import math as mt

plt.interactive(True)

t = sp.Symbol('t')

def y(x):
    return mt.sin(x) - x**2 - x + 2

def f(x):
    return np.sin(x)

def orint(array):
    output = ""
    for i in range(len(array)):
        output += f'{array[i]:.3f} '

    return output

def g(x):
    return - x**2 - x + 2

def equation(x):
    return sp.sin(x) + x**2 + x - 2

def Newton_Raphson(x0):
    tolerance = 0.000001
    d = sp.diff(equation(t), t)
    for i in range(5):
        x1 = x0 - (y(x0) / d.doit().subs({t: x0}))
        n = abs(x1 - x0)
        if n < tolerance:
            break
        x0 = x1
    return x1


x = np.linspace(-4, 4, 20)
y1 = f(x)
y2 = g(x)


raiz_1 = fsolve(y, -2.5)
raiz_2 = fsolve(y, 0.5)

print(f'fsolve:')
print(f'Raíz no intervalo ]-3, -2[ = {raiz_1[0]:.5f}')
print(f'Raíz no intervalo ]0, 1[ = {raiz_2[0]:.5f}')


xi = -2.5
xr1 = Newton_Raphson(xi)

xi = 0.5
xr2 = Newton_Raphson(xi)

print(f'NEWTON-RAPHSON raizes:')
print(f'Raíz no intervalo ]-3, -2[ = {xr1:.5f}')
print(f'Raíz no intervalo ]0, 1[ = {xr2:.5f}')

equation_fx = plt.plot(x, y1)
equation_gx = plt.plot(x, y2)

plt.setp(equation_fx, color='red', linewidth=3, linestyle='--')
plt.setp(equation_gx, color='blue', linewidth=3, linestyle=':')

plt.grid(True)
plt.show(block=True)


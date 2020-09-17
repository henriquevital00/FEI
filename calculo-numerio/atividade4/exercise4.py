#!/usr/bin/env python3

from sympy import *
import numpy as np
x = np.array([i for i in range(-5, 6, 1)]).reshape((1, 11))
y = (x + 1)**2 - np.exp(x)
print(x)
print(y)
print("\n")

x = Symbol('x')


def NewtonsMethod(x0):
    tolerance = 0.000001
    d = diff(f(x), x)
    while True:
        x1 = x0 - (f(x0) / d.doit().subs({x: x0}))
        t = abs(x1 - x0)
        if t < tolerance:
            break
        x0 = x1
    return x1


def f(x):
    return x**3 - 3 * x**2 + 6 * x - 15


xi = 3.5
xr = NewtonsMethod(xi)
print('xi: ', xi)
print('x0: ', N(xr))
print("f(x0) = ", N(xr**3 - 3 * xr**2 + 6 * xr - 15))
xi = 4.5
xr = NewtonsMethod(xi)
print('xi: ', xi)
print('x0: ', N(xr))
print("f(x0) = ", N(xr**3 - 3 * xr**2 + 6 * xr - 15))

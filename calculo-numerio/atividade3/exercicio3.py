#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np
import sympy
from math import *

def function(x):
    return (x**5) - (3.5 * (x ** 4)) + (2.75 * (x ** 3)) + (2.125 * (x ** 2)) - (3.975 * x) + 1.25

x = np.linspace(-2, 4)
y = function(x)

plt.plot(x, y)
plt.show()

coef = [1, -3.5, 2.75, 2.125, -3.975, 1.25]
rax = np.roots(coef)
print(rax)


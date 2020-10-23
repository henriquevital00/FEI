#!/usr/bin/env python3

import numpy as np
import matplotlib.pyplot as plt
x = np.array([1, 2, 3, 4])
y = np.array([2.50, 3.83, 4.96, 6.00])
n = np.size(x)
Sx = np.sum(x)
Sy = np.sum(y)
Sxy = np.sum(x * y)
Sxx = np.sum(x * x)
a1 = (n * Sxy - Sx * Sy) / (n * Sxx - Sx**2)
a0 = (Sxx * Sy - Sxy * Sx) / (n * Sxx - Sx**2)
plt.scatter(x, y, color="b", marker="o", s=50)
y_pred = a0 + a1 * x
print("y = " + str(a1) + "x +" + str(a0))
plt.plot(x, y_pred, color="r")
plt.xlabel('x', fontsize=15)
plt.ylabel('y', fontsize=15)
plt.show()


def Residuo(x, y, b0, b1):
    n = len(y)
    RS = 0
    for i in range(0, n):
        y_pred = a0 + a1 * x[i]
        RS = RS + (y[i] - y_pred)**2
    return RS


print("Resultado do residuo: " + str(Residuo(x, y, a0, a1)))

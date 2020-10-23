#!/usr/bin/env python3
import numpy as np

x = np.array([i for i in range(-4, 5, 1)]).reshape((1,9))
y = np.cos(x) + x**2 +2 * x - 2
print(x)
print(y)

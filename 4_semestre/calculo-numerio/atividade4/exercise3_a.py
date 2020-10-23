#!/usr/bin/env python3
import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import fsolve

x = np.linspace(-4, 5, 800)
y = np.sin(x)
y1 = -2.5 + 5 * x
plt.plot(x, y, 'r')
plt.plot(x, y1, 'b')
plt.show()

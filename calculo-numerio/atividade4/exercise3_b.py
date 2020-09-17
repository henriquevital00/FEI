#!/usr/bin/env python3
import numpy as np
from scipy.optimize import fsolve


def function(x):
    return x - 0.2 * np.sin(x) - 0.5


menor_raiz = fsolve(function, 0.5)
print(menor_raiz)

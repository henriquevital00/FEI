#!/usr/bin/env python3

import sympy as sy
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

X = [1, 2, 3, 4]
numpy_array_x = np.array(X)
y = [15.4, 10.8, 7.5, 5.3]
log_of_y = np.log(y)
numpy_array_x = numpy_array_x.reshape(-1, 1)

model = LinearRegression().fit(numpy_array_x, log_of_y)

var = model.coef_

var2 = np.exp(model.intercept_)

y2 = var2 * np.exp(var * X)

var = np.exp(var)

print("{:.3f}*({:.3f})^x".format(var2, var[0]))

plt.plot(numpy_array_x, y2)
plt.show()

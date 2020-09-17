#!/usr/bin/env python3

import sympy as sy
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

X = np.array([2, 3, 4, 5, 7, 10])
y = np.array([5.2, 7.8, 10.7, 13, 19.3, 27.5])

X = X.reshape(-1, 1)
modelo = LinearRegression().fit(X, y)
print(modelo.intercept_)
print(modelo.coef_)
plt.scatter(X, y)
plt.plot(X, modelo.predict(X), color='red')
# valor de corrente para tensao = 3.5
yr = modelo.intercept_ + modelo.coef_ * 3.5
print("valor de corrente para tensao = 3.5: " + str(yr))
#valor de tensao para o valor da corrente em 15
x = sy.Symbol('x')
y = modelo.intercept_ + modelo.coef_ * x - 15
print("valor de tensao para o valor da corrente em 15: " + str(sy.solve(y)))
print("Residuos: " + str(modelo._residues))

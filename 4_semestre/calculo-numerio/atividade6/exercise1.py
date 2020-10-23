import sympy as sy
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
X = [400, 500, 600, 700, 750]
X = np.array(X)
y = [600, 1050, 1440, 1900, 2120]
X = X.reshape(-1, 1)
modelo = LinearRegression().fit(X, y)
print(modelo.intercept_)
print(modelo.coef_)
plt.scatter(X, y)
plt.plot(X, modelo.predict(X), color='red')
plt.show()

print("Residuo: " + str(modelo._residues))
# valor de y para x=800
yr = modelo.intercept_ + modelo.coef_ * 800
print("Para r=800 p=" + str(yr))
#valor de x para y =1650
x = sy.Symbol('x')
y = modelo.intercept_ + modelo.coef_ * x - 1650
print("Para P=1650 R=" + str(sy.solve(y)))

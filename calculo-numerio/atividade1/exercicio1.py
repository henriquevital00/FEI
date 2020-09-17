import matplotlib.pyplot as plt
import numpy as np
import sympy

#Exercicio 1
#plot
def function(x):
    return ((x+1)**(2/3))*((x-3)**2)

x = np.linspace(-4, 4, 50)
y = function(x)

plt.plot(x, y)
plt.grid()
plt.show()

#derivada 1 ordem
x = sympy.Symbol('x')
y = function(x)

print(sympy.diff(y, x))
print(sympy.diff(y, x, 3))

y=((x+1)**(2/3))*((x-3)**2)
print(sympy.integrate(y, x))
print(sympy.integrate(y, (x, -1, 2 )))


from math import pow
from math import sqrt
from math import cos
from  sympy import *

#Exercicio 2
def equation(x):
    return (pow(x, 2) - 2*x)/cos(x)

print(equation(sqrt(5)))

x = symbols('x')
eq = ((x**2) - 2*x)/cos(x)
print(limit(eq, x, 9))

print(diff(eq))

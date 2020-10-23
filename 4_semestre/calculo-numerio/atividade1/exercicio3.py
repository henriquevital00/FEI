from sympy import *
from math import *
import numpy as np

#Exercicio 3
A = np.array([[1, 0, 1], [1, 2, 3], [1, 2, 4]])
B = np.array([[3, 1, 4], [1, 2, 1], [3, 1, 1]])

print("Determinante: " + str(np.linalg.det(A)))
print("Inversa: " + str(np.linalg.inv(B)))
print("Transposta: " + str(np.matrix.transpose(A)))
print("AxB: " + str(A*B))
print("Ax-4B: " + str(A*(-4*B)))


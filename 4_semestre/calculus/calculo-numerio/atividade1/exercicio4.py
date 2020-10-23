import numpy  as np

#Exercicio 4
A = np.zeros((6, 3))
B = np.arange(1, 7).reshape(6, 1)
A[:] = B

print("A: " + str(A))

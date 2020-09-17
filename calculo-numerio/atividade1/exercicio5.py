import numpy as np

#Exercicio 5
matrix = np.random.randint(0, 2, (10, 10))

print("Matrix: " + str(matrix))

sum = np.sum(matrix, axis=0)

print("Soma de colunas: " + str(sum))
print("Coluna de maior soma: " + str(np.argmax(sum)))

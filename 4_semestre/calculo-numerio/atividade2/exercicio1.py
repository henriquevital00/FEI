import numpy as np

A = np.matrix([[3, 5, 1], [2, 2, 2], [4, 7, 3]])
B = ([1], [3], [0])

result = np.linalg.inv(A) * B

print(result)

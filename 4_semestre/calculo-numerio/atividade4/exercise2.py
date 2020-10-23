#!/usr/bin/env python3
import numpy as np

matrix = np.matrix([[7 / 100, 8 / 100, 9 / 100], [7 / 100, 8 / 100, 1 / 10],
                    [1, 1, 1]])
y = np.matrix([[2830], [2960], [35000]])

result = np.linalg.solve(matrix, y)
print(result)

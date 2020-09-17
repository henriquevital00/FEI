#!/usr/bin/env python3

import numpy as np

matrix = np.matrix([[50, 200, 160], [90, 100, 80], [180, 250, 120]])
y = np.matrix([[11700], [7000], [14800]])

print(np.linalg.solve(matrix, y))

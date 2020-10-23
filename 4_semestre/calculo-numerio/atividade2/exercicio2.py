#!/usr/bin/env python3

import numpy as np

A = np.matrix([[1, 1, 1, 1, 1], [1, 2, 3, 4, 5], [1, 3, 6, 10, 15], [1, 4, 10, 20, 35], [1, 5, 15, 35, 70]])
B = ([15], [35], [70], [126], [210]) 

result = np.linalg.inv(A) * B

print(result)


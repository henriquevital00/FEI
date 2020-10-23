#!/usr/bin/env python

import numpy as np
A=np.matrix([[200,100,500], [250,120,400], [400,80,600]])
B=([[495.00],[532.50],[585.00]])

result=np.linalg.inv(A)*B
print(result[1])

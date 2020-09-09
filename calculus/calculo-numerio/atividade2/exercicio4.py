#!/usr/bin/env python3

#indeterminado pois a conta não foi totalmente resolvida

import numpy as np
import sympy
from sympy.abc import x, y, z, t

system=sympy.Matrix(( (2,8,4,0,-1), (4,-6,-2,-10, -14), (6, -14, 2, -10, -16), (0,2,-2,-2,-2) ))
print(sympy.solve_linear_system(system, x, y, z, t))


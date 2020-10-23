#!/usr/bin/env python3

import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from matplotlib import pyplot as plt
from sklearn.metrics import r2_score

data = pd.read_csv('./concrete_data.csv', header=(0))
ylabel = data.columns[-1]
data = data.to_numpy()
nrow, ncol = data.shape
y = data[:, -1]
X = data[:, 0:ncol - 1]

p = 0.2  # fracao e elementos no conjnto de teste
x_train, x_test, y_train, y_test = train_test_split(X,
                                                    y,
                                                    test_size=p,
                                                    random_state=42)

im = LinearRegression()
im.fit(x_train, y_train)
y_predidction = im.predict(x_test)

img = plt.plot(y_predidction, y_test, "bo")
plt.show()

R2 = r2_score(y_test, y_predidction)

print("R2: ", R2)

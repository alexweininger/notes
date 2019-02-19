import numpy as np

a = [-0.469, 0.469, -0.207, 0.207]
x1 = [0.5, 0.5, -1, 1]
x2 = [-1, 0, -1, 0.5]
b = -0.195

def calc(x):

	s = 0
	for i in range(len(a)):
		s += a[i] * np.matmult([x, x2[i]])

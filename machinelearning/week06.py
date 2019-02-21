import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from sklearn import decomposition

np.random.seed(91)

X = np.random.rand(200)


# gaussian noise to make football shape lol wut
X= np.random.randn(200) + 2*X
Y = np.random.randn(200) + 2*X
Z = np.random.randn(200) + 2*X

data = ((X, Y, Z))
fig = plt.figure()

ax = fig.add_subplot(111, projection='3d')
ax.scatter(X, Y, Z, c='r')


pca_model = decomposition.PCA(n_components=3)
variance = pca_model.fit(data)

print(variance)
print(pca_model.explained_variance_)
print(pca_model.explained_variance_ratio_)
print(pca_model.explained_variance_ratio_.cumsum())

plt.show()

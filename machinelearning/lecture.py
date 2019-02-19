import numpy as np

a = np.random.choice(10,20)
print(a)
print(a[3:6])

random = np.random.randint(10)
print(random)

print(a[random:random + 3])


print(np.random.choice(a, 3, replace=False)) # randomly pick 3 values from array

b = np.reshape(a, [5, 4])
print(b)
print(b[2:])

# w(w0, w1, w2)
# x(1, x1, x2) # 1 is just a placeholder

row = b[2]

row = np.concatenate(([1], row))

print(row)

w = np.random.random_sample(5)
print(w)

result = np.multiply(row, w)
print(result)

print(np.sum(result))

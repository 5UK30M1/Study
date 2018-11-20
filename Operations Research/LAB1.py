import matplotlib.pyplot as plt
import numpy as np
import math

def F1(x):
    return (x - 15/2)**2 + 15 * x

def F2(x):
    return (x - 15/2)**2 + 15 * x**2

def F3(x):
    return (x - 15/2)**2 + np.sin(15 * x)

def x_opt(x,n):
    Fm = [F1(x[0]),F2(x[0]),F3(x[0])]
    for i in range(1,n):
        if (Fm[0] > F1(x[i])):
            Fm[0] = F1(x[i])
        if (Fm[1] > F2(x[i])):
            Fm[1] = F2(x[i])
        if (Fm[2] > F3(x[i])):
            Fm[2] = F3(x[i])
    return Fm


def func1(a, b, n):
    x = []
    for i in range(0,n):
        x.insert(i,a + i*(b -a) / n)
    return x

def func2t(a, b, n):
    iter = (b - a) / n
    ak = []
    bk = []
    x = []
    i = 1
    k = 1
    while(i < n):
        ak.insert(i,a + i * iter)
        x.insert(k,a + i * iter)
        k += 1
        bk.insert(i,b - i * iter)
        x.insert(k,b - i * iter)
        k += 1
        i += 1
        print(k)
    return x

def func2(a, b, n):
    iter = (b - a) / n
    ak = []
    bk = []
    i = 1
    k = 1
    while(i < n):
        ak.insert(i,a + i * iter)
        bk.insert(i,b - i * iter)
        i += 1
    return x

#print("input n:")
n = 100

#print("input a:")
a = -15.0

#print("input b:")
b = 15.0

x = np.linspace(a, b, 100)

x2t = func2t(a, b, n)

x1 = func1(a, b, n)
x_opt1 = x_opt(x1, n)
print(x_opt1)

x2 = func2(a, b, n)
x_opt2 = x_opt(x2, n)
print(x_opt2)

k = []
z1 = []
z2 = []
z3 = []


for i in range(1,21):
    k.insert(i,i)
    z1.insert(i, x_opt1[0] - x1[i])


plt.plot(x, F1(x), label='F1 (X) = (X- N / 2)^2 + N * X')
plt.plot(x, F2(x), label='F2 (X) = (X- N / 2)^2 + N * X^2')
plt.plot(x, F3(x), label='F3 (X) = (X- N / 2)^2 + sin (N * X)')

plt.xlabel('x label')
plt.ylabel('y label')

plt.title("Function Graph")

plt.legend()

plt.show()


plt.plot(k, z1, 'ro',label='Z')

plt.xlabel('Z label')
plt.ylabel('k labal')

plt.title("Graph of Z(k)")

plt.legend()

plt.show()


plt.plot(range(0,198), x2t, label='Xmin')

plt.xlabel('x label')
plt.ylabel('y label')

plt.title("Function Graph")

plt.legend()

plt.show()

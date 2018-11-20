import matplotlib.pyplot as plt
import numpy as np
import math

def F1(x):
    return (x - 15)**2 + 15 * x

def F2(x):
    return (x - 15)**2 + 15 * x**2

def F3(x):
    return (x - 15)**2 + np.sin(15 * x)

def MPD(f, a, b, eps):
    xf = []
    i=0
    while abs(b - a) > eps:
        x = (a + b) / 2.0
        fx = f(x)
        fa = f(a)
        xf.insert(i,x)
        ++i
        if (fx < 0 and fa < 0) or (fx > 0 and fa > 0):
            a = x
        else:
            b = x
    return [x,xf]


def goldenSectionSearch(f, l, r, eps):
    phi = (1 + math.sqrt(5)) / 2
    resphi = 2 - phi
    x1 = l + resphi * (r - l)
    x2 = r - resphi * (r - l)
    f1 = f(x1)
    f2 = f(x2)
    xf = []
    i = 0
    while (abs(r - l) > eps):
      if (f1 > f2):
        r = x2
        x2 = x1
        f2 = f1
        x1 = l + resphi * (r - l)
        f1 = f(x1)
      else:
        l = x1
        x1 = x2
        f1 = f2
        x2 = r - resphi * (r - l)
        f2 = f(x2)
      ++i
      xf.insert(i, (x1 + x2) / 2)
    return [(x1 + x2) / 2, xf]

eps = 0.001

n = 8

a = 0.0

b = 45.0

x = np.linspace(a, b, 100)

print("Xort MPD")
print(MPD(F1, a, b, eps)[0])
print(MPD(F2, a, b, eps)[0])
print(MPD(F3, a, b, eps)[0])

print("Xort GS")
print(goldenSectionSearch(F1, a, b, eps)[0])
print(goldenSectionSearch(F2, a, b, eps)[0])
print(goldenSectionSearch(F3, a, b, eps)[0])

plt.plot(x, F1(x), label='F1 (X) = (X- N)^2 + N * X')
plt.plot(x, F2(x), label='F2 (X) = (X- N)^2 + N * X^2')
plt.plot(x, F3(x), label='F3 (X) = (X- N)^2 + sin (N * X)')

plt.xlabel('x label')
plt.ylabel('y label')

plt.title("Function Graph")

plt.legend()

plt.show()

xf = MPD(F1,a,b,eps)[1]
plt.plot(range(0, len(xf)), xf, 'ro')
plt.xlabel('x label')
plt.ylabel('y label')
plt.title("MPD")
plt.show()

xf = goldenSectionSearch(F1,a,b,eps)[1]
plt.plot(range(0, len(xf)), xf, 'ro')
plt.xlabel('x label')
plt.ylabel('y label')
plt.title("goldenSectionSearch")
plt.show()

z = [[], [], []]
for i in range(0, 20):
    z[0].insert(i, goldenSectionSearch(F1, a, b, eps)[0] -
                goldenSectionSearch(F1, a, b, eps)[1][i])
    z[1].insert(i, goldenSectionSearch(F2, a, b, eps)[0] -
                goldenSectionSearch(F2, a, b, eps)[1][i])
    z[2].insert(i, goldenSectionSearch(F3, a, b, eps)[0] -
                goldenSectionSearch(F3, a, b, eps)[1][i])
plt.plot(range(0, len(z[0])), z[0], label='F1 (X) = (X- N)^2 + N * X')
plt.plot(range(0, len(z[1])), z[1], label='F2 (X) = (X- N)^2 + N * X^2')
plt.plot(range(0, len(z[2])), z[2], label='F3 (X) = (X- N)^2 + sin (N * X)')
plt.xlabel('x label')
plt.ylabel('y label')
plt.title("goldenSectionSearch")
plt.legend()
plt.show()

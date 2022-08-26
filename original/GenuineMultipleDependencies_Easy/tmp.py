from functools import reduce

f = [ [1] * 301 for _ in [0] * 301 ]
for n in range(1, 301):
    for x in range(2, 301):
        f[n][x] = reduce(lambda a, b: (a + b) % 998244353, (f[n-1][i] for i in range(1, x+1)))

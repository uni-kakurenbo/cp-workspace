from sys import setrecursionlimit, stderr;
# setrecursionlimit(10**6)
def debug(*args, **opts):
    print(*args, **opts, file=stderr);

import numpy as np;

n, m = map(int, input().split());
A = np.array([*map(int, input().split())][::-1]);
C = np.array([*map(int, input().split())][::-1]);
print(*map(int, [*np.polydiv(C, A)[0]][::-1]));

from sys import setrecursionlimit, stderr, argv;
# setrecursionlimit(10**5)
def debug(*args, **opts):
    if argv[-1] == "LOCAL_JUDGE": print(*args, **opts, file=stderr);

from cmath import cos, sin, pi

a, b, d = map(int, input().split());
z = complex(a, b);
z *= complex(cos(d/180*pi), sin(d/180*pi));
print(z.real, z.imag);

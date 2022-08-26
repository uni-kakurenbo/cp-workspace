# @uni_kakurenbo
# https://github.com/uni-kakurenbo/competitive-programming-workspace
#
# CC0 1.0  http://creativecommons.org/publicdomain/zero/1.0/deed.ja

# #language PyPy3 #

from itertools import product
from sys import setrecursionlimit, stderr, argv;
# setrecursionlimit(10**5)
def debug(*args, **opts):
    if argv[-1] == "LOCAL_JUDGE": print(*args, **opts, file=stderr);

n, m = map(int, input().split())

d = [0] * n
for _ in [0] * m:
    a, b = map(int, input().split())
    d[a-1] += 1; d[b-1] += 1

ans = 0
for i in range(n):
    ans += d[i] * (d[i] - 1)
print(ans//2)

# @uni_kakurenbo
# https://github.com/uni-kakurenbo/competitive-programming-workspace
#
# CC0 1.0  http://creativecommons.org/publicdomain/zero/1.0/deed.ja

# #language PyPy3 #

from sys import setrecursionlimit, stderr, argv
setrecursionlimit(10**5)
def debug(*args, **opts):
    if argv[-1] == "LOCAL_JUDGE": print(*args, **opts, file=stderr)

t = int(input())

from functools import lru_cache, reduce
@lru_cache(maxsize=None)
def solve(n, x):
    if n == 0: return 1
    return reduce(lambda a, b: (a + b) % 998244353, (solve(n-1, i) for i in range(1, x+1)))

for _ in [0] * t:
    n, x = map(int, input().split())
    print(solve(n,x))

# @uni_kakurenbo
# https://github.com/uni-kakurenbo/competitive-programming-workspace
#
# CC0 1.0  http://creativecommons.org/publicdomain/zero/1.0/deed.ja

# #language PyPy3 #

from ast import Lambda
from sys import setrecursionlimit, stderr, argv
setrecursionlimit(10**5)
def debug(*args, **opts):
    if argv[-1] == "LOCAL_JUDGE": print(*args, **opts, file=stderr)

t = int(input())

from functools import reduce
dp = [ [1] * 301 for _ in [0] * 301 ]
for n in range(1, 301):
    for x in range(2, 301):
        dp[n][x] = reduce(lambda a, b: (a + b) % 998244353, (dp[n-1][i] for i in range(1, x+1)))

for _ in [0] * t:
    n, x = map(int, input().split())
    print(dp[n][x])

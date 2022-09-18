# @uni_kakurenbo
# https://github.com/uni-kakurenbo/competitive-programming-workspace
#
# CC0 1.0  http://creativecommons.org/publicdomain/zero/1.0/deed.ja

# #language PyPy3 #

from sys import setrecursionlimit, stderr, argv
setrecursionlimit(10**5)
def debug(*args, **opts):
    if argv[-1] == "LOCAL_JUDGE": print(*args, **opts, file=stderr)

dp = [[1] * 3001 for _ in [0] * 3001]

for n in range(1, 3001):
    for x in range(2, 3001):
        dp[n][x] = (dp[n-1][x] + dp[n][x-1]) % 998244353

t = int(input())

for _ in [0] * t:
    n, x = map(int, input().split())
    print(dp[n][x])

# @uni_kakurenbo
# https://github.com/uni-kakurenbo/competitive-programming-workspace
#
# CC0 1.0  http://creativecommons.org/publicdomain/zero/1.0/deed.ja

# #language PyPy3 #

from sys import setrecursionlimit, stderr, argv;
# setrecursionlimit(10**5)
def debug(*args, **opts):
    if argv[-1] == "LOCAL_JUDGE": print(*args, **opts, file=stderr);

n, x, y, k = map(int, input().split())
A = [*map(int, input().split())]
A.sort()

ans = 0
for a in A:
    k -= a*x/y;
    if k < 0: break;
    ans += 1

print(ans)

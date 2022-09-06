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

H, W, N = map(int, input().split())
S = input()

if len(S) != N: print("NG: S length"); exit(1)
if not 1 <= H <= 2400: print("NG: H"); exit(1)
if not 1 <= W <= 2400: print("NG: W"); exit(1)
if not 1 <= N <= 2*10**6: print("NG: N"); exit(1)

grid = [[1] * (W+2) for _ in range(H+2)]
dis, djs = [ 0, 1, 0, -1 ], [ 1, 0, -1, 0 ]
i, j, d = 1, 1, 0;
for s in S:
    grid[i][j] = 0
    if s == 'F': i += dis[d]; j += djs[d]
    elif s == 'L': d -= 1
    elif s == 'R': d += 1
    elif s == 'T': d += 2
    else: print("NG: S characters"); exit(1)
    d %= 4
    if i < 1 or i > H or j < 1 or j > W: print("NG: S content"); exit(1)
grid[i][j] = 0

print("OK")

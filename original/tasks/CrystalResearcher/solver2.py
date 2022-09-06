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

H += 2; W += 2
grid = [[1] * W for _ in [0] * H]

dis, djs = [ 0, 1, 0, -1 ], [ 1, 0, -1, 0 ]

i, j, d = 1, 1, 0;
for s in S:
    grid[i][j] = 0
    if s == 'F': i += dis[d]; j += djs[d]
    if s == 'L': d -= 1
    if s == 'R': d += 1
    if s == 'T': d += 2
    d %= 4
grid[i][j] = 0

# debug(grid)

ans = 0
for i, j in product(range(1, H-1),range(1, W-1)):
    cnt = 0
    if not grid[i][j]: continue
    for di, dj in zip(dis,djs):
        cnt += grid[i+di][j+dj]
    ans += cnt >= 4

print(ans)

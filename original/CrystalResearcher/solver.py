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
grid = [1] * H * W

dis, djs = [ 0, 1, 0, -1 ], [ 1, 0, -1, 0 ]

i, j, d = 1, 1, 0;
for s in S:
    grid[i*W+j] = 0
    if s == 'F': i += dis[d]; j += djs[d]
    if s == 'L': d = (d-1)%4
    if s == 'R': d = (d+1)%4
    if s == 'T': d = (d+2)%4
grid[i*W+j] = 0

# debug(grid)

ans = 0
for i, j in product(range(1, H-1),range(1, W-1)):
    if not grid[i*W+j]: continue
    ans += all(grid[(i+di)*W+j+dj] for di, dj in zip(dis,djs))

print(ans)

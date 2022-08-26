# @uni_kakurenbo
# https://github.com/uni-kakurenbo/competitive-programming-workspace
#
# CC0 1.0  http://creativecommons.org/publicdomain/zero/1.0/deed.ja

# #language PyPy3 #

from sys import setrecursionlimit, stderr, argv;
# setrecursionlimit(10**5)
def debug(*args, **opts):
    if argv[-1] == "LOCAL_JUDGE": print(*args, **opts, file=stderr);

from collections import deque, defaultdict

n = int(input())
A = [*map(int, input().split())]

cnt = defaultdict(int)
ans, j = 0,0
for i in range(n):
    while j < n and cnt[A[j]] < 1: cnt[A[j]]+=1; j+=1
    ans = max(ans, j-i)
    cnt[A[i]] -= 1;
print(ans)

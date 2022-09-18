# @uni_kakurenbo
# https://github.com/uni-kakurenbo/competitive-programming-workspace
#
# CC0 1.0  http://creativecommons.org/publicdomain/zero/1.0/deed.ja

# #language PyPy3 #

from sys import setrecursionlimit, stderr, argv;
# setrecursionlimit(10**5)
def debug(*args, **opts):
    if argv[-1] == "LOCAL_JUDGE": print(*args, **opts, file=stderr);

n = int(input())
A = [*map(int, input().split())]

st = set()
ans, l, r = 0, 0, 0
while True:
    while r < n and A[r] not in st: st.add(A[r]); r+=1
    ans = max(ans, r-l);
    if r >= n: break
    while l < r and A[r] in st: st.discard(A[l]); l+=1
print(ans)

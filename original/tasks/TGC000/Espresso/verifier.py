# @uni_kakurenbo
# https://github.com/uni-kakurenbo/competitive-programming-workspace
#
# CC0 1.0  http://creativecommons.org/publicdomain/zero/1.0/deed.ja

# #language PyPy3 #

from sys import setrecursionlimit, stderr, argv;
# setrecursionlimit(10**5)
def debug(*args, **opts):
    if argv[-1] == "LOCAL_JUDGE": print(*args, **opts, file=stderr);

N, X, Y, K = map(int, input().split())
A = [*map(int, input().split())]

debug(N, X, Y, K)
debug(len(A))
debug(A)

if len(A) != N: print("NG: A size != N"); exit(1)
if not 1 <= N <= 4*10**6: print("NG: N"); exit(1)
if not 0 <= X <= Y <= 1000: print("NG: X, Y"); exit(1)
if Y == 0: print("NG: Y == 0"); exit(1)
if not 0 <= K <= 10**15: print("NG: K"); exit(1)
for a in A:
    if not 1 <= a <= 10**9: print("NG: A_i"); exit(1)
print("OK");

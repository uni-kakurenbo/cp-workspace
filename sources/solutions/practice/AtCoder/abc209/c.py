from sys import setrecursionlimit, stderr, argv;
# setrecursionlimit(10**5)
def debug(*args, **opts):
    if argv[-1] == "LOCAL_JUDGE": print(*args, **opts, file=stderr);

n = int(input())
A = [*map(int, input().split())]
A.sort()

mod = 10**9 + 7
ans, under = 1, 0

for a in A:
    ans *= max(a-under, 0)
    ans %= mod
    under += 1

print(ans)

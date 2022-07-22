from sys import setrecursionlimit, stderr, argv;
# setrecursionlimit(10**5)
def debug(*args, **opts):
    if argv[-1] == "LOCAL_JUDGE": print(*args, **opts, file=stderr);

def dsum(x):
    res = 0
    while x > 0:
        res += x%10
        x //= 10
    return res

n, a, b = map(int, input().split())
ans = 0
for i in range(1, n+1):
    ans += i if a <= dsum(i) <= b else 0;
print(ans)

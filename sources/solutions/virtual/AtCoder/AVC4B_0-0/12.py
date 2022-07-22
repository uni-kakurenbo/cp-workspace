from sys import setrecursionlimit, stderr, argv;
# setrecursionlimit(10**5)
def debug(*args, **opts):
    if argv[-1] == "LOCAL_JUDGE": print(*args, **opts, file=stderr);

n = int(input());
A = [*map(int, input().split())];

ans = 0;
for a in A:
    ans = a + ans*2;
print(ans)

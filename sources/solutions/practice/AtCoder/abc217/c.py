from sys import setrecursionlimit, stderr, argv;
# setrecursionlimit(10**5)
def debug(*args, **opts):
    if argv[-1] == "LOCAL_JUDGE": print(*args, **opts, file=stderr);

n = int(input());
P = [*map(int, input().split())];
Q = [0] * n;
i = 1;
for p in P:
    Q[p-1] = i;
    i += 1;

print(*Q);

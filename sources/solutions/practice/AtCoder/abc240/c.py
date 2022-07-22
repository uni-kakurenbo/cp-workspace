from sys import setrecursionlimit, stderr, argv;
# setrecursionlimit(10**6)
def debug(*args, **opts):
    if argv[-1] == "LOCAL_JUDGE": print(*args, **opts, file=stderr);

n, x = map(int, input().split());
P = [[0] * (x+1) for _ in range(n+1)];
P[0][0] = 1;
for i in range(n):
    debug(P);
    a, b = map(int, input().split());
    for j in range(x):
        if not P[i][j]: continue;
        if j+a <= x: P[i+1][j+a] = 1;
        if j+b <= x: P[i+1][j+b] = 1;
debug(P);
print("Yes" if P[n][x] else "No");

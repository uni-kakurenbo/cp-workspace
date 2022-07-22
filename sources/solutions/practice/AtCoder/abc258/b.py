from sys import setrecursionlimit, stderr, argv;
# setrecursionlimit(10**6)
def debug(*args, **opts):
    if argv[-1] == "LOCAL_JUDGE": print(*args, **opts, file=stderr);

n = int(input());
A = [[*map(int, list(input()))] for _ in range(n)];
debug(A);
def calc(i, j, di, dj):
    res = str(A[i][j]);
    for _ in range(n-1):
        i += di; j += dj;
        res += str(A[i%n][j%n]);
    return int(res);

dis = [ -1, -1, -1, 0, 0, 1, 1, 1 ];
djs = [ -1, 0, 1, -1, 1, -1, 0, 1 ];

ans = 0;
for i in range(n):
    for j in range(n):
        for di, dj in zip(dis, djs):
            ans = max(ans, calc(i, j, di, dj));
print(ans);

from sys import setrecursionlimit, stderr, argv;
# setrecursionlimit(10**6)
def debug(*args, **opts):
    if argv[-1] == "LOCAL_JUDGE": print(*args, **opts, file=stderr);

n = int(input());

ans = 0;
for a in range(1, n+1):
    if a ** 3 > n: break;
    for b in range(a, n+1):
        if a*b*b > n: break;
        ans += n//(a*b) - b + 1;
print(ans);

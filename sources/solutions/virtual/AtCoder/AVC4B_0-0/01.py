from sys import setrecursionlimit, stderr, argv;
# setrecursionlimit(10**5)
def debug(*args, **opts):
    if argv[-1] == "LOCAL_JUDGE": print(*args, **opts, file=stderr);

n, r = map(int, input().split());
if n >= 10: print(r);
else: print(r + 100*(10-n))

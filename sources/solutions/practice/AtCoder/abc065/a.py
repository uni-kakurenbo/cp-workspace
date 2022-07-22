from sys import setrecursionlimit, stderr, argv;
# setrecursionlimit(10**5)
def debug(*args, **opts):
    if argv[-1] == "LOCAL_JUDGE": print(*args, **opts, file=stderr);

x, a, b = map(int, input().split());

if b <= a: print("delicious")
elif b-a <= x: print("safe")
else: print("dangerous")

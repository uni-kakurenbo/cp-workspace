from sys import setrecursionlimit, stderr;
# setrecursionlimit(10**6)
def debug(*args, **opts):
    print(*args, **opts, file=stderr);

n, x = map(int, input().split());
S = ""
for c in [*"ABCDEFGHIJKLMNOPQRSTUVWXYZ"]:
    S += c*n;
debug(S);
print(S[x-1]);

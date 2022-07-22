from sys import setrecursionlimit, stderr, argv;
# setrecursionlimit(10**5)
def debug(*args, **opts):
    if argv[-1] == "LOCAL_JUDGE": print(*args, **opts, file=stderr);

S = input()
T = input()

ans = 0;
for i in range(3):
    ans += S[i] == T[i];

print(ans);

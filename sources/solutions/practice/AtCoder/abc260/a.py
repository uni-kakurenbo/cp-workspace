from sys import setrecursionlimit, stderr, argv;
# setrecursionlimit(10**5)
def debug(*args, **opts):
    if argv[-1] == "LOCAL_JUDGE": print(*args, **opts, file=stderr);

s = input();
if s[0] == s[1] and s[1] == s[2]: print(-1);
elif s[0] == s[1] and s[0] != s[2]: print(s[2]);
elif s[0] == s[2] and s[0] != s[1]: print(s[1]);
elif s[1] == s[2] and s[0] != s[1]: print(s[0]);
else: print(s[0]);

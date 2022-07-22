from sys import setrecursionlimit, stderr, argv;
# setrecursionlimit(10**5)
def debug(*args, **opts):
    if argv[-1] == "LOCAL_JUDGE": print(*args, **opts, file=stderr);

c = input();
L = "QWERTYASDFGHZXCVB";
r = "OPKL";
print("Left" if c in L else "Right");

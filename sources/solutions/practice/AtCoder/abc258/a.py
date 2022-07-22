from sys import setrecursionlimit, stderr, argv;
# setrecursionlimit(10**6)
def debug(*args, **opts):
    if argv[-1] == "LOCAL_JUDGE": print(*args, **opts, file=stderr);

k = int(input());
k += 21 * 60;
h = str(k//60);
m = str(k%60);
if len(h)==1: h = "0"+h;
if len(m)==1: m = "0"+m;
print(h+":"+m);

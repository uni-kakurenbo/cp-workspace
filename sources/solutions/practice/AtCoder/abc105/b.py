from sys import setrecursionlimit, stderr;
setrecursionlimit(10**6)
def debug(*args):
    print(*args, file=stderr)

n = int(input());
if n >= 18 or n%4 == 0 or n%7 == 0 or n in [ 11, 15 ]: print("Yes");
else: print("No")

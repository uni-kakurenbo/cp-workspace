from sys import setrecursionlimit, stderr;
setrecursionlimit(10**6)
def debug(*args):
  print(*args, file=stderr)

n = int(input())
L = [*map(int, input().split())]
m = max(L)
s = sum(L)
print("Yes" if 2*m < s else "No")

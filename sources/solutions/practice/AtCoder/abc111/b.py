from sys import setrecursionlimit, stderr;
setrecursionlimit(10**6)
def debug(*args):
  print(*args, file=stderr)

N = int(input())
ans = 111
while ans < N:
  ans += 111
print(ans)

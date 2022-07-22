from sys import setrecursionlimit, stderr;
setrecursionlimit(10**6)
def debug(*args):
  print(*args, file=stderr)

n = int(input())
ans = 0
for _ in range(n):
  x, u = input().split()
  x = float(x)
  if u == "JPY": ans += x
  else: ans += 380000.0 * x
print(ans)

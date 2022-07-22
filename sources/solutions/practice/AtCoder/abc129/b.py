from sys import stderr;
def debug(*args):
  print(*args, file=stderr);

n = int(input())
W = [*map(int, input().split())]
l, r = 0, sum(W)
ans = 10 ** 10
for w in W:
  l += w; r -= w
  ans = min(ans, abs(l-r))
print(ans)

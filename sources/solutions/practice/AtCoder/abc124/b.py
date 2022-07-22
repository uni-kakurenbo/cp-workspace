from sys import stderr;
def debug(*args):
  print(*args, file=stderr);

n = int(input())
H = [*map(int, input().split())]
ans, m = 0, 0;
for h in H:
  ans += m<=h
  m = max(m, h)
print(ans)

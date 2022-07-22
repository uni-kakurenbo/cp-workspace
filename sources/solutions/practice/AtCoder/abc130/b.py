from sys import stderr;
def debug(*args):
  print(*args, file=stderr);

n, x = map(int, input().split());
L = [*map(int, input().split())];
ans, now = 1, 0;
for l in L:
  now+=l;
  ans += now <= x
print(ans)

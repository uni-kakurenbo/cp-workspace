from math import sqrt;

n, d = map(int, input().split());
ans = 0;
for _ in range(n):
  x, y = map(int, input().split());
  ans += sqrt(x*x + y*y) <= d;

print(ans);

n, m, t = map(int, input().split());
x=n; now=0;
for i in range(m):
  a, b = map(int, input().split());
  x -= a-now;
  if x <= 0: print("No"); exit(0);
  x += b-a; x = min(x, n);
  now = b;
x -= t-now;
if x <= 0: print("No"); exit(0);
print("Yes");

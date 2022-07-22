n, x = map(int, input().split());
x *= 100;
now = 0;
for i in range(n):
    v, p = map(int, input().split());
    now += v * p
    if now > x: exit(print(i+1));
print(-1);

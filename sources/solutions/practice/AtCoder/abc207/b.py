a, b, c, d = map(int, input().split());
x = a;
y = 0;
ans = 0;
if b >= c*d: exit(print(-1));
while x > y*d:
    x += b;
    y += c;
    ans += 1;
print(ans);

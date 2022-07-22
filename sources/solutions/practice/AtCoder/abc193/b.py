n = int(input());
ans = 10 ** 10;
for _ in range(n):
    a, p, x = map(int, input().split());
    if x-a > 0: ans = min(ans, p);
print(ans if ans < 10 ** 10 else -1);

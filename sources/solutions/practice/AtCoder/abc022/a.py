n, s, t = map(int, input().split());
now = 0; ans = 0;
for i in range(n):
    now += int(input());
    ans += s <= now <= t
print(ans);

n = int(input());
A = list(map(int, input().split()));
ans = 0;
for a in A:
    ans += max(a - 10, 0);
print(ans);

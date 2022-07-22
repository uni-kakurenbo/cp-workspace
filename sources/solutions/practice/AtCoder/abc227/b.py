n = int(input());
s = list(map(int, input().split()));
ans = n
for v in s:
    flag = False;
    for a in range(1, 1000):
        for b in range(1, 1000):
            flag |= v == 4*a*b + 3*a + 3*b;
    ans -= flag;
print(ans);

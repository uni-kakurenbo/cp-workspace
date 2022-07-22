n, x = map(int, input().split());
a = list(map(int, input().split()));
already = [False] * n;
ans = 0;
while not already[x-1]:
    already[x-1] = True;
    x = a[x-1];
    ans += 1;
print(ans)

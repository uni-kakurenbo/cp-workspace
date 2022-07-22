n = int(input());
cnt = [0] * n;
for _ in range(n-1):
    a, b = map(int, input().split());
    cnt[a-1]+=1; cnt[b-1]+=1;
for v in cnt:
    if v == n-1: exit(print("Yes"));
print("No");

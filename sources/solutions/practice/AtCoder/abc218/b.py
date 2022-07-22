a = "abcdefghijklmnopqrstuvwxyz";
P = list(map(int, input().split()));
ans = [];
for p in P:
    ans.append(a[p-1]);
print("".join(ans));
    

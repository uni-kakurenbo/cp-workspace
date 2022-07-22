n = int(input());
l = list(map(int, input().split()));
ans = 0;
for i in range(0, n-2):
  for j in range(i+1, n-1):
    for k in range(j+1, n):
      ls = sorted(list(set([l[i], l[j], l[k]])));
      if len(ls) < 3: continue;
      if ls[2] >= ls[0]+ls[1]: continue;
      ans+=1;
print(ans);

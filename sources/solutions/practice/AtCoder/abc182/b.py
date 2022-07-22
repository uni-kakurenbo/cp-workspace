n = int(input());
a = list(map(int, input().split()));
ans, max_GCD_ness = 0, -1;
for k in range(2, max(a)+1):
  GCD_ness=0;
  for i in range(n):
    GCD_ness += a[i]%k==0;
  if GCD_ness > max_GCD_ness:
    max_GCD_ness=GCD_ness;
    ans=k;
print(ans);

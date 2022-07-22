s = input();
t = input();
ans=0;
for i, c in enumerate(s):
  ans += c != t[i];
print(ans);

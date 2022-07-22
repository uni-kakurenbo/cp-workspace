s = input();
t = input();
ans = 10 ** 10;
for i in range(0, len(s)-len(t)+1):
  cnt = 0;
  for j in range(0, len(t)):
    cnt += s[i+j] != t[j];
  ans = min(ans, cnt);
print(ans);

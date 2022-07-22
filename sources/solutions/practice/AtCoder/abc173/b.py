n = int(input());
cnt = { "AC":0, "WA":0, "TLE":0, "RE":0 };
for _ in range(n):
  s = input();
  cnt[s]+=1;
for k, v in cnt.items():
  print(k, "x", v);

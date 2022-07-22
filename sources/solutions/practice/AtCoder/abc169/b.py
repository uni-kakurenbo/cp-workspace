n = int(input());
A = list(map(int, input().split()));
if A.count(0) > 0: print(0); exit(0);
p = 1;
for a in A:
  p *= a;
  if p > 10**18: print(-1); exit(0);
print(p);

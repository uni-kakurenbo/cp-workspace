n, x = map(int, input().split());
S = input();
p = x;
for s in S:
  if s == "o": p += 1;
  else: p -= 1; p=max(p, 0);
print(p);

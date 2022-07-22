n = int(input());
cnt = 0;
for i in range(n):
  a, b = map(int, input().split());
  cnt = cnt + 1 if a == b else 0;
  if cnt >= 3: print("Yes"); exit();
print("No");

n, k = map(int, input().split());
no = [1] * n;
for _ in range(k):
  d = int(input());
  A = list(map(int, input().split()));
  for a in A:
    no[a-1] = 0;
print(sum(no));

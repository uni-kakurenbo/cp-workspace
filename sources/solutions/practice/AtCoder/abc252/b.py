n, k = map(int, input().split());
A = list(map(int, input().split()));
B = list(map(int, input().split()));
A_max = max(A);
ex = set();
for i, a in enumerate(A):
  if a == A_max: ex.add(i+1);
for e in ex:
  if B.count(e) > 0: exit(print("Yes"));
print("No");

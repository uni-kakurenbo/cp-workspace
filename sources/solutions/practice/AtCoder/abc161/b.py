n, m = map(int, input().split());
A = list(map(int, input().split()));
s = sum(A);
cnt = 0;
for a in A:
  cnt += 1 if a*4*m >= s else 0;
print("Yes" if cnt >= m else "No")

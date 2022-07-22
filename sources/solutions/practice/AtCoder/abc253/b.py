from sys import stderr;
def debug(*args):
  print(*args, file=stderr);
h, w = map(int, input().split());
A = [];
for _ in range(h):
  A.append(input())

P, Q = -1, -1
for i in range(h):
  for j in range(w):
    if A[i][j] == "o":
      if P == -1:
        P = (i, j)
      else:
        Q = (i, j)
print(abs(P[0]-Q[0])+abs(P[1]-Q[1]))

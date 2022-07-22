from sys import setrecursionlimit, stderr;
setrecursionlimit(10**6)
def debug(*args):
  print(*args, file=stderr)

n = int(input())
A = [ 1 ]

for _ in range(n):
  B = [ 1 ] * (_+1)
  for i in range(1, _):
    B[i] = A[i-1] + A[i]
  A = B
  print(*A)

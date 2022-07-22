from sys import stderr;
def debug(*args):
  print(*args, file=stderr);

n, l = map(int, input().split())
A = [l+i for i in range(n)]
B = [*map(abs, A)];
m = min(B);
debug(m)
print(sum(A)-A[B.index(m)]);

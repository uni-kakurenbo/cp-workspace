from sys import stderr;
def debug(*args):
  print(*args, file=stderr);

h, n = map(int, input().split());
A = list(map(int, input().split()));
print("Yes" if h <= sum(A) else "No");

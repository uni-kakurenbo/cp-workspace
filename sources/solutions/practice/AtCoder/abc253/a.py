from sys import stderr;
def debug(*args):
  print(*args, file=stderr);
a, b, c = map(int, input().split());
print("Yes" if b == sorted([a, b, c])[1] else "No");

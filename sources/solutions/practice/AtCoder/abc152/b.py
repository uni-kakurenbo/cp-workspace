from sys import stderr;
def debug(*args):
  print(*args, file=stderr);

a, b = map(int, input().split());
print(min(str(a)*b, str(b)*a));

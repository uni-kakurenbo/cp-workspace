from sys import stderr;
def debug(*args):
  print(*args, file=stderr);

n = input()
print(n[-2:])

from sys import stderr;
def debug(*args):
  print(*args, file=stderr);

k, x = map(int, input().split())
print(*[a for a in range(x-k+1, x+k)])

from sys import stderr;
def debug(*args):
  print(*args, file=stderr);
n, d = map(int, input().split())
D = d*2+1;
print((n+D-1)//D)

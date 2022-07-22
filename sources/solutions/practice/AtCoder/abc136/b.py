from sys import stderr;
def debug(*args):
  print(*args, file=stderr);

n = int(input())
print(sum(len(str(i))%2 for i in range(1, n+1)))

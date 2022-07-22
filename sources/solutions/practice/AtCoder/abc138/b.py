from sys import stderr;
def debug(*args):
  print(*args, file=stderr);

n = int(input())
A = list(map(int, input().split()))
print(1/sum(1/a for a in A))

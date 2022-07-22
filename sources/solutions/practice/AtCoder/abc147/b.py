from sys import stderr;
def debug(*args):
  print(*args, file=stderr);

S = input();
n = len(S);
print(sum(a < b for a, b in zip(S, S[::-1])));

from sys import stderr;
def debug(*args):
  print(*args, file=stderr);

from itertools import combinations;
n = int(input());
D = list(map(int, input().split()));
print(sum(p*q for p, q in combinations(D, 2)));

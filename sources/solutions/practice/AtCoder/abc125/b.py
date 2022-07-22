from sys import stderr;
def debug(*args):
  print(*args, file=stderr);

n = int(input())
V = [*map(int, input().split())]
C = [*map(int, input().split())]
D = [v-c if v>c else 0 for v, c in zip(V, C)]
print(sum(D));

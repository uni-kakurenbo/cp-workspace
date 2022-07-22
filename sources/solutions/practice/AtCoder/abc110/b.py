from sys import setrecursionlimit, stderr;
setrecursionlimit(10**6)
def debug(*args):
  print(*args, file=stderr)

n, m, x, y = map(int, input().split())
X = [*map(int, input().split())]
Y = [*map(int, input().split())]
X.append(x); Y.append(y)
print("No War" if max(X) < min(Y)  else "War")

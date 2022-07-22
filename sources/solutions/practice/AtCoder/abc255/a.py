from sys import setrecursionlimit, stderr;
setrecursionlimit(10**6)
def debug(*args):
    print(*args, file=stderr)

r, c = map(int, input().split());
A = [0,0];
A[0] = [*map(int, input().split())];
A[1] = [*map(int, input().split())];
print(A[r-1][c-1]);

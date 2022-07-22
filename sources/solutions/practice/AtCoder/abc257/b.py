from sys import setrecursionlimit, stderr;
# setrecursionlimit(10**6)
def debug(*args, **opts):
    print(*args, **opts, file=stderr);

n, k, q = map(int, input().split());
A = [*map(int, input().split())];
L = [*map(int, input().split())];
P = [0] * (n+10);
for a in A:
    P[a-1] = 1;
for l in L:
    debug(*A);
    if A[l-1] >= n: continue;
    if P[A[l-1]] == 1: continue;
    P[A[l-1]-1] = 0;
    P[A[l-1]] = 1;
    A[l-1] += 1;
print(*A);

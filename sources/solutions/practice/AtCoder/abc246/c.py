from audioop import reverse
from sys import setrecursionlimit, stderr;
# setrecursionlimit(10**6)
def debug(*args, **opts):
    print(*args, **opts, file=stderr);

n, k, x = map(int, input().split());
A = [*map(int, input().split())];
A.sort(reverse=True);
for i in range(n):
    if k<=0: break;
    take = min(A[i]//x, k);
    A[i] -= take*x;
    k-=take;
A.sort(reverse=True);
for i in range(n):
    if k<=0: break;
    A[i]=0;
    k-=1;
print(sum(A));

from sys import setrecursionlimit, stderr;
def debug(*args):
    print(*args, file=stderr)

n, k = map(int, input().split());
A = [*map(int, input().split())];
X, Y = [0]*n, [0]*n
for i in range(n):
    X[i], Y[i] = map(int, input().split());

ans = 0;
for i, (x1, y1)in enumerate(zip(X, Y)):
    if i+1 in A: continue;
    prov_ans = 10**100;
    for j, (x2, y2) in enumerate(zip(X, Y)):
        if not j+1 in A: continue;
        prov_ans = min(prov_ans, ((x1-x2)**2 + (y1-y2)**2)**0.5)
    ans = max(ans, prov_ans);
print(ans);

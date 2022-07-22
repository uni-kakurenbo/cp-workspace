from sys import setrecursionlimit, stderr
# setrecursionlimit(10**6)
def debug(*args, **opts):
    print(*args, **opts, file=stderr);

n = int(input());
S = [list(input()) for _ in range(n)];

def judge(i, j, di, dj):
    cnt = 0;
    for _ in range(6):
        if not (0 <= i < n and 0 <= j < n): return 0;
        cnt += S[i][j] == '#';
        i += di; j += dj;
    return cnt >= 4;

dis, djs = [ 1, 0, 1, 1 ], [ 0, 1, 1, -1 ];
for i in range(n):
    for j in range(n):
        for di, dj in zip(dis, djs):
            if judge(i, j, di, dj): print("Yes"); exit();
print("No");

from sys import stderr;
def debug(*args):
  print(*args, file=stderr);

n = int(input())
P = list(map(int, input().split()))
T = sorted(P);
for i in range(n-1):
  for j in range(i, n):
    Q = [*P];
    Q[i], Q[j] = Q[j], Q[i]
    debug(Q)
    if Q == T: print("YES"); exit()
print("NO")

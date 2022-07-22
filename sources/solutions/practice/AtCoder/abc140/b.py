from sys import stderr;
def debug(*args):
  print(*args, file=stderr);

n = int(input());
A = list(map(int, input().split()));
A = [a-1 for a in A];
B = list(map(int, input().split()));
C = list(map(int, input().split()));
A.append(-1);

print(sum(B[A[i]] + (C[A[i+1]-1] if A[i+1] == A[i]+1 else 0) for i in range(n)));

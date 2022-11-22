N = int(input())
N += 1
F = [0] * (N+1)
F[0] = F[1] = 1
for i in range(2, N+1):
    F[i] = F[i-1] + F[i-2]
    F[i] %= 998244353
print(F[N])

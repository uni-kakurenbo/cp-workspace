n = int(input());
A = []; B = [];

for _ in range(n):
    a, b = map(int, input().split());
    A.append(a); B.append(b);

ans = 10 ** 10;
for i in range(n):
    for j in range(n):
        a, b = A[i], B[j];
        ans = min(ans, a+b if i==j else max(a, b));

print(ans)

from math import sqrt;
n = int(input());
X = list(map(int, input().split()));
M, E, C = 0, 0, 0;
for x in X:
  M += abs(x);
  E += x**2;
  C = max(C, abs(x));
E = sqrt(E);
print(M);
print(E);
print(C);

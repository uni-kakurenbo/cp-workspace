def solve(P, Q):
  q = int(Q**0.5);
  if q*q==Q: return P+q, 0
  D = P*P - Q
  if Q%4 > 0 or  D < 0: return [-1]
  d = int(D**0.5)
  if d*d!=D: return [-1]
  return (P+d)//2, (P-d)//2

for _ in range(int(input())):
  print(*solve(*map(int, input().split())))
